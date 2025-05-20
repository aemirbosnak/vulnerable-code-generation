//FormAI DATASET v1.0 Category: Linked list operations ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define a structure called Node which is a single element of linked list
struct Node {
    int data;     // Data stored in the node
    struct Node* next;   // Pointer to next node
};

// Initialize the linked list
void initialize(struct Node** head) {
    *head = NULL;   // Initially, the linked list will be empty
}

// Insert an element at the beginning of the linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));  // Create a new node
    newNode->data = data;   // Assign data to the node

    if (*head == NULL) {   // If the linked list is empty
        newNode->next = NULL;   // Assign the next pointer to NULL
        *head = newNode;   // Make the new node as the head of the linked list
    } else {   // If the linked list is not empty
        newNode->next = *head;   // Assign the next pointer to the current head
        *head = newNode;   // Make the new node as the head of the linked list
    }
}

// Delete an element from the beginning of the linked list
void delete(struct Node** head) {
    if (*head == NULL) {   // If the linked list is empty
        printf("Linked List is empty!\n");
    } else {   // If the linked list is not empty
        struct Node* currentNode = *head;   // Assign the current head to a new node
        *head = currentNode->next;   // Make the next node as the new head of the linked list
        free(currentNode);   // Free the memory occupied by the previous head
        printf("Element deleted from the beginning of the linked list.\n");
    }
}

// Display the elements of the linked list
void display(struct Node** head) {
    if (*head == NULL) {   // If the linked list is empty
        printf("Linked List is empty!\n");
    } else {   // If the linked list is not empty
        struct Node* currentNode = *head;   // Assign the current head to a new node

        printf("Elements in the linked list are: ");
        while(currentNode != NULL) {
            printf("%d ", currentNode->data);   // Print the data stored in the current node
            currentNode = currentNode->next;   // Move the pointer to the next node
        }
        printf("\n");
    }
}

int main() {
    struct Node* head;   // Declare a head pointer for the linked list
    int choice, element;

    // Initialize the linked list
    initialize(&head);

    printf("Welcome to Linked List Operations!\n");

    do {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insert(&head, element);   // Call the insert function
                break;
            case 2:
                delete(&head);   // Call the delete function
                break;
            case 3:
                display(&head);   // Call the display function
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}