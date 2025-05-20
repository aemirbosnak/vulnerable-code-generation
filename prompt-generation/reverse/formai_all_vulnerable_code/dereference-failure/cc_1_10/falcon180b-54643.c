//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure definition
typedef struct node {
    char data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* newNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void push(Node** head_ref, char new_data) {
    Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to print the linked list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%c ", node->data);
        node = node->next;
    }
}

// Function to search for a character in the linked list
Node* search(Node* head, char key) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return NULL;
}

// Main function
int main() {
    Node* head = NULL;

    // Insert elements into the linked list
    push(&head, 'a');
    push(&head, 'b');
    push(&head, 'c');
    push(&head, 'd');

    // Print the linked list
    printf("Linked List: ");
    printList(head);
    printf("\n");

    // Search for a character in the linked list
    char key = 'b';
    Node* result = search(head, key);

    // Check if the character was found
    if (result!= NULL)
        printf("%c found in the linked list\n", key);
    else
        printf("%c not found in the linked list\n", key);

    return 0;
}