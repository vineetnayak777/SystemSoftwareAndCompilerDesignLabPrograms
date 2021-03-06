%{
	#include<stdio.h>
	#include<stdlib.h>
	int id = 0, op = 0, digit = 0, keyword = 0;
%}

%token OP KEYWORD ID DIGIT

%% 
S: DIGIT S {digit++;}
   | ID S {id++;}
   | KEYWORD S {keyword++;}
   | OP S {op++;}
   | DIGIT {digit++;}
   | ID {id++;}
   | KEYWORD {keyword++;}
   | OP {op++;}

%%

extern FILE *yyin;
void main()
{
	yyin=fopen("outputlabprog6a.txt", "r");
	do{
		yyparse();
	}while(!feof(yyin));
	fclose(yyin);
	printf("Total number of Digits: %d\n",digit);
	printf("Total number of Operators: %d\n",op);
	printf("Total number of Keywords : %d\n",keyword);
	printf("Total number of Identifiers: %d\n",id);
}

int yyerror()
{
	printf("Invalid\n");
}