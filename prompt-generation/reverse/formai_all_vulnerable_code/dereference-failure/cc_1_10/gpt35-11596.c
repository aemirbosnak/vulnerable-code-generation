//FormAI DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Node of a linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Returns a new node with specified data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Adds a new node at the end of the list
void appendToList(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Displays the contents of the list
void displayList(Node* head) {
    printf("List contents: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Tests the linked list implementation
int main() {

    // Create an empty linked list
    Node* head = NULL;

    // Add some nodes to the list
    appendToList(&head, 10);
    appendToList(&head, 20);
    appendToList(&head, 30);
    appendToList(&head, 40);

    // Display the contents of the list
    displayList(head);

    // Free the memory allocated to the list
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}