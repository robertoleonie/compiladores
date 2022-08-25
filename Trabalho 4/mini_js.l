DIGITO  [0-9]
LETRA   [A-Za-z_$]

WS      [ \t]
DOUBLE  {DIGITO}+("."{DIGITO}+)?([Ee]("+"|"-")?{DIGITO}+)?

NEG     ("-"){DOUBLE}

ID      {LETRA}({LETRA}|{DIGITO})*
STRING  ([\"]([^\"\n]*(\"\")*(\\\")*)*[\"])|([\']([^\'\n]*(\'\')*(\\\')*)*[\'])

%%

{WS}        { }

"\n"        { linha++; }

{NEG}       {   yylval.c = aux + (yytext + 1);
                return NEG; }

{DOUBLE}    {   yylval.c = aux + yytext; 
                return DOUBLE; }

"let"       {   yylval.c = aux + "let"; 
                return LET; }

"var"       {   yylval.c = aux + "var"; 
                return VAR; }

"const"     {   yylval.c = aux + "const"; 
                return CONST; }

"if"        {   yylval.c = aux + "if"; 
                return IF; }

"else"      {   yylval.c = aux + "else"; 
                return ELSE; }

"for"       {   yylval.c = aux + "for"; 
                return FOR; }

"while"     {   yylval.c = aux + "while"; 
                return WHILE; }

"function"  {   yylval.c = aux + "function"; 
                return FUNCTION; }

"return"    {   yylval.c = aux + "return"; 
                return RETURN; }

"asm{".*"}" {   yylval.c = split( trim( yytext + 4 ) );
                return ASM; }

">="        {   yylval.c = aux + ">="; 
                return MAIG; }

"<="        {   yylval.c = aux + "<=";
                return MEIG; }

"=="        {   yylval.c = aux + "==";
                return IG; }

{STRING}    {   yylval.c = aux + yytext;
                return STRING; }

{ID}        {   yylval.c = aux + yytext;
                return ID; }

.           {   yylval.c = aux + yytext;
                return *yytext; }

%%