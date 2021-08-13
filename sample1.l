%option noyywrap
%{

	#include<stdio.h>

%}

%%
[0-9]+ printf("valid digit");
. printf("invalid input");
%%

int main()
{
	printf("Enter input\n");
	yylex();
	return 0;
}