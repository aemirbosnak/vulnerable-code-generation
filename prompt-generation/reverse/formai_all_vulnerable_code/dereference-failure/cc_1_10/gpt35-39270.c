//FormAI DATASET v1.0 Category: Linked list operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Node structure for Linked List
struct node {
    int data;
    struct node* next;
};

// Function to insert a node at the beginning of the Linked List
void insertAtBeginning(struct node** head_ref, int new_data) {
    // Allocate memory for new node
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    // Assign data to new node
    new_node->data = new_data;

    // Make new node as head
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to insert a node after a given node
void insertAfterNode(struct node* prev_node, int new_data) {
    // Check if prev_node is NULL
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL!\n");
        return;
    }

    // Allocate memory for new node
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    // Assign data to new node
    new_node->data = new_data;

    // Make new node as next of prev_node
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to insert a node at the end of the Linked List
void insertAtEnd(struct node** head_ref, int new_data) {
    // Allocate memory for new node
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    // Assign data to new node and make its next as NULL
    new_node->data = new_data;
    new_node->next = NULL;

    // If Linked List is empty, make new node as head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Traverse to last node and make its next as new node
    struct node* last_node = *head_ref;
    while (last_node->next != NULL)
        last_node = last_node->next;

    last_node->next = new_node;
}

// Function to delete a node with given key from Linked List
void deleteNode(struct node** head_ref, int key) {
    // If Linked List is empty, return
    if (*head_ref == NULL)
        return;

    // If head node contains the key to be deleted
    if ((*head_ref)->data == key) {
        struct node* temp = *head_ref;
        *head_ref = (*head_ref)->next;   // Change head to next node
        free(temp);                 // Free memory of head node
        return;
    }

    // Find the node with the given key
    struct node* curr_node = *head_ref;
    struct node* prev_node = NULL;
    while (curr_node != NULL && curr_node->data != key) {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    // If key is not present in Linked List
    if (curr_node == NULL) {
        printf("Key not found in Linked List!\n");
        return;
    }

    // Else delete the node and free memory
    prev_node->next = curr_node->next;
    free(curr_node);
}

// Function to print the Linked List
void printList(struct node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Initialize an empty Linked List
    struct node* head = NULL;

    // Insert some nodes at the beginning of the Linked List
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);

    // Insert a node after a given node
    struct node* temp_node = head->next;
    insertAfterNode(temp_node, 6);

    // Insert some nodes at the end of the Linked List
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 8);

    // Print the Linked List
    printList(head);

    // Delete a node from the Linked List
    deleteNode(&head, 6);

    // Print the Linked List again
    printList(head);

    return 0;
}