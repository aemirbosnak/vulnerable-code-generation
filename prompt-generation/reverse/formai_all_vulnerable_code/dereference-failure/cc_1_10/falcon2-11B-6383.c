//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void push(Node** head_ref, int data){
    Node* new_node = createNode(data);
    Node* temp = *head_ref;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

void printList(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    printf("The list is:\n");
    printList(head);
    return 0;
}