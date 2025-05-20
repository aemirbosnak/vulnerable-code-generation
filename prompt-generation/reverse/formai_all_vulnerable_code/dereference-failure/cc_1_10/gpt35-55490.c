//FormAI DATASET v1.0 Category: Linked list operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the linked list
void insertAtStart(struct Node** head_ref, int data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // Assign data to the new node
    new_node->data = data;
    new_node->next = (*head_ref);

    // Make the new node the head of the linked list
    (*head_ref) = new_node;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // Assign data to the new node
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        // If the linked list is empty, make the new node the head of the linked list
        *head_ref = new_node;
        return;
    }

    // Traverse the linked list to find the last node
    struct Node* last_node = *head_ref;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }

    // Make the new node the last node in the linked list
    last_node->next = new_node;
}

// Function to display the linked list
void display(struct Node* head) {
    // Traverse the linked list and print the data of each node
    printf("Contents of Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head_ref, int key) {
    // If the head node itself holds the key to be deleted
    if (*head_ref != NULL && (*head_ref)->data == key) {
        struct Node* temp = *head_ref; // Store head node
        *head_ref = (*head_ref)->next; // Change head
        free(temp); // Free old head
        return;
    }

    // Search for the key to be deleted, keep track of the previous node as we need to change 'prev->next'
    struct Node* prev = NULL;
    struct Node* temp = *head_ref;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not found in the linked list
    if (temp == NULL) {
        printf("Key not found in Linked List\n");
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;

    // Free the memory allocated to the node
    free(temp);
}

int main() {
    struct Node* head = NULL; // Initialize the linked list as empty

    // Prompt the user for desired operation
    printf("Enter 1 to insert a node at the beginning of the Linked List\nEnter 2 to insert a node at the end of the Linked List\nEnter 3 to delete a node from the Linked List\nEnter 0 to exit program\n");

    // Loop until the user wants to exit
    int choice = 1;
    while (choice) {
        printf("\nEnter operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0: // Exit program
                printf("Exiting program\n");
                break;
            case 1: // Insert node at beginning of linked list
                printf("Enter data to insert at start of Linked List: ");
                int data;
                scanf("%d", &data);
                insertAtStart(&head, data);
                display(head);
                break;
            case 2: // Insert node at end of linked list
                printf("Enter data to insert at end of Linked List: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                display(head);
                break;
            case 3: // Delete a node from the linked list
                printf("Enter data to delete from Linked List: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                display(head);
                break;
            default: // Invalid choice
                printf("Invalid choice, please try again\n");
                break;
        }
    }

    return 0;
}