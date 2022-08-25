all: js entrada.txt
		./js < entrada.txt

lex.yy.c: js.l
		lex js.l

y.tab.c: js.y
		yacc js.y

js: lex.yy.c y.tab.c
		g++ -o js y.tab.c -ll