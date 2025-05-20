//FormAI DATASET v1.0 Category: Linked list operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int val; // Data value
    struct Node* next; // Pointer to the next node
};

// Define the head node of the list
struct Node* head = NULL;

// Function to insert a node at the beginning of the list
void insert(int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); // Allocate space for the new node

    if (newNode == NULL) { // If memory allocation unsuccessful
        printf("Error: Unable to allocate memory for new node\n");
        return;
    }

    newNode->val = val; // Set the new node's data value
    newNode->next = head; // Set the new node's next pointer to point to the current head node
    head = newNode; // Set the head node to be the new node
}

// Function to print the list
void printList() {
    struct Node* currentNode = head; // Initialize a current node pointer to the head node

    printf("List: ");
    while (currentNode != NULL) { // Loop until end of list
        printf("%d ", currentNode->val); // Print the current node's data value
        currentNode = currentNode->next; // Move to the next node
    }
    printf("\n");
}

// Function to delete a node from the list
void delete(int val) {
    struct Node* currentNode = head; // Initialize a current node pointer to the head node
    struct Node* prevNode = NULL; // Initialize a previous node pointer to NULL

    // Loop until either end of list or node with value val is found
    while (currentNode != NULL && currentNode->val != val) {
        prevNode = currentNode; // Set the previous node pointer to the current node
        currentNode = currentNode->next; // Move to the next node
    }

    if (currentNode == NULL) { // If end of list reached, node with value val not found
        printf("Error: Node with value %d not found in list\n", val);
        return;
    }

    if (prevNode == NULL) { // If the node to be deleted is the head node
        head = currentNode->next; // Set the head node to be the next node
    } else {
        prevNode->next = currentNode->next; // Set the previous node's next pointer to skip over the current node
    }

    free(currentNode); // Free the memory allocated for the current node
}

int main() {
    // Test the linked list operations
    printf("Let's create our own linked list!\n");
    printf("Inserting 3, 7, and 10 into the list ...\n");
    insert(3);
    insert(7);
    insert(10);
    printList();

    printf("Deleting 7 from the list ...\n");
    delete(7);
    printList();

    printf("Deleting 4 from the list ...\n");
    delete(4);

    return 0;
}