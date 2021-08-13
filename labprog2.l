%option noyywrap
%{
	#include<stdio.h>
	#include "y.tab.h"	
%}

%%
a {return A;}
b {return B;}
[ \t] ;
. {return yytext[0];}
\n {return 0;}
%%