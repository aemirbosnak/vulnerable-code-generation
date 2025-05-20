//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Define a complex data structure to store a linked list of nodes
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of a linked list
void insertAtBeginning(Node** head_ref, int data) {
    Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of a linked list
void insertAtEnd(Node** head_ref, int data) {
    Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    Node* new_node = newNode(data);
    current->next = new_node;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to traverse the linked list
void traverse(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create a linked list of integers
    Node* head = NULL;

    // Insert some nodes at the beginning of the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Insert some nodes at the end of the list
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    // Print the linked list
    printList(head);

    // Traverse the linked list
    traverse(head);

    // Free the memory of the linked list
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}