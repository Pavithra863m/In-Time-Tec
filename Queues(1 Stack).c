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

int is_full(struct Stack* stack) {
    if (stack->top == MAX - 1) {
        return 1;
    }
    return 0;
}

int is_empty(struct Stack* stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

void push(struct Stack* stack, int value) {
    if (is_full(stack)) {
        printf("Queue is full\n");
        return;
    }
    stack->top++;
    stack->array[stack->top] = value;
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

void enqueue(struct Stack* stack_in, int value) {
    push(stack_in, value);
}

int dequeue(struct Stack* stack_in, struct Stack* stack_out) {
    if (is_empty(stack_out)) {
        while (!is_empty(stack_in)) {
            push(stack_out, pop(stack_in));
        }
    }

    if (is_empty(stack_out)) {
        printf("Queue is empty\n");
        return -1;
    }
    return pop(stack_out);
}

int peek_front(struct Stack* stack_in, struct Stack* stack_out) {
    if (is_empty(stack_out)) {
        while (!is_empty(stack_in)) {
            push(stack_out, pop(stack_in));
        }
    }

    if (is_empty(stack_out)) {
        printf("Queue is empty\n");
        return -1;
    }
    return peek(stack_out);
}

int size(struct Stack* stack_in, struct Stack* stack_out) {
    return stack_in->top + 1 + stack_out->top + 1;
}

void print_queue(struct Stack* stack_in, struct Stack* stack_out) {
    if (is_empty(stack_in) && is_empty(stack_out)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue contents:\nFRONT\n");

    for (int i = stack_out->top; i >= 0; i--) {
        printf("%d\n", stack_out->array[i]);
    }

    for (int i = 0; i <= stack_in->top; i++) {
        printf("%d\n", stack_in->array[i]);
    }

    printf("REAR\n");
}

int main() {
    struct Stack stack_in, stack_out;
    init_stack(&stack_in);
    init_stack(&stack_out);

    int value, choice = 0;
    printf("Queue Operations using two stacks\n");
    printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Is Empty\n5.Size\n6.Print Queue\n7.Exit");

    while (choice != 7) {
        printf("\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &value);
                enqueue(&stack_in, value);
                break;
            case 2:
                value = dequeue(&stack_in, &stack_out);
                if (value != -1) {
                    printf("%d dequeued\n", value);
                }
                break;
            case 3:
                value = peek_front(&stack_in, &stack_out);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 4:
                if (is_empty(&stack_in) && is_empty(&stack_out)) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 5:
                printf("Size: %d\n", size(&stack_in, &stack_out));
                break;
            case 6:
                print_queue(&stack_in, &stack_out);
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
