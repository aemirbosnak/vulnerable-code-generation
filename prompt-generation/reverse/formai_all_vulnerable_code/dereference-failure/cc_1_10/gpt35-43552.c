//FormAI DATASET v1.0 Category: Linked list operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Define the structure for our linked list node
struct Node {
    int data;
    struct Node *next;
};

// Define a function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node **head, int value) {
    // Allocate memory for the new node
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    // Set the value of the new node
    newNode->data = value;
    // Set the next pointer of the new node to the current head of the list
    newNode->next = *head;
    // Set the head of the list to the new node
    *head = newNode;
}

// Define a function to insert a node at the end of the linked list
void insertAtEnd(struct Node **head, int value) {
    // Allocate memory for the new node
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    // Set the value of the new node
    newNode->data = value;
    // Set the next pointer of the new node to NULL
    newNode->next = NULL;

    // Check if the list is empty
    if (*head == NULL) {
        // If the list is empty, set the head to the new node
        *head = newNode;
    } else {
        // If the list is not empty, traverse to the end of the list
        struct Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        // Set the next pointer of the last node to the new node
        current->next = newNode;
    }
}

// Define a function to delete a node from the linked list
void deleteNode(struct Node **head, int value) {
    // Check if the list is empty
    if (*head == NULL) {
        return;
    }
    // If the first node needs to be deleted
    if ((*head)->data == value) {
        // Set the head of the list to the second node
        *head = (*head)->next;
        return;
    }
    // Traverse the list to find the node to be deleted
    struct Node *current = *head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }
    // Check if the node was found
    if (current->next == NULL) {
        return;
    }
    // Set the next pointer of the previous node to the next node
    current->next = current->next->next;
}

// Define a function to print the linked list
void printList(struct Node *head) {
    // Traverse the list and print the data of each node
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Define a function to reverse the linked list using recursion
void reverseList(struct Node **head) {
    // Check if the list is empty or has only one node
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    // Reverse the rest of the list
    reverseList(&((*head)->next));
    // Set the next pointer of the current node to the previous node
    (*head)->next->next = *head;
    // Set the next pointer of the head to NULL
    (*head)->next = NULL;
    // Set the head to the last node
    *head = (*head)->next;
}

int main() {
    // Declare and initialize the head of the linked list
    struct Node *head = NULL;

    // Insert nodes at the beginning of the list
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    // Print the list
    printf("List after inserting nodes at the beginning: ");
    printList(head);

    // Insert nodes at the end of the list
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    // Print the list
    printf("List after inserting nodes at the end: ");
    printList(head);

    // Delete a node from the list
    deleteNode(&head, 20);

    // Print the list
    printf("List after deleting a node: ");
    printList(head);

    // Reverse the list
    reverseList(&head);

    // Print the list
    printf("List after reversing: ");
    printList(head);

    return 0;
}