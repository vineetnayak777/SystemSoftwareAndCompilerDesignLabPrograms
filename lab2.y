%{
	#include<stdio.h>
	#include<stdlib.h>
	int result = 0;
%}

%token NUM
%left '+''-'
%left '*''/'

%% 
S:E       {result=$1;}
E:E '+' E {$$=$1+$3;}
 |E '-' E {$$=$1-$3;}
 |E '*' E {$$=$1*$3;}
 |E '/' E {if($3 != 0)
		{$$=$1/$3;}
	   else
	   {
		printf("Divide by zero error");
		exit(0);
	   }
	  }
 |'('E')' {$$=$2;}
 |NUM	  {$$=$1;}
%%
int main()
{
	printf("Enter an expression\n");
	yyparse();
	printf("Result = %d\n",result);
}

yyerror()
{
	printf("Invalid Expression\n");
}