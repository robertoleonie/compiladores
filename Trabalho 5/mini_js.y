%{
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Atributos {
    vector<string> c;
};

#define YYSTYPE Atributos

int yylex();
int yyparse();
void yyerror( const char* );

vector<string> concatena( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, string b );

string gera_label( string prefixo );

vector<string> resolve_enderecos( vector<string> );

void print( vector<string> );

void atributos( Atributos );
void attr( Atributos );

string trim( char* );
vector<string> split( string );

vector<string> aux;
map<string, int> vars;

vector<string> funcs;

int linha = 1;
int qtd_pars = 0;

vector<vector<string>> elements;
vector<vector<string>> pars;

%}

%token ID DOUBLE STRING IG MAIG MEIG TRUE FALSE LET VAR CONST IF ELSE FOR WHILE FUNCTION FUNC_ANON RETURN ASM APS ARROW

%right '='
%right ARROW

%nonassoc '<' '>' IG MAIG MEIG

%left '+' '-'
%left '*' '/' '%'

// Start indica o simbolo inicial da gramatica
// %start S

%%

RAIZ : S    { print( $1.c + "." ); }
     ;

S : CMDs    { print( resolve_enderecos( $1.c + "." + funcs ) ); }
  ;

CMDs : CMD CMDs     { $$.c = $1.c + $2.c; }
     | CMD          { $$.c = $1.c; }
     ;

CMD : E ';'                         { $$.c = $1.c + "^"; }
    | ID ASM ';'                    { $$.c = $1.c + "@" + $2.c + "^"; }
    | LET D ';'                     { $$.c = $2.c; }
    | VAR D ';'                     { $$.c = $2.c; }
    | CONST D ';'                   { $$.c = $2.c; }
    | RETURN E ';'                  { $$.c = aux + $2.c + "'&retorno'" + "@" + "~"; }
    | IF '(' E ')' B ELSE B         { string r = gera_label( "IF_ELSE" ); 
                                      string s = gera_label( "IF_CONTINUE" ); 
                                      $$.c = $3.c + "!" + r + "?" + $5.c + s + "#" + (":" + r) + $7.c + (":" + s); }
    | IF '(' E ')' B                { string r = gera_label( "ENDIF" ); 
                                      $$.c = $3.c + "!" + r + "?" + $5.c + (":" + r); }
    | WHILE '(' E ')' B             { string r = gera_label( "WHILE" ); 
                                      string s = gera_label( "ENDWHILE" ); 
                                      $$.c = aux + (":" + r) + $3.c + "!" + s + "?" + $5.c + r + "#" + (":" + s); }
    | FOR '(' CMD E ';' E ')' B     { string r = gera_label( "TESTFOR" );
                                      string s = gera_label( "ENDFOR" ); 
                                      $$.c = $3.c + (":" + r) + $4.c + "!" + s + "?" + $8.c + $6.c + "^" + r + "#" + (":" + s); }
    | FUNCTION ID '(' ')' B         { string r = gera_label( $2.c[0] ); 
                                      vector<string> retorna = aux + "undefined" + "@" + "'&retorno'" + "@" + "~"; 
                                      funcs = funcs + (":" + r) + $5.c + retorna;
                                      vector<string> end_decl = $2.c + "&" + $2.c + "{}" + "=" + "'&funcao'" + r + "[=]" + "^";
                                      $$.c = end_decl; 
                                      qtd_pars = 0; }
    | FUNCTION ID '(' D_LINHA ')' B { string r = gera_label( $2.c[0] );
                                      vector<string> retorna = aux + "undefined" + "@" + "'&retorno'" + "@" + "~";
                                      funcs = funcs + (":" + r) + $4.c + $6.c + retorna;
                                      $$.c = $2.c + "&" + $2.c + "{}" + "=" + "'&funcao'" + r + "[=]" + "^"; }
    ;

E : E '<' E       { $$.c = $1.c + $3.c + "<"; }
  | E '>' E       { $$.c = $1.c + $3.c + ">"; }
  | E MAIG E      { $$.c = $1.c + $3.c + ">="; }
  | E MEIG E      { $$.c = $1.c + $3.c + "<="; }
  | E IG E        { $$.c = $1.c + $3.c + "=="; }
  | E '*' E       { $$.c = $1.c + $3.c + "*"; }
  | E '+' E       { $$.c = $1.c + $3.c + "+"; }
  | E '-' E       { $$.c = $1.c + $3.c + "-"; }
  | E '/' E       { $$.c = $1.c + $3.c + "/"; }
  | E '%' E       { $$.c = $1.c + $3.c + "%"; }
  | LV_ '=' E     { $$.c = $1.c + $3.c + "[=]"; }
  | LVALUE '=' E  { $$.c = $1.c + $3.c + "="; }
  | LV_           { $$.c = $1.c + "[@]"; }
  | LVALUE        { $$.c = $1.c + "@"; }
  | O             { $$ = $1; }
  | F
  ;

