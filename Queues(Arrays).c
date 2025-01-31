#include<stdio.h>

int front = -1;
int rear = -1;

int isEmpty(){
    if(rear==-1){
        return 1;
    }
    return 0;
}

void Enqueue(int *queue,int queue_size){
    if(rear == queue_size-1){
        printf("Queue Overflow\n");
        return;
    }
    int value;
    printf("Enter the value to add to queue: ");
    scanf("%d",&value);
    
    if(front==-1){
        front = 0;
    }
    rear++;
    queue[rear] = value;
    
}

void Dequeue(int *queue,int queue_size){
    int value;
    if(isEmpty()){
        printf("Queue is Empty\n");
        return;
    }
    
    value = queue[front];
    for(int i=front;i<rear;i++){
        queue[i] = queue[i+1];
    }
    rear--;
    printf("The Dequeued element: %d\n",value);
}

void peek(int queue[]){
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    printf("The element at the front of the queue: %d\n",queue[front]);
}
void printQueue(int queue[]){
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    printf("FRONT\n");
    for(int i=front;i<=rear;i++){
        printf("%d\n",queue[i]);
    }
    printf("REAR\n");
}
void size(int queue[]){
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    int size=0;
    for(int i=front;i<=rear;i++){
        size++;
    }
    printf("The current size of the queue: %d\n",size);
}
int main(){
    int choice;
    int queue_size;
    int value;
    printf("Enter the queue size:");
    scanf("%d",&queue_size);
    int queue[queue_size];
    while(1){
        printf("Queue Operations on Arrays\n1.Enqueue\n2.Dequeue\n3.peek\n4.isEmpty\n5.size\n6.Print the Queue\n7.Exit\n");
        do{
            printf("Enter the choice: ");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    Enqueue(queue,queue_size);
                    break;
                case 2:
                    Dequeue(queue,queue_size);
                    
                    break;
                case 3:
                    peek(queue);
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
                    size(queue);
                    break;
                case 6:
                    printQueue(queue);
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