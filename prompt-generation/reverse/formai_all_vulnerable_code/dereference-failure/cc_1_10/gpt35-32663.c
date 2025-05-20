//FormAI DATASET v1.0 Category: Linked list operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

/* Declare structure for linked list node */
typedef struct node {
    int data;
    struct node *next;
} Node;

/* Function to insert a new node at the beginning of a list */
void insertAtBeginning(Node **head_ref, int new_data) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed while inserting node at beginning!");
        exit(1);
    }
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

/* Function to insert a new node at a given position in a list */
void insertAtPosition(Node **head_ref, int new_data, int position) {
    if (position < 1) {
        printf("Invalid position provided for node insertion!");
        exit(1);
    }
    if (position == 1) {
        insertAtBeginning(head_ref, new_data);
        return;
    }
    Node *current_node = *head_ref;
    for (int i = 0; i < position-2; i++) {
        if (current_node == NULL) {
            printf("Position provided for node insertion exceeds number of nodes in list!");
            exit(1);
        }
        current_node = current_node->next;
    }
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed while inserting node at position!");
        exit(1);
    }
    new_node->data = new_data;
    new_node->next = current_node->next;
    current_node->next = new_node;
}

/* Function to delete the first occurrence of a node with given data */
void deleteNode(Node **head_ref, int key) {
    Node *temp_node = *head_ref, *prev_node = NULL;
    if (temp_node != NULL && temp_node->data == key) {
        *head_ref = temp_node->next;
        free(temp_node);
        return;
    }
    while (temp_node != NULL && temp_node->data != key) {
        prev_node = temp_node;
        temp_node = temp_node->next;
    }
    if (temp_node == NULL) {
        printf("Node with given data not found in list!");
        return;
    }
    prev_node->next = temp_node->next;
    free(temp_node);
}

/* Function to print all the nodes in a list */
void printList(Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Main function to demonstrate linked list operations */
int main() {
    Node *head = NULL;
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 5);
    insertAtPosition(&head, 7, 2);
    printf("Original list: ");
    printList(head);
    deleteNode(&head, 5);
    printf("Updated list: ");
    printList(head);
    insertAtPosition(&head, 9, 4);
    printf("Updated list after insertion at position 4: ");
    printList(head);
    return 0;
}