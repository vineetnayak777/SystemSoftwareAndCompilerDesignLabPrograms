%option noyywrap
%{
	#include<stdio.h>
	#include<string.h>
	int comment =0, state=1;
%}

%%
"//".*[\n] {comment++;}
"/*" {state = 0;}
"*/" {if(state==0)
	{
		comment++;
		state=1;
	}
     }
.|\n {if(state ==1)
	{
		fprintf(yyout, "%s",yytext);
	}
     }
%%
int main()
{
	char infile[100], outfile[100];
	printf("Enter input file name\n");
	scanf("%s",infile);
	printf("Enter output file name\n");
	scanf("%s",outfile);
	yyin = fopen(infile,"r");
	yyout = fopen(outfile, "w");
	yylex();
	printf("Total comment lines are: %d\n", comment);
	return 0;
}