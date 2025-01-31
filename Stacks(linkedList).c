#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

int isEmpty(){
    if(head==NULL){
        return 1;
    }
    return 0;
}

void insertion(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    newNode->data=value;
    newNode->next = NULL;
    if(head==NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void push(){
    int value;
    printf("Enter the value to the node in stack: ");
    scanf("%d",&value);
    insertion(value);
}

void pop(){
    if(isEmpty()){
        printf("stack is empyty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    printf("The value poped is: %d\n",temp->data);
    free(temp);
}

void peek(){
    if(isEmpty()){
        printf("stack is empyty\n");
        return;
    }
    printf("The element at the top of the stack: %d\n",head->data);
    return;
}

void size(){
    int size=0;
    struct Node *temp = head;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    printf("The number of elements in the stack: %d\n",size);
}
void printstack(){
    struct Node *temp = head;
    if(head==NULL){
        printf("Stack empty\n");
        return;
    }
    printf("TOP->");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    int choice;
    while(1){
        printf("Stack Operations on Linked Lists\n1.Push\n2.Pop\n3.peek\n4.isEmpty\n5.size\n6.PrintStack\n7.Exit\n");
        do{
            printf("Enter the choice: ");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    push();
                    break;
                case 2:
                    pop();
                    
                    break;
                case 3:
                    peek();
                    break;
                case 4:
                    if(isEmpty()){
                        printf("Stack is empty\n");
                    }
                    else{
                        printf("Stack is not empty\n");
                    }
                    break;
                case 5:
                    size();
                    break;
                case 6:
                    printstack();
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