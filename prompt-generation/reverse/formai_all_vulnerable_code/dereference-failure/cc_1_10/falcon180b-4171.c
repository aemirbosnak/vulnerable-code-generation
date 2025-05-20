//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data){
    Node* newNode = createNode(data);
    Node* temp = *head;
    if(*head == NULL){
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void insertAtBeginning(Node** head, int data){
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    return;
}

void insertAtPosition(Node** head, int data, int pos){
    Node* newNode = createNode(data);
    Node* temp = *head;
    if(pos == 1){
        newNode->next = temp;
        *head = newNode;
        return;
    }
    for(int i=1;i<pos-1 && temp!= NULL;i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Position out of bounds\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return;
}

void deleteNode(Node** head, int data){
    Node* temp = *head;
    Node* prev = NULL;
    if(temp!= NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
    return;
}

void printList(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtPosition(&head, 4, 2);
    printList(head);
    deleteNode(&head, 2);
    printList(head);
    deleteNode(&head, 1);
    printList(head);
    deleteNode(&head, 3);
    printList(head);
    deleteNode(&head, 4);
    printList(head);
    return 0;
}