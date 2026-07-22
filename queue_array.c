#include <stdio.h>
#include <stdlib.h>
#define MAX 25

int front = -1;
int rear = -1;

void enqueue(int q[]){
	int val;
	printf("Enter val: ");
	scanf("%d",&val);
	
	if(rear==MAX-1){
		printf("Queue overflow\n");
		return;
	}
	else{
		if(front==-1){
			front = 0;
		}
		
		q[++rear]  = val;
		
	}
}

void dequeue(int q[]){
	if(front==-1||front>rear){
		printf("Queue underflow");
		return;
	}
	else{
		printf("Element to be deleted is: %d\n",q[front]);
		front = front + 1;
	}
	
}

void display(int q[]){
	if(front==-1){
		printf("Queue is empty\n");
		return;
	}
	printf("QUEUE ELEMENTS: ");
	
	for(int i=front;i<=rear;i++){
		printf("%d ",q[i]);
	}
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
