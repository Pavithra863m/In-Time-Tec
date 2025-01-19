#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

int getValidNumber() {
    int number;
    while (1) {
        scanf("%d", &number);
        if (number >= -1000 && number <= 1000) {
            return number;
        }
        printf("Error: value out of range.\nEnter value in range: ");
    }
}

int getValidPosition() {
    int position;
    while (1) {
        scanf("%d", &position);
        if (position >= 1) {
            return position;
        }
        printf("Error: Invalid Position.\nEnter a valid position: ");
    }
}

int getValidOperations() {
    int number_of_operations;
    while (1) {
        scanf("%d", &number_of_operations);
        if (number_of_operations >= 1 && number_of_operations <= 100) {
            return number_of_operations;
        }
        printf("Error: Number of operations out of range.\nEnter valid number of operations: ");
    }
}


void insertAtBeginning(int new_data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = new_data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int new_data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = new_data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *last_node = head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = newNode;
}

void insertAtPosition(int position, int new_data) {
    if (position == 1) {
        insertAtBeginning(new_data);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = new_data;

    struct Node *current_node = head;
    for (int i = 1; i < position - 1; i++) {
        if (current_node == NULL) {
            printf("Invalid position\n");
            free(newNode);
            return;
        }
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = current_node->next;
    current_node->next = newNode;
}

void display() {
    if (head == NULL) {
        printf("\n");
        return;
    }

    struct Node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

void updateAtPosition(int position, int new_value) {
    struct Node *current_node = head;
    for (int i = 1; i < position; i++) {
        if (current_node == NULL) {
            printf("Invalid position\n");
            return;
        }
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        printf("Invalid position\n");
        return;
    }

    current_node->data = new_value;
}

void deleteAtBeginning() {
    if (head == NULL) {
        return;
    }

    struct Node *beginning_node = head;
    head = head->next;
    free(beginning_node);
}

void deleteAtEnd() {
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *last_node = head;
    while (last_node->next->next != NULL) {
        last_node = last_node->next;
    }

    free(last_node->next);
    last_node->next = NULL;
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (position == 1) {
        deleteAtBeginning();
        return;
    }

    struct Node *current_node = head;
    struct Node *previous_node = NULL;

    for (int i = 1; i < position; i++) {
        if (current_node == NULL) {
            printf("Invalid position\n");
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        printf("Invalid position\n");
        return;
    }

    previous_node->next = current_node->next;
    free(current_node);
}

void handleOperation(int operation) {
    int value, position;
    if (operation < 1 || operation > 8) {
        printf("Error: Invalid operation.\nPlease enter a valid operation between 1 and 8: ");
        scanf("%d", &operation);
    }
    switch (operation) {
        case 1:
            value = getValidNumber();
            insertAtEnd(value);
            break;
        case 2:
            value = getValidNumber();
            insertAtBeginning(value);
            break;
        case 3:
            position = getValidPosition();
            value = getValidNumber();
            insertAtPosition(position, value);
            break;
        case 4:
            display();
            break;
        case 5:
            position = getValidPosition();
            value = getValidNumber();
            updateAtPosition(position, value);
            break;
        case 6:
            deleteAtBeginning();
            break;
        case 7:
            deleteAtEnd();
            break;
        case 8:
            position = getValidPosition();
            deleteAtPosition(position);
            break;
    }
}

int main() {
    int number_of_operations = getValidOperations();
    for (int i = 0; i < number_of_operations; i++) {
        int operation;
        scanf("%d", &operation);
        handleOperation(operation);
    }
    return 0;
}
