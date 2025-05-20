//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node in the linked list
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
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
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

// Function to delete a node by value
void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If head node itself holds the value to be deleted
    if (temp != NULL && temp->data == value) {
        *head = temp->next; // Change head
        free(temp);         // Free old head
        return;
    }

    // Search for the value to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If value was not present in the linked list
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to search for a node by value
struct Node* searchNode(struct Node* head, int value) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current; // Value found
        }
        current = current->next;
    }
    return NULL; // Value not found
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

// Main function to illustrate linked list operations
int main() {
    struct Node* head = NULL;

    // Inserting nodes into the list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 2);

    printf("Linked List after insertions:\n");
    displayList(head);

    // Searching for a node
    int searchValue = 20;
    struct Node* foundNode = searchNode(head, searchValue);
    if (foundNode) {
        printf("Value %d found in the list.\n", searchValue);
    } else {
        printf("Value %d not found in the list.\n", searchValue);
    }

    // Delete a node
    int deleteValue = 10;
    printf("Deleting value: %d\n", deleteValue);
    deleteNode(&head, deleteValue);
    
    printf("Linked List after deletion:\n");
    displayList(head);

    // Clean up memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}