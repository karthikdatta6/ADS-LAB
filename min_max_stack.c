#include <stdio.h> 
#define MAX 9 
 
int top1 = -1; 
int top2 = -1; 
int top3 = -1; 
 
void push(int stack[], int stack1[], int stack2[]) { 
    int val; 
    printf("Enter val: "); 
    scanf("%d", &val); 
 
    if (top1 == MAX - 1) { 
        printf("Overflow\n"); 
        return; 
    } 
 
    top1++; 
    stack[top1] = val; 
 
    if (top2 == -1) { 
        top2++; 
        stack1[top2] = val; 
    } else { 
        int current_min = stack1[top2]; 
        top2++; 
        stack1[top2] = (val < current_min) ? val : current_min; 
    } 
 
    if (top3 == -1) { 
        top3++; 
        stack2[top3] = val; 
    } else { 
        int current_max = stack2[top3]; 
        top3++; 
        stack2[top3] = (val > current_max) ? val : current_max; 
    } 
} 
 
void pop(int stack[], int stack1[], int stack2[]) { 
    if (top1 == -1) { 
        printf("Underflow\n"); 
        return; 
    } 
 
    printf("Popped element from minstack is: %d\n", stack1[top2]); 
    top2--; 
 
    printf("Popped element from maxstack is: %d\n", stack2[top3]); 
    top3--; 
 
    printf("Popped element from original stack is: %d\n", stack[top1]); 
    top1--; 
} 
 
void peek(int stack[]) { 
    if (top1 == -1) { 
        printf("Stack is empty\n"); 
        return; 
    } 
    printf("Top element is:%d\n",stack[top1]); 
} 
 
void getMin(int stack1[]) { 
    if (top2 == -1) { 
        printf("Min-stack is empty\n"); 
        return; 
    } 
    printf("Min element is: %d\n",stack1[top2]); 
} 
 
void getMax(int stack2[]) { 
    if (top3 == -1) { 
        printf("Max-stack is empty\n"); 
        return; 
    } 
    printf("Max element is: %d\n",stack2[top3]); 
} 
 
void display(int stack[],int stack1[],int stack2[]) 
{ 
	int i; 
	printf("\nOriginal stack: "); 
	for(i=top1;i>=0;i--){ 
		printf("%d",stack[i]); 
	} 
	 
	printf("\nMin stack: "); 
	for(i=top2;i>=0;i--){ 
		printf("%d",stack1[i]); 
	} 
	 
	printf("\nMax stack: "); 
	for(i=top3;i>=0;i--){ 
		printf("%d",stack2[i]); 
	} 
} 
 
int main(){ 
	int stack[MAX]; 
	int stack1[MAX]; 
	int stack2[MAX]; 
	 
	int ch; 
	 
	while(1){ 
		printf("1.\nPush\n"); 
		printf("2.Pop\n"); 
		printf("3.peek\n"); 
		printf("4.getmin\n"); 
		printf("5.getmax\n"); 
		printf("6.display\n"); 
		printf("7.exit\n"); 
		 
		printf("Enter ch: "); 
		scanf("%d",&ch); 
		 
		switch(ch){ 
			case 1: 
				push(stack,stack1,stack2); 
				break; 
				 
			case 2: 
				pop(stack,stack1,stack2); 
				break; 
				 
			case 3: 
				peek(stack);				 
				break; 
				 
		    case 4: 
		    	getMin(stack1); 
		    	break; 
		    	 
		    case 5: 
		    	getMax(stack2); 
		    	break; 
		    	 
		    case 6: 
		    	display(stack,stack1,stack2); 
		    	break; 
		    	 
		    case 7: 
		    	return 0; 
		    	 
		    default: 
		    	printf("Invalid choice\n"); 
		    	 
		    	 
		} 
	} 
	return 0; 
}sdimilarly
