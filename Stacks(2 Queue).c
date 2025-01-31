#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Queue {
    int* array;
    int front; 
    int rear;
};

int is_empty(struct Queue* queue) {
    if (queue->front == -1) {
        return 1;
    }
    return 0;
}

int is_full(struct Queue* queue) {
    if (queue->rear == MAX - 1) {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue* queue, int value) {
    if (is_full(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (is_empty(queue)) {
        queue->front = 0;
    }
    queue->array[++queue->rear] = value;
}

int dequeue(struct Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue->array[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return value;
}

int peek(struct Queue* queue) {
    if (is_empty(queue)) {
        printf("Stack is empty\n");
        return -1;
    }
    return queue->array[queue->front];
}

void push(struct Queue* queue1, struct Queue* queue2, int value) {
    if (is_full(queue1)) {
        printf("Stack is full\n");
        return;
    }

    enqueue(queue2, value);
    while (!is_empty(queue1)) {
        enqueue(queue2, dequeue(queue1));
    }

    struct Queue temp = *queue1;
    *queue1 = *queue2;
    *queue2 = temp;
}

void pop(struct Queue* queue1) {
    if (is_empty(queue1)) {
        printf("Stack is empty\n");
        return;
    }
    int value = dequeue(queue1);
    printf("Popped element: %d\n", value);
}

int size(struct Queue* queue1) {
    if (is_empty(queue1)) {
        return 0;
    }
    return queue1->rear - queue1->front + 1;
}

void print_stack(struct Queue* queue1) {
    if (is_empty(queue1)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents:\n");
    for (int i = queue1->front; i <= queue1->rear; i++) {
        printf("%d\n", queue1->array[i]);
    }
}

int main() {
    struct Queue* queue1 = (struct Queue*)malloc(sizeof(struct Queue));
    struct Queue* queue2 = (struct Queue*)malloc(sizeof(struct Queue));
    queue1->front = queue1->rear = -1;
    queue2->front = queue2->rear = -1;
    int value, choice;

    queue1->array = (int*)malloc(sizeof(int) * MAX);
    queue2->array = (int*)malloc(sizeof(int) * MAX);
    
    printf("Stack Operations using Two Queues\n");
    printf("1.Push\n2.Pop\n3.Peek\n4.Is Empty\n5.Size\n6.Print Stack\n7.Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &value);
                push(queue1, queue2, value);
                break;
            case 2:
                pop(queue1);
                break;
            case 3:
                value = peek(queue1);
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                if (is_empty(queue1)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 5:
                printf("Stack size: %d\n", size(queue1));
                break;
            case 6:
                print_stack(queue1);
                break;
            case 7:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
