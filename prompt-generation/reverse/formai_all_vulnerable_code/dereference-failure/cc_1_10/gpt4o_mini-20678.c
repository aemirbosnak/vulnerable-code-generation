//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
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

// Function to delete a node by value
void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head, *prev = NULL;

    if (temp != NULL && temp->data == value) {
        *head = temp->next; 
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to search for a value in the list
int searchNode(struct Node* head, int value) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL;

    // Inserting nodes into the list
    insertEnd(&head, 5);
    insertEnd(&head, 10);
    insertEnd(&head, 15);
    insertEnd(&head, 20);

    printf("Initial List: ");
    printList(head);

    // Searching for a node
    int searchValue = 15;
    if (searchNode(head, searchValue)) {
        printf("Found %d in the list.\n", searchValue);
    } else {
        printf("%d not found in the list.\n", searchValue);
    }

    // Deleting a node
    printf("Deleting node with value 10.\n");
    deleteNode(&head, 10);
    printf("List after deletion: ");
    printList(head);

    // Trying to delete a non-existent node
    printf("Attempting to delete node with value 30.\n");
    deleteNode(&head, 30);
    printf("List remains: ");
    printList(head);

    // More insertions
    insertEnd(&head, 25);
    insertEnd(&head, 30);
    printf("List after adding more elements: ");
    printList(head);

    // Final cleanup
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}