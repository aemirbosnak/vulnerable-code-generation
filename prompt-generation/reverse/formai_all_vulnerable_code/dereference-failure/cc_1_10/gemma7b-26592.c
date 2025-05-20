//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Define a structure node
typedef struct node {
    int data;
    struct node* next;
} node;

// Function to insert at the end
void insertAtEnd(node* head, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    head = newNode;
}

// Function to search for a node
node* search(node* head, int data) {
    node* current = head;

    while (current) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

int main() {
    node* head = NULL;
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    node* foundNode = search(head, 30);

    if (foundNode) {
        printf("Node found: %d\n", foundNode->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}