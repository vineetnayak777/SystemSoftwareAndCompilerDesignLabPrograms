%option noyywrap
%{
	#include<stdio.h>
	#include"y.tab.h"
	extern int yylval;
%}

%%

[\+\-\*\/\=] {	
		printf("%s is an operator\n",yytext);
		return OP;
	     }
int|float|char|bool|void|while|if|for|do|else|return|printf|scanf|exit|main {
										printf("%s is keyword\n",yytext);
										return KEYWORD;
									}
[0-9]* {
		yylval = atoi(yytext);
		printf("%d is a digit\n",yylval);
		return DIGIT;
	}

[A-Za-z_][a-zA-Z0-9]* { 
			printf("%s is an Identifier\n", yytext);
			return ID;
			}
.|\n ;
%%
