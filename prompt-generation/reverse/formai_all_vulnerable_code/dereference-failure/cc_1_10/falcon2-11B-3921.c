//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: innovative
#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;

void insertAtBeginning(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node* current = head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void insertAtPosition(int data, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (position == 0) {
        insertAtBeginning(data);
        return;
    }
    Node* current = head;
    for (int i = 1; i < position - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void deleteNode(int data) {
    Node* current = head;
    Node* previous = NULL;
    while (current!= NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void displayList() {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    insertAtBeginning(5);
    insertAtBeginning(10);
    insertAtBeginning(15);
    insertAtEnd(20);
    insertAtEnd(25);
    insertAtEnd(30);
    insertAtPosition(10, 2);
    displayList();
    printf("Deleting node with data 20...\n");
    deleteNode(20);
    displayList();
    return 0;
}