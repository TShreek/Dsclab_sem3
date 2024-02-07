#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

int stack[MAX], l;
void initializeStack()
{
printf("\nEnter the number of elements ");
int n;
scanf("%d",&l);
printf("\n Enter the elements of the array");
for(int i=0;i<l;i++)
        {
                printf("\n Element %d : ",i+1);
                scanf("%d",&stack[i]);
        }
}
void display()
{
printf("\n Elements of the Stack are :\n");
for(int i=0;i<l;i++)
        {
                printf("\n Element %d : %d",i+1,stack[i]);
        }
}
void insert()
{
int n;
printf("\n Enter the position to be inserted in :");
scanf("%d",&n);
int a;
for(int i=l;i>=n;i--)
{
        stack[i]=stack[i-1];
}
printf("\n Enter the number to be inserted");
scanf("%d",&a);
stack[n-1]=a;
l++;
}

void deleteE() {
    int n, j;
    printf("\nEnter the number to be deleted: ");
    scanf("%d", &n);
    for(int i = 0; i < l; i++) {
        if(stack[i] == n) {
            for(j = i; j < l - 1; j++) {
                stack[j] = stack[j + 1];
            }
            l--;
            break; // Exit loop after deleting the first occurrence of the element
        }
    }
    if (j == l)
        printf("Element not found\n");
}

int main()
{

        while(1)
        {
                printf("\n Enter a choice: \n1.initialize Stack\n2.Display Elements\n");
                printf("3.Add element\n4.Delete element\n5.Exit\n");
                int ch;
                scanf("%d",&ch);
                switch(ch)
                {
                case 1:initializeStack();
                        break;
                case 2: display();
                        break;
                case 3: insert();
                        break;
                case 4: deleteE();
                        break;
                case 5: exit(0);
                default: printf(" \n Enter a proper choice :");

                }
        }
return 0;
}
