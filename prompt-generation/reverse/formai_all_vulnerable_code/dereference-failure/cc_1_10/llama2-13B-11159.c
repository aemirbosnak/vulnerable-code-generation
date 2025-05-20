//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold a node in a linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node into a linked list
void insertNode(Node** head_ref, int data) {
    Node* new_node = newNode(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        Node* current = *head_ref;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to print the linked list
void printList(Node* head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    printf("The list is: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insert some nodes into the list
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Print the list
    printList(head);

    // Free the nodes
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}