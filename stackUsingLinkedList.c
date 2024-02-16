#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} node;

node* head=NULL;
node* createNode(int val)
{
	node* new=(node *)malloc(sizeof(node));
	new->next=NULL;
	new->data=val;
	return new;
}
void push(){
	int val;
	printf("\n Enter the value to add to list  : ");
	scanf("%d",&val);
	node* new=createNode(val);
	
	new->next=head;
	head=new;

}

void pop()
{
	if(head==NULL)
		printf("\n List empty ! ");
	else 
	{
		int val=head->data;
		head=head->next;
		printf("\n Value deleted : %d ", val);
	}
}

void peek()
{
	if(head==NULL)
		printf("\n List empty ! ");
	else{
		printf("\n Top element : %d",head->data);
	}
}

void display()
{
	if(head==NULL)
		printf("\n List empty ! ");
	else
	{
		node* new=head;
		printf("\n Elements in queue are : ");
		while(new!=NULL)
		{
			printf(" %d ",new->data);
			new=new->next;
		}
	}
}

int main()
{
	int ch;
	while(1)
	{
	printf("\n \n Enter your choice :\n 1.Insert \n 2.Delete \n3.Display\n 4.peek\n 5.exit \n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		push();
		break;
	case 2:
		pop();
		break;
	case 3:
		display();
		break;
	case 4:
		peek();
		break;
	case 5:
		exit(0);
	default:printf("\n Enter a proper input!");
	}
    }
    return 0;
}
