//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, int data){
    Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteNode(Node** head, int data){
    Node* temp = *head;
    Node* prev = NULL;
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Node not found\n");
        return;
    }
    if(prev == NULL){
        *head = temp->next;
    }
    else{
        prev->next = temp->next;
    }
    free(temp);
}

int searchNode(Node* head, int data){
    Node* temp = head;
    while(temp!= NULL){
        if(temp->data == data){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void reverseList(Node** head){
    Node* current = *head;
    Node* prev = NULL;
    Node* next = NULL;

    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

int main(){
    Node* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);
    printf("Original list: ");
    printList(head);
    reverseList(&head);
    printf("\nReversed list: ");
    printList(head);
    deleteNode(&head, 3);
    printf("\nList after deleting node with data 3: ");
    printList(head);
    int result = searchNode(head, 4);
    if(result == 1){
        printf("\nNode with data 4 found");
    }
    else{
        printf("\nNode with data 4 not found");
    }
    return 0;
}