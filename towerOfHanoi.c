#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int step=0;

void toh(int n, char source, char spare, char dest)
{
	if(n==1)
		printf("step %d : move %d from %c to %c\n",++step,n,source,dest);
	else
	{
     toh(n-1,source,dest,spare);
	 toh(1,source,spare,dest);
	 toh(n-1,spare,source,dest);
	}
}
void main()
{
printf("Enter the number of rings: ");
int n;
scanf("%d",&n);
char a='A',b='B',c='C';
toh(n,a,b,c);
}