D : D_ ',' D      { $$.c = $1.c + $3.c; }
  | D_
  ;

D_ : LVALUE '=' E   { $$.c = $1.c + "&" + $1.c + $3.c + "=" + "^";
                      vars[$1.c[0]] = linha;
                    }
    | LVALUE        { $$.c = $1.c + "&";
                      vars[$1.c[0]] = linha;
                    }
    ;

B : '{' CMDs '}'  { $$.c = $2.c; }
  | CMD           { $$.c = $1.c; }
  | B_            { $$.c = aux; }
  ;

B_ : '{' '}'
   ;

D_LINHA : D_LINHA_  {   vector<string> decl_par;
                        int tam = pars.size() / 2;

                        for( int i = 0; i < tam; i++ ) {
                          vector<string> defaultValue = pars.back();
                          pars.pop_back();

                          vector<string> id = pars.back();
                          pars.pop_back();

                          if ( defaultValue.size() == 0 ) {
                            decl_par = decl_par + id + "&" + id + "arguments" + "@" + to_string(i) + "[@]" + "=" + "^";
                          } else {
                            string r = gera_label( "IF_ELSE" );
                            string s = gera_label( "IF_CONTINUE" );

                            vector<string> def = aux + "arguments" + "@" + to_string(i) + "[@]" + "undefined" + "@" + "==" + "!" + r + "?" + id + "&" + id + defaultValue + "=" + "^";
                            vector<string> notDef = aux + s + "#" + (":" + r) + id + "&" + id + "arguments" + "@" + to_string(i) + "[@]" + "=" + "^" + (":" + s);
                            decl_par = decl_par + def + notDef;
                          }
                        }
                        pars.clear();
                        $$.c = decl_par; }
        ;

D_LINHA_ : ID '=' E ',' D_LINHA_      { pars.push_back($1.c);
                                        pars.push_back($3.c);
                                        $$.c = $1.c + $3.c + $5.c; }
        | ID ',' D_LINHA_             { pars.push_back($1.c);
                                        pars.push_back(aux);
                                        $$.c = $1.c + $3.c; }
        | ID '=' E                    { pars.push_back($1.c);
                                        pars.push_back($3.c);
                                        $$.c = $1.c + $3.c; }
        | ID                          { pars.push_back($1.c);
                                        pars.push_back(aux);
                                        $$.c = $1.c; }
        ;

LV_ : LVALUE P    { $$.c = $1.c + "@" + $2.c; }
    ;

LVALUE : ID       { $$.c = $1.c; }
       ;

P : '[' E ']' P   { $$.c = $2.c + "[@]" + $4.c; }
  | '.' ID P      { $$.c = $2.c + "[@]" + $3.c; }
  | '[' E ']'     { $$.c = $2.c; }
  | '.' ID        { $$.c = $2.c; }
  ;

O : '{' ATRIB '}' { $$.c = aux + "{}" + $2.c; }
  | B_            { $$.c = aux + "{}"; }
  ;

ATRIB : ID ':' E ',' ATRIB    { $$.c = $1.c + $3.c + "[<=]" + $5.c; }
      | ID ':' E              { $$.c = $1.c + $3.c + "[<=]"; }
      ;

F : DOUBLE        { $$.c = $1.c; }
  | STRING        { $$.c = $1.c; }
  | TRUE          { $$.c = $1.c; }
  | FALSE         { $$.c = $1.c; }
  | '(' E ')'     { $$ = $2; }
  | CF            { $$ = $1; }
  | ARRAY         { $$ = $1; }
  | FA            { $$ = $1; }
  | FARROW        { $$ = $1; }
  ;

CF :  ID '(' P_ ')'   { $$.c = $3.c + to_string(qtd_pars) + $1.c + "@" + "$"; qtd_pars = 0; }
   | ID '(' ')'       { $$.c = aux + "0" + $1.c + "@" + "$"; }
   | LV_ '(' P_ ')'   { $$.c = $3.c + to_string(qtd_pars) + $1.c + "[@]" + "$"; qtd_pars = 0; }
   | LV_ '(' ')'      { $$.c = aux + "0" + $1.c + "[@]" + "$"; }
   ;

