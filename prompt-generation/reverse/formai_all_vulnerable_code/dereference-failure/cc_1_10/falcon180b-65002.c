//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function declarations
void addNode(struct Node** head, int data);
void deleteNode(struct Node** head, int data);
void printList(struct Node* head);

int main() {
    struct Node* head = NULL;

    // Add nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);

    // Print the list
    printf("List after adding nodes:\n");
    printList(head);

    // Delete a node from the list
    deleteNode(&head, 2);

    // Print the list again
    printf("\nList after deleting node with data 2:\n");
    printList(head);

    return 0;
}

// Function to add a node to the list
void addNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node from the list
void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }

    temp->next = temp->next->next;
    free(temp->next);
}

// Function to print the list
void printList(struct Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}