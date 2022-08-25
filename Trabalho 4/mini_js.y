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

vector<string> resolve_enderecos( vector<string> );

string gera_label( string );

void print( vector<string> );

void atributos( Atributos );
void attr( Atributos );

Atributos gera_operador(  Atributos s1, 
                          Atributos s3, 
                          Atributos s2 );

string trim( char* );
vector<string> split( string );

map<string, int> vars;
vector<string> aux;

vector<string> funcs;
int linha = 1;
int qtd_pars = 0;

%}

%token ID DOUBLE NEG MAIG MEIG IG STRING IF ELSE FOR WHILE LET VAR CONST FUNCTION RETURN ASM

%right MAIG
%right '='
%right '^'

%nonassoc '<' '>'

%left MEIG IG 
%left '+' '-'
%left '*' '/' '%'
%left '['
%left '.'

// Start indica o simbolo inicial da partida
// %start S

%%

RAIZ : S  { print( $1.c + "." ); }
     ;

S : CMDs { print(resolve_enderecos( $1.c + "." + funcs) ); }
  ;

CMDs : CMD CMDs { $$.c = $1.c + $2.c; }
     | CMD      { $$.c = $1.c; }
     ;

CMD : E ';'                           { $$.c = $1.c + "^"; }
    | B ';'                           { $$.c = $1.c; }
    | E ASM ';'                       { $$.c = $1.c + $2.c + "^"; }
    | LET D ';'                       { $$.c = $2.c; }
    | VAR D ';'                       { $$.c = $2.c; }
    | CONST D ';'                     { $$.c = $2.c; }    
    | RETURN E ';'                    { $$.c = aux + $2.c + "'&retorno'" + "@" + "~"; }
    | IF '(' E ')' B ELSE B           { string r = gera_label( "IF_ELSE" );
                                        string s = gera_label( "IF_CONTINUE" );
                                        $$.c = $3.c + "!" + r + "?" + $5.c + s + "#" + (":" + r) + $7.c + (":" + s); }
    | IF '(' E ')' B                  { string r = gera_label( "ENDIF" );
                                        $$.c = $3.c + "!" + r + "?" + $5.c + (":" + r); }
    | WHILE '(' E ')' B               { string r = gera_label( "WHILE" ); 
                                        string s = gera_label( "ENDWHILE" ); 
                                        $$.c = aux + (":" + r) + $3.c + "!" + s + "?" + $5.c + r + "#" + (":" + s); }
    | FOR '(' CMD E ';' E ')' B       { string r = gera_label( "TESTFOR" ); 
                                        string s = gera_label( "ENDFOR" );
                                        $$.c = $3.c + (":" + r) + $4.c + "!" + s + "?" + $8.c + $6.c + "^" + r + "#" + (":" + s); }
    | FUNCTION ID '(' ')' B           { string r = gera_label( $2.c[0] );
                                        vector<string> retorna = aux + "undefined" + "@" + "'&retorno'" + "@" + "~";
                                        funcs = funcs + (":" + r) + $5.c + retorna;
                                        vector<string> end_decl = $2.c + "&" + $2.c + "{}" + "=" + "'&funcao'" + r + "[=]" + "^"; 
                                        $$.c = end_decl; }
    | FUNCTION ID '(' D_LINHA ')' B   { string r = gera_label( $2.c[0] ); 
                                        vector<string> pars;
                                        for( int i = 0; i < $4.c.size(); i++ ){
                                          pars = pars + $4.c[i] + "&" + $4.c[i] + "arguments" + "@" + to_string(i) + "[@]" + "=" + "^";
                                        }
                                        vector<string> retorna = aux + "undefined" + "@" + "'&retorno'" + "@" + "~";
                                        funcs = funcs + (":" + r) + pars + $6.c + retorna;
                                        vector<string> end_decl = $2.c + "&" + $2.c + "{}" + "=" + "'&funcao'" + r + "[=]" + "^";
                                        $$.c = end_decl; }
    | FUNCTION ID '(' DS ')' B        { string r = gera_label( $2.c[0] ); 
                                        vector<string> pars;
                                        for( int i = 0; i < $4.c.size(); i++ ){
                                          pars = pars + $4.c[i];
                                        }
                                        pars = pars + "=" + "^";
                                        vector<string> retorna = aux + pars + $1.c + "@" + "$" + "=" + "^";
                                        funcs = funcs + (":" + r) + pars + $6.c + retorna;
                                        vector<string> end_decl = $2.c + "&" + $2.c + "{}" + "=" + "'&funcao'" + r + "[=]" + "^";
                                        $$.c = end_decl; }
    ;

DS : DOUBLE ',' DS          { $$.c = $1.c + $3.c; }
   | DOUBLE                 { $$.c = $1.c; }
   ;

