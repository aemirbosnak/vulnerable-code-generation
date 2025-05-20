//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = (*head);
    (*head) = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = (*head);
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete a node from the list
void deleteNode(struct Node** head, int data) {
    struct Node* current = (*head);
    struct Node* previous = NULL;

    if (current!= NULL && current->data == data) {
        *head = current->next;
        free(current);
        return;
    }

    while (current!= NULL && current->data!= data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    previous->next = current->next;
    free(current);
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Insert nodes at the end
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Delete node with data 3
    deleteNode(&head, 3);

    // Print the linked list after deletion
    printf("\nLinked List after deletion: ");
    printList(head);

    return 0;
}