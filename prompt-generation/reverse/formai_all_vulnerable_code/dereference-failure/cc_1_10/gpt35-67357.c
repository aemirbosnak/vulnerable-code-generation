//FormAI DATASET v1.0 Category: Linked list operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node **head, int data) {
    // Allocate memory for new node
    Node *newNode = (Node*)malloc(sizeof(Node));
    // Configure node data and pointer
    newNode->data = data;
    newNode->next = *head;
    // Update the head pointer
    *head = newNode;
    printf("Hooray! %d added at the beginning of the list.\n", data);
}

// Function to insert a node at the end of the list
void insertAtEnd(Node **head, int data) {
    // Allocate memory for new node
    Node *newNode = (Node*)malloc(sizeof(Node));
    // Configure node data and pointer
    newNode->data = data;
    newNode->next = NULL;
    // If list is empty, update the head pointer
    if(*head == NULL) {
        *head = newNode;
        printf("Yay! %d added at the end of the list.\n", data);
        return;
    }
    // Traverse to the last node and append new node
    Node *temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Hooray! %d added at the end of the list.\n", data);
}

// Function to delete a node from the list
void deleteNode(Node **head, int key) {
    // If list is empty, return
    if(*head == NULL) {
        printf("Uh oh! List is empty.\n");
        return;
    }
    // If node to be deleted is the head node
    if((*head)->data == key) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Yay! %d deleted from the list.\n", key);
        return;
    }
    // Traverse to node before the one to be deleted
    Node *prev = *head;
    Node *curr = prev->next;
    while(curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    // If node to be deleted is not present in the list
    if(curr == NULL) {
        printf("Uh oh! %d not found in the list.\n", key);
        return;
    }
    // Else delete the node
    prev->next = curr->next;
    free(curr);
    printf("Hooray! %d deleted from the list.\n", key);
}

// Function to display the entire list
void displayList(Node *head) {
    // If list is empty, return
    if(head == NULL) {
        printf("Uh oh! List is empty.\n");
        return;
    }
    printf("Here's the entire list:\n");
    // Traverse the list and print each node data
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function to test the linked list operations
int main() {
    // Declare a head pointer for the list and initialize it as NULL
    Node *head = NULL;
    // Insert some nodes
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    // Display the list
    displayList(head);
    // Delete some nodes
    deleteNode(&head, 15);
    deleteNode(&head, 5);
    // Display the updated list
    displayList(head);
    // Insert more nodes
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 1);
    // Display the final list
    displayList(head);
    // Free all memory allocations
    Node *temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}