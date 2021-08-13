#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void FIFO(char[], char[], int, int);
void LRU(char[], char[], int, int);

int main(int argc, char *argv[])
{
	int frames, leng, i, choice, yesorno;
	char s[20], F[10];
	printf("Enter no of empty frames required\n");
	scanf("%d",&frames);
	printf("Enter lenght of the String\n");
	scanf("%d",&leng);
	printf("Enter the string\n");
	scanf("%s",s);
	for (i = 0;i<frames ;i++ )
	{
		F[i] = -1;
	}

	do{
			printf("*******Menu*******\n");
			printf("1. FIFO\n2.LRU\n3.Exit\n");
			printf("Enter your choice\n");
			scanf("%d",&choice);
		switch(choice)
		{
			case 1: for(i = 0; i< frames; i++)
					{
						F[i]=-1;
					}
					FIFO(s, F, leng, frames);
					break;
			case 2: for(i = 0; i< frames; i++)
					{
						F[i]=-1;
					}
					LRU(s, F, leng, frames);;
					break;
			case 3: exit(0);
			default: printf("Enter valid choice\n");
		}
		printf("Do you want to continue\nIf yes press 1, else 0");
		scanf("%d",&yesorno);
	}while(yesorno);
	return 0;
	
}

void FIFO(char s[], char F[], int l, int f)
{
	int i, k, j = 0, flag = 0, count = 0;
	printf("PAGE\tFRAMES\tFAULTS?\n");
	for(i = 0;i < l; i++)
	{
		for(k = 0; k < f; k++)
		{
			
			if(F[k] == s[i])
			{
				flag  = 1;
			}

			if(flag == 0)
			{
				printf("%c",s[i]);
				F[j] = s[i];
				j++;
				for(k = 0; k< f; k++)
				{
					printf("\t%c",F[k]);
				}
				printf("\t Page fault %d\n", count);
				count++;
			}

			else
			{
				flag = 0;
				printf("\n%c",s[i]);
				for(k = 0; k < f; k++)
				{
					printf("\t%c", F[k]);
				}
				printf("No Page Fault\n");
			}

			if(j == f)
				j=0;
		}

	}

}

void LRU(char s[],char F[],int l,int f)
{
    int i,j=0,k,m,flag=0,cnt=0,top=0;
    printf("\n\tPAGE\t	FRAMES\t\t\t FAULTS");
    for(i=0;i<l;i++)
    {
        for(k=0;k<f;k++)
        {
            if(F[k]==s[i])
            {
                flag=1;
                break;
            }
        }
        printf("\n\t%c\t",s[i]);
        if(j!=f && flag!=1)
        {
            F[top]=s[i];
            j++;
            if(j!=f)
                top++;
        }

        else
        {
            if(flag==1)
            {
                for(m=k;m<top;m++)
                    F[m]=F[m+1];
                F[top]=s[i];
            }
			if(flag!=1)
            {
                for(k=0;k<top;k++)
                    F[k]=F[k+1];
                F[top]=s[i];
            }  
        }

        for(k=0;k<f;k++)
            printf("\t%c",F[k]);

        if(flag==0)
        {
            printf("\tPage fault%d",cnt);
            cnt++;
        }
        else
            printf("\tNo page fault");
        flag=0;
  }
}
