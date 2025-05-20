//FormAI DATASET v1.0 Category: Linked list operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a linked list node
struct node {
    int data;
    struct node* next;
};

// Initialize the head of the linked list to be NULL
struct node* head = NULL;

// Function to insert a new node at the beginning of the linked list
void insert_at_beginning(int value) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;
    printf("%d has been inserted at the beginning of the linked list.\n", value);
}

// Function to insert a new node at the end of the linked list
void insert_at_end(int value) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        printf("%d has been inserted at the end of the linked list.\n", value);
        return;
    }
    struct node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    printf("%d has been inserted at the end of the linked list.\n", value);
}

// Function to delete a node of a given value from the linked list
void delete_node(int value) {
    if (head == NULL) {
        printf("The linked list is already empty, nothing to delete.\n");
        return;
    }
    struct node* curr_node = head;
    struct node* prev_node = NULL;
    while (curr_node != NULL && curr_node->data != value) {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    if (curr_node == NULL) {
        printf("%d was not found in the linked list, nothing to delete.\n", value);
        return;
    }
    if (prev_node == NULL) {
        head = curr_node->next;
    } else {
        prev_node->next = curr_node->next;
    }
    printf("%d has been deleted from the linked list.\n", value);
    free(curr_node);
}

// Function to display the contents of the linked list
void display() {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    struct node* ptr = head;
    printf("The linked list is: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Main function to test the linked list operations
int main() {
    int choice, value;
    do {
        printf("Select an operation:\n");
        printf("1. Insert a new node at the beginning of the linked list\n");
        printf("2. Insert a new node at the end of the linked list\n");
        printf("3. Delete a node from the linked list\n");
        printf("4. Display the contents of the linked list\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a value to insert at the beginning: ");
                scanf("%d", &value);
                insert_at_beginning(value);
                break;
            case 2:
                printf("Enter a value to insert at the end: ");
                scanf("%d", &value);
                insert_at_end(value);
                break;
            case 3:
                printf("Enter a value to delete: ");
                scanf("%d", &value);
                delete_node(value);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please select a valid operation.\n");
        }
    } while (choice != 5);
    return 0;
}