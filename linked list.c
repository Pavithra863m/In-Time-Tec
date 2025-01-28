#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* split(struct Node* head){
    struct Node* fast = head;
    struct Node* slow = head;
    
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        if(fast != NULL){
            slow = slow->next;
        }
    }

    struct Node* temp = slow->next;
    slow->next = NULL;
    return temp;
}

struct Node* merge(struct Node* first, struct Node* second){
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }

    if(first->data < second->data){
        first->next = merge(first->next, second);
        return first;
    }
    else{
        second->next = merge(first, second->next);
        return second;
    }
}

struct Node* merge_sort(struct Node* node){
    if(node == NULL || node->next == NULL){
        return node;
    }

    struct Node* second = split(node);

    node = merge_sort(node);
    second = merge_sort(second);
    return merge(node, second);
}

void insertAtEnd(int new_data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = new_data;
    newNode -> next = NULL;
    if(head == NULL){
        head = newNode;
        return;
    }
    struct Node *last_node = head;
    while(last_node -> next != NULL){
        last_node = last_node -> next;
    }
    last_node -> next = newNode;
}
void print_list(){
    if(head==NULL){
        printf("Empty Linked List\n");
        return;
    }
    struct Node *current_node = head;
    while(current_node!=NULL){
        printf("%d->",current_node -> data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}
int main(){
    int number_of_nodes;
    printf("Enter the number of nodes: ");
    scanf("%d",&number_of_nodes);
    int value;
    printf("Enter the node values: ");
    for(int i=0;i<number_of_nodes;i++){
        scanf("%d",&value);
        insertAtEnd(value);
    }
    printf("The unsorted linked list: ");
    print_list();
    
    head = merge_sort(head);
    
    printf("The sorted linked list: ");
    print_list();
    
    return 0;
}