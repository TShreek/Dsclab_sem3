#include<stdio.h>
#include<stdlib.h>

int queue[20];
int rear=-1,front=-1;

void insert(int no)
{
	if(rear==-1)
		front=0;
	queue[++rear]=no;
	printf("\n Caller waiting on line : %d ",queue[rear]);
}

void delete()
{
	if(front==-1){
		printf("\n No callers waiting in queue");
	}
	else{
		printf("\n Caller Answerred : %d",queue[front]);
		front++;
	}
	if(front>rear)
		front=rear=-1;
}

void display(){
	if(rear==-1)
		printf("\n queue Empty");
	else{
		int i=0;
		printf("\n Callers waiting :\n");
		for(i=front;i<=rear;i++)
			{
				printf("%d \n",queue[i]);
			}
		}
}

void main()
{
	while(1){
		printf("\n rear =%d, front = %d \n",rear,front);
		printf("\n Enter a valid choice: \n1.Insert\nDelete\n3.display\n4.Exit\n");
		int ch,val;
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("\n Enter caller number to add:");
			scanf("%d",&val);
			insert(val);
			break;
		case 2:
			delete();
			break;
		case 3:
			display();
			break;
		case 4:exit(0);
		default: printf("\n Enter a proper input");
		}
	}
}
