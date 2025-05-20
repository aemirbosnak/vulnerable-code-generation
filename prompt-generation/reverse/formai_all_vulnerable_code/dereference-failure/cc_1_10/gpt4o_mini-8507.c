//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
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

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning of the list.\n", data);
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d at the end of the list.\n", data);
        return;
    }
    struct Node* lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    printf("Inserted %d at the end of the list.\n", data);
}

// Function to delete a node by value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Change head
        free(temp); // Free old head
        printf("Deleted %d from the list.\n", key);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
    printf("Deleted %d from the list.\n", key);
}

// Function to search for an element
int search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return 1; // Element found
        }
        current = current->next;
    }
    return 0; // Element not found
}

// Function to display the list
void displayList(struct Node* node) {
    if (node == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to test the linked list operations
int main() {
    struct Node* head = NULL;

    // Inserting elements
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    displayList(head);

    // Searching for elements
    int searchKey = 30;
    if (search(head, searchKey)) {
        printf("Element %d found in the list.\n", searchKey);
    } else {
        printf("Element %d not found in the list.\n", searchKey);
    }

    // Deleting elements
    deleteNode(&head, 20);
    displayList(head);

    deleteNode(&head, 100); // Try to delete a non-existing element
    deleteNode(&head, 30);
    displayList(head);

    // Cleanup remaining nodes
    while (head != NULL) {
        deleteNode(&head, head->data);
    }
    
    return 0;
}