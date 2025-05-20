//FormAI DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Initialize the list node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Initialize a global head pointer 
Node* head = NULL;

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    // Check if the new node can be created
    if (newNode != NULL) {
        newNode->data = val;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insert_beginning(int val) {
    Node* newNode = createNode(val);
    if (newNode != NULL) {
        newNode->next = head;
        head = newNode;
    }
}

// Function to delete a node from the linked list
void delete_node(int val) {
    Node* curr = head;
    // Check if the node to be deleted is the first node
    if (curr != NULL && curr->data == val) {
        head = head->next;
        free(curr);
        return;
    }
    Node* prev = NULL;
    // Traverse the linked list to find the node to be deleted
    while (curr != NULL && curr->data != val) {
        prev = curr;
        curr = curr->next;
    }
    // If the node is not found
    if (curr == NULL) {
        printf("%d not found in the list.\n", val);
        return;
    }
    // If the node is found and is not the first node
    prev->next = curr->next;
    free(curr);
}

int main() {
    // Initialize some values and perform some memory management operations
    insert_beginning(5);
    insert_beginning(3);
    insert_beginning(7);
    insert_beginning(2);
    delete_node(3);
    Node* curr = head;
    // Traverse and print the linked list
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    return 0;
}