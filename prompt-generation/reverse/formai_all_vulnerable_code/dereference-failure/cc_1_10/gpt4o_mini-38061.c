//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for a doubly linked list
typedef struct Node {
    char data[100];
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to display the list from head to tail
void displayList(Node* head) {
    Node* current = head;
    printf("Doubly Linked List (Head to Tail):\n");
    while (current != NULL) {
        printf("| %s | <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to display the list from tail to head
void displayListReverse(Node* tail) {
    Node* current = tail;
    printf("Doubly Linked List (Tail to Head):\n");
    while (current != NULL) {
        printf("| %s | <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

// Function to add a node at the end of the list
void appendNode(Node** head, Node** tail, const char* data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

// Function to free the list
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Adding nodes to the list
    appendNode(&head, &tail, "Node 1");
    appendNode(&head, &tail, "Node 2");
    appendNode(&head, &tail, "Node 3");
    appendNode(&head, &tail, "Node 4");
    appendNode(&head, &tail, "Node 5");

    // Displaying the list from head to tail
    displayList(head);
    // Displaying the list from tail to head
    displayListReverse(tail);

    // Freeing the allocated memory
    freeList(head);

    return 0;
}