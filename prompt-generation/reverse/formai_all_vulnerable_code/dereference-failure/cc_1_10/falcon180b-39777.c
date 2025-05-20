//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void createLinkedList(Node** head) {
    *head = malloc(sizeof(Node));
    if (*head == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    (*head)->data = 0;
    (*head)->next = NULL;
}

void addElement(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayLinkedList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseLinkedList(Node** head) {
    Node* prev = NULL;
    Node* curr = *head;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main() {
    Node* head = NULL;
    createLinkedList(&head);
    addElement(&head, 10);
    addElement(&head, 20);
    addElement(&head, 30);
    addElement(&head, 40);
    addElement(&head, 50);
    displayLinkedList(head);
    reverseLinkedList(&head);
    displayLinkedList(head);
    return 0;
}