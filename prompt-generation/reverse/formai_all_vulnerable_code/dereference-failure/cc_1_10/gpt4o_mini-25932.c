//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
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

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;  // Link the new node to the old head
    *head = newNode;        // Update the head pointer
    printf("Inserted %d at the beginning of the list.\n", data);
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // If list is empty, make new node head
        printf("Inserted %d at the end of the list.\n", data);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next; // Move to the end of the list
    }
    temp->next = newNode; // Link the last node with new node
    printf("Inserted %d at the end of the list.\n", data);
}

// Function to delete a node with a given key
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Change head
        free(temp);         // Free the old head
        printf("Deleted %d from the list.\n", key);
        return;
    }

    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next; // Move to next node
    }

    // If key was not present in the list
    if (temp == NULL) {
        printf("%d not found in the list.\n", key);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free memory
    printf("Deleted %d from the list.\n", key);
}

// Function to print the linked list
void printList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the linked list operations
int main() {
    struct Node* head = NULL; // Initialize the head of the linked list

    // Energy rising as we perform operations!
    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    printList(head);

    deleteNode(&head, 20);
    deleteNode(&head, 30);
    
    printList(head);

    deleteNode(&head, 100); // Attempt to delete a non-existing node

    insertAtEnd(&head, 60);
    insertAtBeginning(&head, 70);
    
    printList(head);

    // Clean up remaining nodes before exiting
    while (head != NULL) {
        deleteNode(&head, head->data); // Delete each element
    }

    printf("All nodes deleted, exiting program!\n");
    return 0;
}