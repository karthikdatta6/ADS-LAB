#include <stdio.h>
#define MAX 9

int top1 = -1;
int top2 = MAX;


void push1(int stack[])
{   int val;
	printf("Enter val: ");
	scanf("%d",&val);
	
	if((top1 + 1) == top2){
		printf("Stack overflow\n");
		return;
	}
	stack[++top1] = val;
}

void push2(int stack[])
{   int val;
	printf("Enter val: ");
	scanf("%d",&val);
	
	if((top1 + 1) == top2){
		printf("Stack overflow\n");
		return;
	}
	stack[--top2] = val;
}

int pop1(int stack[])
{
	if(top1==-1){
		printf("Stack underflow\n");
		return;
	}
	int p = stack[top1];
	top1--;
	printf("Popped element is:%d\n",p);
}

void pop2(int stack[])
{
	if(top2==MAX){
		printf("Stack underflow\n");
		return;
	}
	int p = stack[top2];
	top2++;
	printf("Popped element is:%d\n",p);
}


void display1(int stack[])
{   
    if(top1==-1){
    	printf("Underflow\n");
    	return;
	}
	
    int i;
    printf("\nStack1: ");
    
    for(i=top1;i>=0;i--){
    	printf("%d ",stack[i]);
	}   
}

void display2(int stack[])
{
	if(top2==MAX){
    	printf("Underflow\n");
    	return;
	}
	
    int i;
    printf("\nStack2: ");
    
    for(i=top2;i<MAX;i++){
    	printf("%d ",stack[i]);
	}   
}

int main()
{
	int stack[MAX];
	int ch;
	
	while(1)
	{
		printf("\n1.push1\n");
		printf("2.push2\n");
		printf("3.pop1\n");
		printf("4.pop2\n");
		printf("5.display1\n");
		printf("6.display2\n");
		printf("7.exit\n");
		
		printf("Enter ch: ");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				push1(stack);
				break;
				
			case 2:
				push2(stack);
				break;
				
		    case 3:
				pop1(stack);
				break;
				
			case 4:
				pop2(stack);
				break;
				
			case 5:
				display1(stack);
				break;
				
			case 6:
				display2(stack);
				break;
				
			case 7:
				return 0;
				
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}sample input and output and time and space complexity
