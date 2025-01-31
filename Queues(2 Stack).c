#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5

struct Stack{
    int array[MAXSIZE];
    int top;
};

struct Stack *stack1;
struct Stack *stack2;

int isEmpty(struct Stack *stack){
    if(stack->top==-1){
        return 1;
    }
    return 0;
}

int isfull(struct Stack *stack){
    if(stack->top==MAXSIZE-1){
        return 1;
    }
    return 0;
}

void push(struct Stack *stack,int value){
    if(isfull(stack)){
        printf("Queue Overflow\n");
        return;
    }
    stack->top++;
    stack->array[stack->top] = value;
}

int pop(struct Stack *stack){
    int value;
    if(isEmpty(stack)){
        printf("Empty Queue\n");
        return -1;
    }
    value = stack->array[stack->top];
    stack->top--;
    return value;
}

void enQueue(int value){
    int poped_value;
    if(isEmpty(stack1)){
        push(stack1,value);
        return;
    }
    else{
        while(stack1->top!=-1){
            poped_value = pop(stack1);
            push(stack2,poped_value);
        }
        push(stack1,value);
        while(stack2->top!=-1){
            poped_value = pop(stack2);
            push(stack1,poped_value);
        }
    }
}

void deQueue(){
    int value = pop(stack1);
    if(value==-1){
        return;
    }
    printf("The Dequeued element: %d\n",value);
}

void printQueue(struct Stack *stack ){
    printf("FRONT\n");
    for(int i=stack->top;i>=0;i--){
        printf("%d\n",stack->array[i]);
    }
    printf("REAR\n");
}

int size(struct Stack *stack){
    return stack->top + 1 ;
}

void peek() {
    if (!isEmpty(stack1)) {
        printf("Front element: %d\n", stack1->array[stack1->top]);
    } else {
        printf("Queue is empty\n");
    }
}

int main(){
    
    stack1 = (struct Stack *)malloc(sizeof(struct Stack));
    stack2 = (struct Stack *)malloc(sizeof(struct Stack));

    stack1->top = -1;
    stack2->top = -1;

    int value;
    int choice;
    while(1){
        printf("Queue Operations on Arrays\n1.Enqueue\n2.Dequeue\n3.peek\n4.isEmpty\n5.size\n6.Print the Queue\n7.Exit\n");
        do{
            printf("Enter the choice: ");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    printf("Enter the element: ");
                    scanf("%d",&value);
                    enQueue(value);
                    break;
                case 2:
                    deQueue(stack1);
                    break;
                case 3:
                    peek(stack1);
                    break;
                case 4:
                    if(isEmpty(stack1)){
                        printf("Queue is empty\n");
                    }
                    else{
                        printf("Queue is not empty\n");
                    }
                    break;
                case 5:
                    value = size(stack1);
                    printf("The size of the queue: %d\n",value);
                    break;
                case 6:
                    printQueue(stack1);
                    break;
                case 7: 
                    printf("Exiting the program....");
                    return 0;
                default: 
                    printf("Invalid operation\n");
                    break;
            }
        }while(choice!=7);
        
    }
    return 0;
}
