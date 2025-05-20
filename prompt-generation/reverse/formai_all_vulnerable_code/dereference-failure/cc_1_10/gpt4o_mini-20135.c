//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    // If the linked list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Otherwise, traverse to the end of the list and insert the new node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head, *prev = NULL;
    
    // If the head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Change head
        free(temp); // Free old head
        return;
    }
    
    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    // If key was not present in linked list
    if (temp == NULL) return;
    
    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to display the linked list
void displayList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL;

    // Insertion operations
    printf("Inserting 10, 20, and 30 at the beginning:\n");
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);
    displayList(head);
    
    printf("Inserting 40 and 50 at the end:\n");
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    displayList(head);
    
    // Deletion operation
    printf("Deleting 20 from the list:\n");
    deleteNode(&head, 20);
    displayList(head);
    
    // Try to delete a node not in the list
    printf("Trying to delete 100 from the list (not present):\n");
    deleteNode(&head, 100);
    displayList(head);
    
    // Final linked list state
    printf("Final state of the linked list:\n");
    displayList(head);

    // Free up the memory allocated for the nodes in the linked list
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}