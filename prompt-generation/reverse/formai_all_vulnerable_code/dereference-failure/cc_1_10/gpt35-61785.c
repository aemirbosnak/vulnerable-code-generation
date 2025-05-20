//FormAI DATASET v1.0 Category: Linked list operations ; Style: cheerful
// Hey there! Welcome to my Linked list operations program! 
// Are you ready to add, delete or display some nodes? Let's go!

#include <stdio.h>
#include <stdlib.h>

// Let's define our node structure
struct Node {
    int data; 
    struct Node* next;
};

// Let's declare our function prototypes 
void addNode(struct Node** head_ref, int new_data);
void deleteNode(struct Node** head_ref, int key);
void displayList(struct Node* node);

// Let's write our main function
int main() {

    struct Node* head = NULL; // Initialize an empty list

    printf("Let's add some nodes to our list!\n");
    addNode(&head, 7);
    addNode(&head, 10);
    addNode(&head, 13);
    displayList(head);

    printf("Now let's delete node with value 10\n");
    deleteNode(&head, 10);
    displayList(head);

    printf("Cool! How about we add another node?\n");
    addNode(&head, 5);
    displayList(head);

    return 0; // Program executed successfully
}

// Time to define our functions

// Function to add a node to the list
void addNode(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the new node
    new_node->data = new_data; // Assign the new data to the node
    new_node->next = (*head_ref); // Make the next of the new node as head
    (*head_ref) = new_node; // Move the head to point to the new node
    printf("Added new node with value %d\n", new_data);
}

// Function to delete a node from the list
void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Change head
        free(temp); // Free old head
        printf("Deleted node with value %d\n", key);
        return;
    }

    // Search for the key to be deleted, keep track of the previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("Could not find node with value %d\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
    printf("Deleted node with value %d\n", key);
}

// Function to display the linked list
void displayList(struct Node* node) {
    printf("Our linked list contains: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}