#include<stdio.h>
int top = -1;
int isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}
void push(int *stack,int stack_size){
    int value;
    if(top == stack_size-1){
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter thr value to be pushed to the stack: ");
    scanf("%d",&value);
    top = top+1;
    stack[top] = value;
}
void pop(int *stack){
    int value;
    if(isEmpty()){
        printf("Stack Empty\n");
        return;
    }
    value = stack[top];
    top=top-1;
    printf("The element poped: %d\n",value);
    
}
void size(){
    int size = top+1;
    printf("The number of elements in the stack: %d\n",size);
}

int peek(int stack[]){
    if(isEmpty()){
        printf("Stack is empty\n");
        return 0;
    }
    return stack[top];
}
void printstack(int stack[]){
    if(isEmpty()){
        printf("Stack is empty\n");
        return;
    }
    printf("TOP\n");
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}

int main(){
    int choice;
    int stack_size;
    int value;
    printf("Enter the stack size:");
    scanf("%d",&stack_size);
    int stack[stack_size];
    while(1){
        printf("Stack Operations on Arrays\n1.Push\n2.Pop\n3.peek\n4.isEmpty\n5.size\n6.Print the stack\n7.Exit\n");
        do{
            printf("Enter the choice: ");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    push(stack,stack_size);
                    break;
                case 2:
                    pop(stack);
                    
                    break;
                case 3:
                    value = peek(stack);
                    printf("The top element: %d\n",value);
                    break;
                case 4:
                    if(isEmpty()){
                        printf("stack is empty\n");
                    }
                    else{
                        printf("stack is not empty\n");
                    }
                    break;
                case 5:
                    size();
                    break;
                case 6:
                    printstack(stack);
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