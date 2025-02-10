#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Stack {
    int* array;
    int top;
};

void init_stack(struct Stack* stack) {
    stack->array = (int*)malloc(sizeof(int) * MAX);
    stack->top = -1;
}

int is_empty(struct Stack* stack) {
    return stack->top == -1;
}

int is_full(struct Stack* stack) {
    return stack->top == MAX - 1;
}

void push(struct Stack* stack, int value) {
    if (is_full(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->array[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (is_empty(stack)) {
        return -1;
    }
    return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
    if (is_empty(stack)) {
        return -1;
    }
    return stack->array[stack->top];
}

void enqueue(struct Stack* stack, int value) {
    if (is_full(stack)) {
        printf("Queue is full\n");
        return;
    }
    push(stack, value);
}

int dequeue(struct Stack* stack) {
    if (is_empty(stack)) {
        printf("Queue is empty\n");
        return -1;
    }

    struct Stack temp_stack;
    init_stack(&temp_stack);

    while (!is_empty(stack)) {
        push(&temp_stack, pop(stack));
    }

    int front = pop(&temp_stack);

    while (!is_empty(&temp_stack)) {
        push(stack, pop(&temp_stack));
    }

    return front;
}

int peek_front(struct Stack* stack) {
    if (is_empty(stack)) {
        printf("Queue is empty\n");
        return -1;
    }

    struct Stack temp_stack;
    init_stack(&temp_stack);

    while (!is_empty(stack)) {
        push(&temp_stack, pop(stack));
    }

    int front = peek(&temp_stack);

    while (!is_empty(&temp_stack)) {
        push(stack, pop(&temp_stack));
    }

    return front;
}

int size(struct Stack* stack) {
    return stack->top + 1;
}

void print_queue(struct Stack* stack) {
    if (is_empty(stack)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue contents:\nFRONT\n");

    struct Stack temp_stack;
    init_stack(&temp_stack);

    while (!is_empty(stack)) {
        push(&temp_stack, pop(stack));
    }

    while (!is_empty(&temp_stack)) {
        printf("%d\n", pop(&temp_stack));
    }

    printf("REAR\n");
}

int main() {
    struct Stack stack;
    init_stack(&stack);

    int value, choice = 0;
    printf("Queue Operations using a Single Stack\n");
    printf("1.Enqueue\n2.Dequeue\n3.Peek Front\n4.Is Empty\n5.Size\n6.Print Queue\n7.Exit");

    while (choice != 7) {
        printf("\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &value);
                enqueue(&stack, value);
                break;
            case 2:
                value = dequeue(&stack);
                if (value != -1) {
                    printf("%d dequeued\n", value);
                }
                break;
            case 3:
                value = peek_front(&stack);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 4:
                if (is_empty(&stack)) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 5:
                printf("Size: %d\n", size(&stack));
                break;
            case 6:
                print_queue(&stack);
                break;
            case 7:
                printf("Exiting the program....\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
