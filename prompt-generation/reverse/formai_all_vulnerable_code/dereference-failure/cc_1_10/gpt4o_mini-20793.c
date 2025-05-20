//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;          // The data stored in the node
    struct Node* next; // Pointer to the next node in the list
};

// Function to create a new node and return its pointer
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Changed head
        free(temp);         // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("Key %d not found in the list.\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free the memory
}

// Function to search for a node in the linked list
struct Node* search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) return current;
        current = current->next;
    }
    return NULL;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL; // Initialize an empty list

    // Insert nodes into the linked list
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    displayList(head); // Display the current list

    // Search for a value
    int searchKey = 20;
    struct Node* foundNode = search(head, searchKey);
    if (foundNode) {
        printf("Found node with value: %d\n", foundNode->data);
    } else {
        printf("Node with value %d not found.\n", searchKey);
    }

    // Delete a node and display the list
    deleteNode(&head, 20);
    displayList(head); // Display after deletion

    // Try deleting a non-existent node
    deleteNode(&head, 100);
    
    // Final display
    displayList(head); // Display final linked list

    // Clean up remaining nodes in the list
    while (head != NULL) {
        deleteNode(&head, head->data);
    }

    return 0;
}