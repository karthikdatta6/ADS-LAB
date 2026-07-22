#include <stdio.h>
#include <stdlib.h>
#define MAX 25

int front =-1;
int rear=-1;

void enqueue(int q[]){
	int val;
	printf("Enter val: ");
	scanf("%d",&val);
	
	if((rear+1)%MAX==front){
		printf("Queue full\n");
		return;
	}
	if(front==-1){
		front = 0;
	}
	rear = (rear+1)%MAX;
	q[rear] = val;
}

int dequeue(int q[]){
	if(front==-1){
		printf("Queue underflow\n");
		return -1;
	}
	
	int x = q[front];
	
	if(front==rear){
		front = -1;
		rear = -1;
	}
	
	front = (front + 1) % MAX;
	
	return x;
}

void display(int q[]){
	if(front==-1){
		printf("Queue underflow\n");
		return;
	}
	
	int i=front;
	while(1){
		printf("%d ",q[i]);
		if (i == rear) break;
		i = (i+1)%MAX;
	}
	printf("\n");
	
}

int main(){
	int q[MAX];
	int ch;
	
	while(1){
		printf("\n1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		
		
		printf("Enter ch: ");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				enqueue(q);
				display(q);
				break;
				
		    case 2:
		    	dequeue(q);
		    	display(q);
		    	break;
		    	
		    case 3:
		    	display(q);
		    	break;
		    	
		    case 4:
		    	return 0;
		    	
		    default:
		    	printf("Invalid choice\n");
		    	
		}
		
	}
	return 0;
}
