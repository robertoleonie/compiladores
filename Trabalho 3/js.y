%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Atributos {
    vector<string> c;
};

#define YYSTYPE Atributos

int yylex();
int yyparse();
void yyerror(const char *);

%}

%token NUM ID LET

%%

S : CMDs { cout << $1.c << "." << endl; }
  ;

CMDs : CMDs CMD { $$.c = $1.c + $2.c; }
     ;

CMD : A
     | LET ID '=' E { $$.c = $2.c + " & " + $2.c + " " + $4.c + " = ^"; }
     | LET ID       { $$.c = $2.c + " &"; }
     ;

A : ID '=' E { $$.c = $1.c + " " + $3.c + " = ^"; }
  ;

E : E '+' T { $$.c = $1.c + " " + $3.c + " +"; }
  | E '-' T { $$.c = $1.c + " " + $3.c + " -"; }
  | T
  ;

T : T '*' F { $$.c = $1.c + " " + $3.c + " *"; }
  | T '/' F { $$.c = $1.c + " " + $3.c + " /"; }
  | F
  ;

F : ID          { $$.c = $1.c + " @"; }
  | NUM         { $$.c = $1.c; }
  | '(' E ')'   { $$ = $2; }
  ;

%%

#include "lex.yy.c"

vector<string> concatena( vector<string> a, vector<string> b ){
    a.insert( a.end(), b.begin(), b.end() );
    return a;
}

vector<string> operator+( vector<string> a, vector<string> b){
    return concatena( a, b );
}

vector<string> operator+( vector<string> a, string b ){
    a.push_back( b );
    return a;
}

string gera_label( string prefixo ){
    static int n = 0;
    return prefixo + "_" + to_string( ++n ) + ":";
}

vector<string> resolve_enderecos( vector<string> entrada ){
    map<string,int> label;
    vector<string> saida;
    for( int i = 0; i < entrada.size(); i++ )
        if( entrada[i][0] == ':' )
            label[entrada[i].substr(1)] = saida.size();
        else
            saida.push_back( entrada[i] );

    for( int i = 0; i < saida.size(); i++ )
        if( label.count( saida[i] ) > 0 )
            saida[i] = to_string(label[saida[i]]);

    return saida;
}

void yyerror( const char* st){
    puts( st );
    printf( "Proximo a: %s\n", yytext );
    exit( 1 );
}

int main( int argc, char* argv[] ){
    yyparse();

    return 0;
}