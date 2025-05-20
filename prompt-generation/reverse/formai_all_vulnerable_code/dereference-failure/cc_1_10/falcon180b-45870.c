//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: systematic
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

Node* createLinkedList(){
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = createNode(1);
    second = createNode(2);
    third = createNode(3);

    head->next = second;
    second->next = third;

    return head;
}

void printLinkedList(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void addNodeAtBeginning(Node** headRef, int data){
    Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

void addNodeAtEnd(Node** headRef, int data){
    Node* newNode = createNode(data);

    if(*headRef == NULL){
        newNode->next = NULL;
        *headRef = newNode;
        return;
    }

    Node* last = *headRef;
    while(last->next!= NULL){
        last = last->next;
    }

    last->next = newNode;
}

void addNodeAtPosition(Node** headRef, int data, int position){
    Node* newNode = createNode(data);

    if(position == 1){
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }

    Node* temp = *headRef;
    for(int i=1; i<position-1 && temp!=NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNodeByValue(Node** headRef, int data){
    Node* temp = *headRef;
    Node* prev = NULL;

    if(temp!= NULL && temp->data == data){
        *headRef = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Element not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int searchElement(Node* head, int data){
    Node* temp = head;
    while(temp!= NULL){
        if(temp->data == data){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main(){
    Node* head = createLinkedList();
    printLinkedList(head);

    addNodeAtBeginning(&head, 0);
    printLinkedList(head);

    addNodeAtEnd(&head, 4);
    printLinkedList(head);

    addNodeAtPosition(&head, 2, 2);
    printLinkedList(head);

    deleteNodeByValue(&head, 0);
    printLinkedList(head);

    if(searchElement(head, 3)){
        printf("Element found\n");
    }else{
        printf("Element not found\n");
    }

    return 0;
}