/* Coloque aqui definições regulares */

WS	        [ \t\n]

D           [0-9]
L           [A-Za-z_$]

INT         {D}+
FLOAT       {D}+("."{D}+)?([Ee][+\-]?{D}+)?

FOR         (F|f)(O|o)(R|r)
IF          (I|i)(F|f)

COMENTARIO  "/*"([^*]|"*"[^/])*"*/"
COMENT2     "//"([^\n])*

STRING      ["]([^"\\\n]|\\(.|\n)|(\"\"))*["]
STRB        [']([^'\\\n]|\\(.|\n)|(''))*[']
STRING2     [`]([^`])*[`]

ID          {L}({L}|{D})*


%%
    /* Padrões e ações. Nesta seção, comentários devem ter um tab antes */

{WS}	    { /* ignora espaços, tabs e '\n' */ } 

{FOR}       { return _FOR; }
{IF}        { return _IF; }

{INT}       { return _INT; }
{FLOAT}     { return _FLOAT; }

">="        { return _MAIG; }
"<="        { return _MEIG; }
"=="        { return _IG; }
"!="        { return _DIF; }

{ID}        { return _ID; }

{STRING}    { return _STRING; }
{STRB}      { return _STRING; }
{STRING2}   { return _STRING2; }

{COMENTARIO} { return _COMENTARIO; }
{COMENT2}   { return _COMENTARIO; }

.       { return *yytext; 
          /* Essa deve ser a última regra. Dessa forma qualquer caractere isolado será retornado pelo seu código ascii. */ }

%%

/* Não coloque nada aqui - a função main é automaticamente incluída na hora de avaliar e dar a nota. */
