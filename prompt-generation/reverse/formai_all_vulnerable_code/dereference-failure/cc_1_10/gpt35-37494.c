//FormAI DATASET v1.0 Category: Linked list operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node* next;
};

// Initialize the head node
struct node* head = NULL;

// Function to insert a new node at the beginning of the linked list
void insert(int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node)); // allocate memory for new node
    new_node->data = new_data; // assign data to the new node
    new_node->next = head; // make new node point to the head
    head = new_node; // update head to the new node
}

// Function to delete a node from the linked list
void delete(int key) {
    struct node* temp = head; // temporary node to traverse the linked list
    struct node* prev = NULL; // previous node to the node to be deleted

    // Traverse the linked list
    while (temp != NULL && temp->data != key) {
        prev = temp; // update the previous node
        temp = temp->next; // move to the next node
    }

    // If the key was not found
    if (temp == NULL) return;

    // If the key is found at the beginning of the linked list
    if (temp == head) {
        head = temp->next; // update head
    }

    // If the key is found in the middle or end of the linked list
    else {
        prev->next = temp->next; // link the previous node with the next node of the node to be deleted
    }
    free(temp); // free memory of the deleted node
}

// Function to display the linked list
void display() {
    struct node* temp = head; // temporary node to traverse the linked list

    // Traverse the linked list
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Insert nodes
    insert(5);
    insert(10);
    insert(15);
    insert(20);
    insert(25);
    insert(30);

    // Display the linked list
    printf("Linked list before deletion: ");
    display();

    // Delete nodes
    delete(10);
    delete(20);
    delete(30);

    // Display the linked list
    printf("Linked list after deletion: ");
    display();

    return 0;
}