ARRAY : '[' ELS ']'   { $$.c = aux + "[]";
                        int tam = elements.size();
                        for ( int i = 0; i < tam; i++ ) {
                          $$.c = $$.c + to_string(i) + elements.back() + "[<=]";
                          elements.pop_back();
                        }
                      }
      | '['']'        { $$.c = aux + "[]"; }
      ;

FA : FUNC_ANON ')' B              { string r = gera_label( "FUNCANON" ); 
                                    vector<string> retorna = aux + "undefined" + "@" + "'&retorno'" + "@" + "~";
                                    funcs = funcs + (":" + r) + $3.c + retorna;
                                    $$.c = aux + "{}" + "'&funcao'" + r + "[<=]"; }
    | FUNC_ANON D_LINHA ')' B     { string r = gera_label( "FUNCANON" );
                                    vector<string> retorna = aux + "undefined" + "@" + "'&retorno'" + "@" + "~";
                                    funcs = funcs + (":" + r) + $2.c + $4.c + retorna;
                                    $$.c = aux + "{}" + "'&funcao'" + r + "[<=]"; }
    ;

FARROW : H ARROW E          { string r = gera_label( "FUNCANON" ); 
                              vector<string> retorna = aux + $3.c + "'&retorno'" + "@" + "~";
                              funcs = funcs + (":" + r) + $1.c + retorna;
                              $$.c = aux + "{}" + "'&funcao'" + r + "[<=]"; }
        ;

P_ : E ',' P_     { $$.c = $1.c + $3.c; qtd_pars++; }
   | E            { $$.c = $1.c; qtd_pars++; }
   ;

ELS : E ',' ELS   { elements.push_back($1.c); }
    | E           { elements.push_back($1.c); }
    ;

H : ID                { $$.c = $1.c + "&" + $1.c + "arguments" + "@" + "0" + "[@]" + "=" + "^"; }
  | '(' ')'           { $$.c = aux; }
  | APS D_LINHA ')'   { $$.c = $2.c; }
  ;

%%

#include "lex.yy.c"

vector<string> concatena( vector<string> a, vector<string> b ) {
  for ( int i = 0; i < b.size(); i++ ) 
    a.push_back( b[i] );
  return a;
}

vector<string> operator+( vector<string> a, vector<string> b ) {
  return concatena( a , b );
}

vector<string> operator+( vector<string> a, string b ) {
  a.push_back( b );
  return a;
}

string gera_label( string prefixo ) {
  static int n = 0;
  return prefixo + "_" + to_string( ++n ) + ":";
}

vector<string> resolve_enderecos( vector<string> entrada ) {
  map<string,int> label;
  vector<string> saida;

  for ( int i = 0; i < entrada.size(); i++ ) {
    if ( entrada[i][0] == ':' )
      label[entrada[i].substr(1)] = saida.size();
    else
      saida.push_back( entrada[i] );
  }

  for ( int i = 0; i < saida.size(); i++ ) {
    if( label.count( saida[i] ) > 0)
      saida[i] = to_string( label[saida[i]] );
  }

  return saida;
}

void atributos( Atributos a ) {
  string var = a.c[0];

  if( vars.count( var ) == 1 ) {
    cout << "Erro: a variável '" << var << "' já foi declarada na linha " << vars[var] << "." << endl;
    exit(1);
  }
}

void attr( Atributos a ) {
  string var = a.c[0];

  if( vars.count( var ) == 0 ) {
    cout << "Erro: a variável '" << var << "' não foi declarada." << endl;
    exit(1);
  }
}

Atributos gera_operador(  Atributos s1,
                          Atributos s3,
                          Atributos s2 ) {
    Atributos ss;

    ss.c = s1.c + s3.c + s2.c;

    return ss;
}

void print( vector<string> v ) {
  for ( int i = 0; i < v.size(); i++ ) {
    cout << v[i] << " ";
  }
}

string trim( char* c ) {
  string temp = c;
  return temp.erase( temp.size() - 1, temp.size() );
}

vector<string> split( string v ) {
  vector<std::string> tokens;
  size_t s = 0, e = 0;

  while( ( e = v.find(" ", s)) != string::npos ) {
    tokens.push_back( v.substr( s, e - s ) );
    s = e + 1;
  }

  tokens.push_back( v.substr( s ) );
  return tokens;
}

void yyerror( const char* st ) {
  puts( st );
  printf( "Proximo a: %s\n", yytext );
  exit( 1 );
}

int main( int argc, char* argv[] ) {
  yyparse();
  return 0;
}