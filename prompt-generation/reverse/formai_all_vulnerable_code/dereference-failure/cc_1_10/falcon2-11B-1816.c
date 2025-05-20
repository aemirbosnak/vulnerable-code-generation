//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;

void insertAtBeginning(int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

void insertAfter(int currentData, int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    Node* temp = head;
    while (temp->next!= NULL && temp->next->data!= currentData) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtEnd(int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList() {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertAtBeginning(1);
    insertAtBeginning(2);
    insertAtBeginning(3);
    insertAtBeginning(4);
    insertAtEnd(5);
    insertAtEnd(6);
    insertAtEnd(7);
    printList();
    insertAfter(2, 8);
    printList();
    insertAfter(7, 9);
    printList();
    return 0;
}