#include<stdio.h>
#include<stdlib.h>

struct cirQueue{
	int data;
};
int max=6;

struct cirQueue queue[6];
int rear=-1,front=-1;

void insert(int val)
{
if((rear+1) %max == front)
	printf("\n Queue is full");
else{
	if(front==-1)
		front=0;
	rear=(rear+1)%max;
	queue[rear].data=val;
	printf("\n %d added at %d \n",queue[rear].data,rear);	
}
}

void delete()
{
	if(front==-1)
		printf("\n Empty queue");
	else{
		printf("\n Value deleted : %d ",queue[front].data);
		front=(front+1)%max;
		if(front==rear+1)
			front=rear=-1;
	}
}

void display()
{
	if(front==-1)
		printf("\n queue is empty");
	else
	{
		printf("\n Elements in queue are: \n");
		for(int i=front;i!=rear;i=(i+1)%max)
		{
			printf("\n i=%d, %d\n",i,queue[i].data);
		}
		printf("%d",queue[rear].data);
	}
}

void main()
{
	while(1)
	{
		int ch,n;
		printf("\n Enter a choice\n1.Insert\n2.delete\n");
		printf("3.Display\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("\n Enter value to add. : ");
			scanf("%d",&n);
			insert(n);
			break;
		case 2:
			delete();
			break;
		case 3: display();
			break;
		case 4: exit(0);
		default: printf("\n Enter a valid choice!");
		}
	}
}
