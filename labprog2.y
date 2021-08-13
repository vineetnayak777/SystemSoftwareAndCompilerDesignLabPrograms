%{
	#include<stdio.h>
	#include<stdlib.h>
%}

%token A B

%% 
S: X B
X: A X
 |;
%%
int main()
{
	printf("Enter a String\n");
	yyparse();
	printf("Valid String\n");
}

yyerror()
{
	printf("Invalid String");
	exit(0);
}