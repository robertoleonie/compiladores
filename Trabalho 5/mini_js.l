DIGITO  [0-9]
LETRA   [A-Za-z_$]

WS      [ \t]

DOUBLE  {DIGITO}+("."{DIGITO}+)?([Ee]("+"|"-")?{DIGITO}+)?
ID      {LETRA}({LETRA}|{DIGITO})*

STRING  ([\"]([^\"\n]*(\"\")*(\\\")*)*[\"])|([\']([^\'\n]*(\'\')*(\\\')*)*[\'])

ARGS    {WS}*{ID}{WS}*(","{WS}*{ID}{WS}*)*")"{WS}"=>"

%%

{WS}        { }

"\n"        { linha++; }

{DOUBLE}    {   yylval.c = aux + yytext; 
                return DOUBLE; }

"("/{ARGS}  {   return APS; }

"true"      {   yylval.c = aux + "true"; 
                return TRUE; }

"false"     {   yylval.c = aux + "false"; 
                return FALSE; }

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

"while"     {   yylval.c = aux + "while"; 
                return WHILE; }

"for"       {   yylval.c = aux + "for"; 
                return FOR; }

"function"  {   yylval.c = aux + "function"; 
                return FUNCTION; }

"function(" {   yylval.c = aux + "function_anonima";
                return FUNC_ANON; }

"return"    {   yylval.c = aux + "return";
                return RETURN; }

"asm{".*"}" {   yylval.c = split( trim( yytext + 4 ) ); 
                return ASM; }

"=>"        {   yylval.c = aux + "=>";
                return ARROW; }

"=="        {   yylval.c = aux + "==";
                return IG; }

"<="        {   yylval.c = aux + "<=";
                return MEIG; }

">="        {   yylval.c = aux + ">=";
                return MAIG; }

{STRING}    {   yylval.c = aux + yytext;
                return STRING; }

{ID}        {   yylval.c = aux + yytext;
                return ID; }

.           {   yylval.c = aux + yytext;
                return *yytext; }

%%