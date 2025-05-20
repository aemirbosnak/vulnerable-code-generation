//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the end of the list
void addNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* last = *head;
    while (last->next!= NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to delete a node with a given value
void deleteNode(struct Node** head, int value) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current!= NULL && current->data!= value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// Function to print the list
void printList(struct Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

// Main function
int main() {
    struct Node* head = NULL;

    // Add some nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);

    // Print the list
    printf("Initial list:");
    printList(head);

    // Delete a node with value 3
    deleteNode(&head, 3);

    // Print the list after deleting node with value 3
    printf("\nList after deleting node with value 3:");
    printList(head);

    // Delete the first node
    deleteNode(&head, 1);

    // Print the list after deleting the first node
    printf("\nList after deleting the first node:");
    printList(head);

    return 0;
}