//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    char name[20];
    struct Node* next;
} Node;

// Function to create a new node with given data and name
Node* createNode(int data, char* name) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(Node** head, int data, char* name) {
    Node* newNode = createNode(data, name);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(Node** head, int data, char* name) {
    Node* newNode = createNode(data, name);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to print the contents of the list
void printList(Node* head) {
    Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("(%d, %s) -> ", current->data, current->name);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Insert nodes at the beginning of the list
    insertAtBeginning(&head, 1, "Apple");
    insertAtBeginning(&head, 2, "Banana");

    // Insert nodes at the end of the list
    insertAtEnd(&head, 3, "Cherry");
    insertAtEnd(&head, 4, "Durian");

    // Print the list
    printList(head);

    // Free the memory allocated to the nodes
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}