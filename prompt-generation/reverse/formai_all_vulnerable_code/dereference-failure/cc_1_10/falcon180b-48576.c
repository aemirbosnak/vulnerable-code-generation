//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to add a node at the end of the list
void push(Node** head_ref, int new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
    } else {
        Node* last = *head_ref;
        while (last->next!= *head_ref) {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = *head_ref;
    }
}

// Function to print the linked list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function to test the linked list implementation
int main() {
    Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);

    printf("Created Linked List: ");
    printList(head);

    return 0;
}