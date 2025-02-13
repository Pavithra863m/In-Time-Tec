#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

typedef struct Node{
    int key;
    int value;
    struct Node* next;
}Node;

typedef struct HashMap{
    Node* table[TABLE_SIZE];
}HashMap;

int getIndex(int key){
    return key % TABLE_SIZE;
}

void init(HashMap* hashMap){
    for(int i = 0; i < TABLE_SIZE; i++){
        hashMap->table[i] = NULL;
    }
}

Node* createNode(int key, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insert(HashMap* hashMap, int key, int value){
    
    int index=getIndex(key);
    Node* new= createNode(key,value);

    if(hashMap->table[index]==NULL){
        hashMap->table[index]=new;
    }
    else{
        Node* current = hashMap->table[index];
        current->next = new;
    }
}

int search(HashMap* hashMap, int key){
    int index = getIndex(key);
    Node* current = hashMap->table[index];
    while(current != NULL){
        if(current->key == key){
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

void delete(HashMap* hashMap, int key){
    int index = getIndex(key);
    Node* current = hashMap->table[index];
    Node* prev = NULL;
    while(current != NULL){
        if(current->key == key){
            if(prev == NULL){
                hashMap->table[index] = current->next;
            }
            else{
                prev->next = current->next;
            }
            printf("Key %d deleted.\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Key %d not found.\n", key);
}

void display(HashMap* hashMap){
    int first = 1;
    printf("Hash Table:\n");
    for(int i = 0; i < TABLE_SIZE; i++){
        Node* current = hashMap->table[i];
        if(current != NULL){
            printf("Index %d: ", i);
            while(current != NULL){
                if(first){
                    printf("(%d, %d) ", current->key, current->value);
                    current = current->next;
                    first = 0;
                }
                else{
                    printf("-> (%d, %d)", current->key, current->value);
                    current = current->next;
                }
            }
        }
    }
    printf("\n");
}

int main(){
    HashMap hashMap;
    init(&hashMap);

    int choice, key, value;
    printf("1. Insert (Put)\n2. Search (Get)\n3. Delete (Remove)\n4. Display\n5. Eixt\n");

    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(&hashMap, key, value);
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                value = search(&hashMap, key);
                if(value == -1){
                    printf("Key not found.\n");
                }
                else{
                    printf("Value: %d\n", value);
                }
                break;

            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                delete(&hashMap, key);
                break;

            case 4:
                display(&hashMap);
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
