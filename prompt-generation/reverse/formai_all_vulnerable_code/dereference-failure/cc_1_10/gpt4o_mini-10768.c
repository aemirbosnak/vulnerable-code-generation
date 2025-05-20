//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
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

// Function to insert a new node at the end of the list
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

// Function to delete a node with a given value
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        return; // List is empty
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == value) {
        *head = temp->next; // Changed head
        free(temp); // Free old head
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not present in the list
    if (temp == NULL) {
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free the memory
}

// Function to display the linked list
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

// Function to free the entire linked list
void freeList(struct Node* node) {
    struct Node* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL; // Initialize the head of the list
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Delete a node\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;

            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;

            case 3:
                displayList(head);
                break;

            case 4:
                printf("Exiting...\n");
                freeList(head); // Free the list before exiting
                break;

            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}