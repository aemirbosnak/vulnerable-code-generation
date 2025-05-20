//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct Node {
    int data;              // Data of the node
    struct Node* next;     // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the new node
    newNode->data = value;      // Set the data
    newNode->next = NULL;       // Set next to NULL
    return newNode;             // Return the newly created node
}

// Function to append a node at the end of the linked list
void appendNode(struct Node** headRef, int value) {
    struct Node* newNode = createNode(value);  // Create a new node
    if (*headRef == NULL) {                     // If the list is empty
        *headRef = newNode;                     // The new node is now the head
        return;
    }
    
    struct Node* temp = *headRef;               // Start with the head
    while (temp->next != NULL) {                 // Traverse to the last node
        temp = temp->next;                       // Go to the next node
    }
    temp->next = newNode;                        // Link the new node at the end
}

// Function to delete a node by value
void deleteNode(struct Node** headRef, int value) {
    struct Node* temp = *headRef;                // Start from the head
    struct Node* prev = NULL;                     // To keep track of the previous node
    
    // Check if the head node itself holds the key
    if (temp != NULL && temp->data == value) {
        *headRef = temp->next;                    // Change head
        free(temp);                               // Free previous head
        return;
    }
    
    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != value) {
        prev = temp;                              // Store the previous node
        temp = temp->next;                        // Move to the next node
    }
    
    // If the key was not present in the linked list
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }
    
    // Unlink the node from linked list
    prev->next = temp->next;                     
    free(temp);                                  // Free memory
}

// Function to display the linked list
void displayList(struct Node* node) {
    if (node == NULL) {
        printf("The list is empty!\n");
        return;
    }
    
    printf("Current Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);            // Print the data and link
        node = node->next;                        // Move to the next node
    }
    printf("NULL\n");                             // End of the list
}

// Main function to run the linked list operations
int main() {
    struct Node* head = NULL;  // Initialize the head of the list

    // Exciting operations to perform on our linked list!
    printf("Let's create a thrilling linked list!\n");
    
    // Appending some nodes
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);
    
    // Displaying the list
    displayList(head);

    // Deleting a node
    printf("Removing 20 from the list...\n");
    deleteNode(&head, 20);
    displayList(head);

    // Attempting to delete a non-existing node
    printf("Trying to remove 99 from the list...\n");
    deleteNode(&head, 99);
    displayList(head);

    // Final cleanup - let’s remove all nodes
    printf("Time to clean up before we finish!\n");
    while (head != NULL) {
        deleteNode(&head, head->data);
    }

    displayList(head);  // Ensure the list is empty
    printf("All nodes have been removed. Goodbye!\n");
    
    return 0; // Finish the program 
}