//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
void createLinkedList(Node** head);
void appendNode(Node** head, int data);
void printLinkedList(Node* head);
void reverseLinkedList(Node** head);

int main() {
    Node* head = NULL;

    // Create a linked list
    createLinkedList(&head);

    // Print the linked list
    printf("Original linked list:\n");
    printLinkedList(head);

    // Reverse the linked list
    reverseLinkedList(&head);

    // Print the reversed linked list
    printf("\nReversed linked list:\n");
    printLinkedList(head);

    return 0;
}

// Function to create a linked list
void createLinkedList(Node** head) {
    int i, n;

    // Get the number of nodes from the user
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Create the first node
    *head = (Node*) malloc(sizeof(Node));
    (*head)->data = 0;
    (*head)->next = NULL;

    // Append the remaining nodes
    for (i = 1; i < n; i++) {
        appendNode(head, i);
    }
}

// Function to append a node to the end of the linked list
void appendNode(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    Node* temp = *head;

    newNode->data = data;
    newNode->next = NULL;

    // Check if the linked list is empty
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    // Traverse the linked list to find the last node
    while (temp->next!= NULL) {
        temp = temp->next;
    }

    // Append the new node to the end of the linked list
    temp->next = newNode;

    return;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;

    printf("Linked list: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");

    return;
}

// Function to reverse the linked list
void reverseLinkedList(Node** head) {
    Node* prev = NULL;
    Node* curr = *head;

    // Traverse the linked list
    while (curr!= NULL) {
        // Save the next node
        Node* next = curr->next;

        // Reverse the link
        curr->next = prev;

        // Move to the next node
        prev = curr;
        curr = next;
    }

    // Set the new head of the linked list
    *head = prev;

    return;
}