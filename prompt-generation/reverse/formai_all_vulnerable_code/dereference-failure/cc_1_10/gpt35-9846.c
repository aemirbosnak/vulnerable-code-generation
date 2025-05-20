//FormAI DATASET v1.0 Category: Linked list operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the node struct
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define some helper functions

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert a new node at the beginning of the list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert a new node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* current = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Delete a node with the given data
void deleteNode(Node** head, int data) {
    Node* current = *head;
    Node* prev = NULL;
    while (current != NULL) {
        if (current->data == data) {
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

// Reverse the list
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Print the list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insert some nodes at the beginning of the list
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // Print the list
    printf("List: ");
    printList(head);

    // Insert some nodes at the end of the list
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 10);

    // Print the list
    printf("List: ");
    printList(head);

    // Delete a node
    deleteNode(&head, 5);

    // Print the list
    printf("List: ");
    printList(head);

    // Reverse the list
    reverseList(&head);

    // Print the list
    printf("Reversed List: ");
    printList(head);

    return 0;
}