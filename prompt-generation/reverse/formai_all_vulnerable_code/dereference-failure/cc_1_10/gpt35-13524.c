//FormAI DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node of the linked list
struct node {
    int data;
    struct node* next;
};

// Insert a node at the beginning of the linked list in a distributed system
void insert_at_beginning(struct node** headRef, int data) {
    // Allocate memory for a new node
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    // Assign the data to the new node
    newNode->data = data;

    // Make the next of the new node as the current head
    newNode->next = *headRef;

    // Make the new node as the head of the linked list
    *headRef = newNode;

    // Print the result
    printf("Node with data %d inserted at the beginning.\n", data);
}

// Insert a node at the end of the linked list in a distributed system
void insert_at_end(struct node** headRef, int data) {
    // Allocate memory for a new node
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    // Assign the data to the new node
    newNode->data = data;

    // Set the next of the new node as NULL
    newNode->next = NULL;

    // If the linked list is empty, make the new node as the head
    if (*headRef == NULL) {
        *headRef = newNode;
    }
    // Otherwise, traverse the linked list till the end and insert the new node
    else {
        struct node* current = *headRef;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Print the result
    printf("Node with data %d inserted at the end.\n", data);
}

// Delete a node from the beginning of the linked list in a distributed system
void delete_from_beginning(struct node** headRef) {
    // If the linked list is empty, print an error message
    if (*headRef == NULL) {
        printf("Error: Linked list is empty!\n");
        return;
    }

    // Store the address of the current head
    struct node* temp = *headRef;

    // Make the next node as the head
    *headRef = (*headRef)->next;

    // Free the memory occupied by the original head node
    free(temp);

    // Print the result
    printf("Node deleted from the beginning.\n");
}

// Delete a node from the end of the linked list in a distributed system
void delete_from_end(struct node** headRef) {
    // If the linked list is empty, print an error message
    if (*headRef == NULL) {
        printf("Error: Linked list is empty!\n");
        return;
    }

    // If the linked list has only one node, delete the node
    if ((*headRef)->next == NULL) {
        free(*headRef);
        *headRef = NULL;

        // Print the result
        printf("Node deleted from the end.\n");
        return;
    }

    // Traverse the linked list till the second last node
    struct node* current = *headRef;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // Free the memory occupied by the last node
    free(current->next);

    // Make the second last node as the last node
    current->next = NULL;

    // Print the result
    printf("Node deleted from the end.\n");
}

// Display the linked list in a distributed system
void display(struct node* head) {
    // If the linked list is empty, print an error message
    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    // Traverse the linked list and print the data of each node
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Driver program to test the linked list operations in a distributed system
int main() {
    struct node* head = NULL;

    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);
    display(head);

    insert_at_end(&head, 30);
    display(head);

    delete_from_beginning(&head);
    display(head);

    delete_from_end(&head);
    display(head);

    return 0;
}