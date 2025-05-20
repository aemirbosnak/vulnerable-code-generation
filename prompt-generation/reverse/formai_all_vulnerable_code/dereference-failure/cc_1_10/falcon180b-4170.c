//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node* head, int data){
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node* insertAtEnd(Node* head, int data){
    Node* newNode = createNode(data);
    if(head == NULL){
        return newNode;
    }
    Node* temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* insertAtPosition(Node* head, int data, int position){
    Node* newNode = createNode(data);
    if(head == NULL || position == 1){
        return insertAtBeginning(head, data);
    }
    Node* temp = head;
    for(int i=1; i<position-1 && temp->next!= NULL; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* deleteNode(Node* head, int data){
    if(head == NULL){
        return head;
    }
    if(head->data == data){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    while(temp->next!= NULL && temp->next->data!= data){
        temp = temp->next;
    }
    if(temp->next == NULL){
        return head;
    }
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    free(delNode);
    return head;
}

void displayList(Node* head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Node* head = NULL;
    head = insertAtBeginning(head, 3);
    head = insertAtEnd(head, 5);
    head = insertAtPosition(head, 2, 2);
    displayList(head);
    head = deleteNode(head, 2);
    displayList(head);
    head = deleteNode(head, 3);
    displayList(head);
    head = deleteNode(head, 5);
    displayList(head);
    return 0;
}