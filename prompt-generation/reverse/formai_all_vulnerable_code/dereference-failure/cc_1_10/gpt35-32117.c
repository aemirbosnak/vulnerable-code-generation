//FormAI DATASET v1.0 Category: Data structures visualization ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for a linked list
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node to the beginning of the linked list
void addToBeginning(struct node **head, int data) {
    struct node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to add a new node to the end of the linked list
void addToEnd(struct node **head, int data) {
    struct node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete a node from the linked list by value
void deleteNode(struct node **head, int value) {
    struct node *prev = NULL;
    struct node *current = *head;
    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Function to print the linked list
void printList(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;

    // Add nodes to the linked list
    addToEnd(&head, 5);
    addToBeginning(&head, 2);
    addToEnd(&head, 8);
    addToBeginning(&head, 1);
    addToEnd(&head, 9);
    addToBeginning(&head, 4);
    addToEnd(&head, 3);

    // Print the linked list
    printf("Linked List:\n");
    printList(head);

    // Delete nodes from the linked list
    deleteNode(&head, 1);
    deleteNode(&head, 9);
    deleteNode(&head, 5);

    // Print the linked list again
    printf("Linked List after deleting nodes with values 1, 9, and 5:\n");
    printList(head);

    return 0;
}