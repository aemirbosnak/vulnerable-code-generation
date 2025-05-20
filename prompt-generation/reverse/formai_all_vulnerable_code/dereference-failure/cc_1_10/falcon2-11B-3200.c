//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    return *head;
}

struct Node* insertAtTail(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    while(temp->next!= NULL)
        temp = temp->next;
    temp->next = newNode;
    return *head;
}

struct Node* insertAfter(struct Node** head, int data, int pos) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    int i = 0;
    while(temp!= NULL && i < pos-1) {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return *head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    head = insertAtHead(&head, 10);
    head = insertAtHead(&head, 20);
    head = insertAtTail(&head, 30);
    head = insertAfter(&head, 10, 1);
    head = insertAfter(&head, 20, 2);
    printList(head);
    return 0;
}