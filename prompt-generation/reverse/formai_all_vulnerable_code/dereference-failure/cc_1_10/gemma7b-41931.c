//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: Ada Lovelace
#include <stdlib.h>
#include <stdio.h>

// Define a singly linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a singly linked list
Node* createList() {
    return NULL;
}

// Insert a node at the end
void insertAtEnd(Node* head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

// Print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = createList();
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    printList(head);

    return 0;
}