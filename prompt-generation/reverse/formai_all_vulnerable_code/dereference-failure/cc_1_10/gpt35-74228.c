//FormAI DATASET v1.0 Category: Data structures visualization ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Print the current state of the linked list
void printList(Node* head) {
    printf("Current List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Initialize the linked list
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // Print the initial state of the linked list
    printList(head);

    // Insert a new node at the end of the list
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = 4;
    new_node->next = NULL;

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;

    // Print the updated state of the linked list
    printList(head);

    // Delete the second node from the list
    Node* temp = head->next;
    head->next = temp->next;
    free(temp);

    // Print the final state of the linked list
    printList(head);

    return 0;
}