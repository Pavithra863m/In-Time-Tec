#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Queue{
    int* array;
    int front;
    int rear;
};

int is_empty(struct Queue* queue){
    if(queue->front == -1){
        return 1;
    }
    return 0;
}

int is_full(struct Queue* queue){
    if(queue->rear == MAX - 1){
        return 1;
    }
    return 0;
}

void enqueue(struct Queue* queue, int value){
    if(is_full(queue)){
        printf("Queue is full\n");
        return;
    }
    if(is_empty(queue)){
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = value;
}

int dequeue(struct Queue* queue){
    int value;
    if(is_empty(queue)){
        printf("Queue is empty\n");
        return -1;
    }
    value = queue->array[queue->front];
    for(int i = queue->front; i < queue->rear; i++){
        queue->array[i] = queue->array[i + 1];
    }
    queue->rear--;
    return value;
}

int peek(struct Queue* queue){
    if(is_empty(queue)){
        printf("Queue is empty\n");
        return -1;
    }
    return queue->array[queue->front];
}

int size(struct Queue* queue){
    if(is_empty(queue)){
        return 0;
    }
    return (queue->rear - queue->front ) + 1;
}

void print_stack(struct Queue* queue){
    if(is_empty(queue)){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents:\n");
    for(int i = queue->front; i <= queue->rear; i++){
        printf("%d\n", queue->array[i]);
    }
}

void push(struct Queue* queue, int value){
    enqueue(queue, value);
    int count = queue->rear;
    while (queue->front < count){
        int dequeued_element = dequeue(queue);
        enqueue(queue, dequeued_element);
    }
}

void pop(struct Queue* queue){
    if(is_empty(queue)){
        printf("Stack is empty\n");
        return;
    }
    int value = dequeue(queue);
    printf("Popped value: %d\n", value);
}

int main(){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(sizeof(int) * MAX);
    int value;
    int choice;
    while (1){
        printf("Stack Operations using Queue\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Is Empty\n5.Size\n6.Print Stack\n7.Exit\n");
        do{
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch(choice){
                case 1:
                    printf("Enter the element: ");
                    scanf("%d", &value);
                    push(queue, value);
                    break;
                case 2:
                    pop(queue);
                    break;
                case 3:
                    value = peek(queue);
                    if(value != -1){
                        printf("Top element: %d\n", value);
                    }
                    break;
                case 4:
                    if(is_empty(queue)){
                        printf("Stack is empty\n");
                    } 
                    else{
                        printf("Stack is not empty\n");
                    }
                    break;
                case 5:
                    printf("Stack size: %d\n", size(queue));
                    break;
                case 6:
                    print_stack(queue);
                    break;
                case 7:
                    printf("Exiting the program...\n");
                    return 0;
                default:
                    printf("Invalid choice, please try again.\n");
                    break;
            }
        }while(choice!=7);
    }

    return 0;
}

