//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node to the end of the list
void addNode(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to delete a node from the list
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->data == data) {
        *head = (*head)->next;
        free((*head));
    } else {
        struct Node* current = *head;
        while (current->next!= NULL && current->next->data!= data) {
            current = current->next;
        }
        if (current->next == NULL) {
            return;
        }
        current->next = current->next->next;
        free(current->next);
    }
}

// Function to search for a specific node in the list
struct Node* searchNode(struct Node* head, int data) {
    struct Node* current = head;
    while (current!= NULL && current->data!= data) {
        current = current->next;
    }
    return current;
}

int main() {
    // Create a linked list
    struct Node* head = NULL;
    addNode(&head, 5);
    addNode(&head, 10);
    addNode(&head, 15);
    addNode(&head, 20);

    // Search for a node
    printf("Node found at index %d\n", searchNode(head, 15)->data);

    // Delete a node
    deleteNode(&head, 10);

    // Search for a node after deletion
    printf("Node found at index %d\n", searchNode(head, 15)->data);

    return 0;
}