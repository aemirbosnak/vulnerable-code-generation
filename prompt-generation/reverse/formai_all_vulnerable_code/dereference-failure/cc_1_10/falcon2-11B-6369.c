//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Node Structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Linked List
Node* head = NULL;

Node* createNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node* insertAtBeginning(int data) {
    Node* node = createNode(data);
    node->next = head;
    head = node;
    return head;
}

Node* insertAtEnd(int data) {
    Node* node = createNode(data);
    Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = node;
    return head;
}

void display() {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    display();

    insertAtBeginning(15);
    insertAtEnd(25);
    display();

    return 0;
}