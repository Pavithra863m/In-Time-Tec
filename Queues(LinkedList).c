#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

int isEmpty(){
    if(head==NULL && tail==NULL){
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
    
    if(tail==NULL && head==NULL){
        tail = newNode;
        head = newNode;
        return;
    }
    tail->next = newNode;
    tail=newNode;
}

void Enqueue(){
    int value;
    printf("Enter the value to the node in stack: ");
    scanf("%d",&value);
    insertion(value);
}

void Dequeue(){
    struct Node *temp = head;
    if(isEmpty()){
        printf("Queue is empyty\n");
        return;
    }
    if(temp->next==NULL){
        printf("The Dequeued element: %d\n",temp->data);
        free(temp);
        head=NULL;
        tail=NULL;
        return;
    }
    head = head->next;
    printf("The Dequeued element: %d\n",temp->data);
    free(temp);
}

void peek(){
    if(isEmpty()){
        printf("Queue is empyty\n");
        return;
    }
    printf("The element at the front of the Queue: %d\n",head->data);
    return;
}

void size(){
    if(isEmpty()){
        printf("Queue is empyty\n");
        return;
    }
    int size=0;
    struct Node *temp = head;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    printf("The number of elements in the Queue: %d\n",size);
}

void printQueue(){
    struct Node *temp = head;
    if(head==NULL){
        printf("Queue empty\n");
        return;
    }
    printf("FRONT->");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("REAR\n");
}

int main(){
    int choice;
    while(1){
        printf("Queue Operations on Linked List\n1.Enqueue\n2.Dequeue\n3.peek\n4.isEmpty\n5.size\n6.Print the Queue\n7.Exit\n");
        do{
            printf("Enter the choice: ");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    Enqueue();
                    break;
                case 2:
                    Dequeue();
                    break;
                case 3:
                    peek();
                    break;
                case 4:
                    if(isEmpty()){
                        printf("Queue is empty\n");
                    }
                    else{
                        printf("Queue is not empty\n");
                    }
                    break;
                case 5:
                    size();
                    break;
                case 6:
                    printQueue();
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