#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char a[20], ac[20], act[20], stk[20];
int c = 0, i = 0, j = 0, k = 0, z = 0;

void check();

int main(int argc, char *argv[])
{
	
	printf("Grammar is E-> E+E| E*E| (E)| id\n");
	printf("Enter a\n");
	scanf("%s",a);
	c = strlen(a);
	printf("Stack\tInput\tAction\t\n");
	strcpy(act, "SHIFT->");
	strcpy(ac, "REDUCE TO E");

	for(k = 0, i = 0; j < c; k++,i++,j++)
	{
	
		if(a[j] == 'i' && a[j+1] == 'd')
		{
			stk[i] = a[j];
			stk[i+1] = a[j+1];
			stk[i+2] = '\0';
			a[j] = ' ';
			a[j+1] = ' ';
			printf("\n$ %s\t %s$\t %s id",stk,a,act);
			check();
		}
		else
		{
			stk[i] = a[j];
			stk[i+1] = '\0';
			a[j] = ' ';
			if(stk[i]=='+')
				printf("\n$ %s\t %s$\t %s +",stk,a,act);
			if(stk[i]=='*')
				printf("\n$ %s\t %s$\t %s *",stk,a,act);
			check();

		}

	}

	return 0;
}

void check()
{
	for(z=0;z<c;z++)
	{
		if (stk[z] == 'i' && stk[z+1] == 'd')
		{
			stk[z] = 'E';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("\n$ %s\t %s$\t %s",stk,a,ac);
			j++;
		}
	}
	for(z=0;z<c;z++)
	{
		if (stk[z] == 'E' && stk[z+1] == '+' && stk[z+2] == 'E')
		{
			stk[z] = 'E';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("\n$ %s\t %s$\t %s",stk,a,ac);
			i=i-2;
		}
	}
	for(z=0;z<c;z++)
	{
		if (stk[z] == 'E' && stk[z+1] == '*' && stk[z+2] == 'E')
		{
			stk[z] = 'E';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("\n$ %s\t %s$\t %s",stk,a,ac);
			i=i-2;
		}
	}
	for(z=0;z<c;z++)
	{
		if (stk[z] == '(' && stk[z+1] == 'E' && stk[z+2] == ')')
		{
			stk[z] = 'E';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("\n$ %s\t %s$\t %s",stk,a,ac);
		}
	}
}