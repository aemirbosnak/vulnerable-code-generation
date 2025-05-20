//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a node at the end
void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to search for a node
Node* search(Node* head, int data) {
    while (head) {
        if (head->data == data) {
            return head;
        } else {
            head = head->next;
        }
    }

    return NULL;
}

int main() {
    Node* head = NULL;

    // Insert a few nodes
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    // Search for a node
    Node* foundNode = search(head, 30);

    // Print the found node's data
    if (foundNode) {
        printf("Found node's data: %d\n", foundNode->data);
    } else {
        printf("Node not found.\n");
    }

    return 0;
}