E : E '<' E       { $$.c = $1.c + $3.c + "<"; }
  | E '>' E       { $$.c = $1.c + $3.c + ">"; }
  | E MAIG E      { $$.c = $1.c + $3.c + ">="; }
  | E MEIG E      { $$.c = $1.c + $3.c + "<="; }
  | E IG E        { $$.c = $1.c + $3.c + "=="; }
  | E '^' E       { $$.c = $1.c + $3.c + "^"; }
  | E '+' E       { $$.c = $1.c + $3.c + "+"; }
  | E '-' E       { $$.c = $1.c + $3.c + "-"; }
  | E '*' E       { $$.c = $1.c + $3.c + "*"; }
  | E '/' E       { $$.c = $1.c + $3.c + "/"; }
  | E '%' E       { $$.c = $1.c + $3.c + "%"; }
  | LV_ '=' E     { $$.c = $1.c + $3.c + "[=]"; }
  | LVALUE '=' E  { $$.c = $1.c + $3.c + "="; }
  | LV_           { $$.c = $1.c + "[@]"; }
  | LVALUE        { $$.c = $1.c + "@"; }
  | F
  ;

D : D_ ',' D      { $$.c = $1.c + $3.c; }
  | D_
  ;

D_LINHA : ID ',' D_LINHA    { $$.c = $1.c + $3.c; }
        | ID                { $$.c = $1.c; }
        ;

D_ : LVALUE '=' E           { $$.c = $1.c + "&" + $1.c + $3.c + "=" + "^"; 
                              vars[$1.c[0]] = linha;
                            }
   | LVALUE                 { $$.c = $1.c + "&";
                              vars[$1.c[0]] = linha;
                            }
   ;

B : '{' CMDs '}'  { $$.c = $2.c; }
  | CMD           { $$.c = $1.c; }
  | B_            { $$.c = aux; }
  ;

B_ : '{' '}'
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
CF : ID '(' P_ ')'  { $$.c = $3.c + to_string(qtd_pars) + $1.c + "@" + "$"; qtd_pars = 0; }

   | ID '(' ')'     { $$.c = aux + "0" + $1.c + "@" + "$"; }
   | LV_ '(' P_ ')' { $$.c = $3.c + to_string(qtd_pars) + $1.c + "[@]" + "$"; qtd_pars = 0; }
   | LV_ '(' ')'    { $$.c = aux + "0" + $1.c + "[@]" + "$"; }
   ;

P_ : E ',' P_       { $$.c = $1.c + $3.c; qtd_pars++; }
  | E               { $$.c = $1.c; qtd_pars++; }
  ;  

F : DOUBLE        { $$.c = $1.c; }
  | STRING        { $$.c = $1.c; }
  | B_            { $$.c = aux + "{}"; }
  | '['']'        { $$.c = aux + "[]"; }
  | '(' E ')'     { $$ = $2; }
  | NEG           { $$.c = aux + "0" + $1.c + "-"; }
  | CF            { $$ = $1; }
  ;

%%

#include "lex.yy.c"

vector<string> concatena( vector<string> a, vector<string> b ) {
  for( int i = 0; i < b.size(); i++ )
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

vector<string> resolve_enderecos( vector<string> entrada ){
    map<string, int> label;
    vector<string> saida;

    for( int i = 0; i < entrada.size(); i++ ){
        if( entrada[i][0] == ':' )
            label[entrada[i].substr(1)] = saida.size();
        else 
            saida.push_back( entrada[i] );
    }

    for( int i = 0; i < saida.size(); i++ ){
        if( label.count( saida[i] ) > 0 )
            saida[i] = to_string( label[saida[i]] );
    }

    return saida;
}

void atributos( Atributos a ) {
    string var = a.c[0];

    if( vars.count( var ) == 1){
        cout << "Erro: a variável '" << var << "' já foi declarada na linha " << vars[var] << "." << endl;
        exit(1);
    }
}

void attr( Atributos a ){
    string var = a.c[0];

    if( vars.count( var ) == 0){
        cout << "Erro: a variável '" << var << "' não foi declarada." << endl;
        exit(1);
    }
}

Atributos gera_operador( Atributos s1, 
                         Atributos s3,
                         Atributos s2 ) {
    Atributos ss;

    ss.c = s1.c + s3.c + s2.c;

    return ss;
}

void print( vector<string> v ){
    for( int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
}

string trim( char *c ) {
    string temp = c;
    return temp.erase( temp.size() - 1 , temp.size() );
}

vector<string> split( string v ) {
  vector<std::string> tokens;

  size_t s = 0, e = 0;

  while( (e = v.find(" ", s)) != string::npos) {
    tokens.push_back( v.substr(s, e-s) );
    s = e + 1;
  }

  tokens.push_back( v.substr(s) );
  return tokens;
}

void yyerror( const char* st ){
    puts( st );
    printf( "Proximo a: %s\n", yytext );

    exit(1);
}

int main( int argc, char* argv[] ){
    yyparse();

    return 0;
}