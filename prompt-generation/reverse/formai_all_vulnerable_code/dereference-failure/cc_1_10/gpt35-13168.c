//FormAI DATASET v1.0 Category: Linked list operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define the linked list node
struct node {
    int data;
    struct node *next;
};

// Define the head of the linked list
struct node *head = NULL;

// Function to insert a new node at the beginning of the linked list
void insert_at_beginning(int data) {
    // Create a new node
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    printf("Node inserted at the beginning.\n");
}

// Function to insert a new node at the end of the linked list
void insert_at_end(int data) {
    // Create a new node
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        // Traverse to the end of the linked list
        struct node *last_node = head;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
    printf("Node inserted at the end.\n");
}

// Function to display all nodes in the linked list
void display_all() {
    if (head == NULL) {
        printf("Linked list is empty.\n");
    } else {
        // Traverse the linked list and print each node
        struct node *current_node = head;
        printf("Linked list nodes: ");
        while (current_node != NULL) {
            printf("%d ", current_node->data);
            current_node = current_node->next;
        }
        printf("\n");
    }
}

// Function to delete the first node with a given data value
void delete_node(int data) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
    } else {
        // Traverse the linked list and find the node with the given data value
        struct node *current_node = head, *prev_node = NULL;
        while (current_node != NULL && current_node->data != data) {
            prev_node = current_node;
            current_node = current_node->next;
        }
        if (current_node == NULL) {
            printf("Node with data value %d not found.\n", data);
        } else {
            // Remove the node from the linked list
            if (prev_node == NULL) {
                head = current_node->next;
            } else {
                prev_node->next = current_node->next;
            }
            free(current_node);
            printf("Node with data value %d deleted.\n", data);
        }
    }
}

int main() {
    while(1) {
        int choice, data;
        printf("\nLinked List operations: \n");
        printf("1. Insert node at the beginning\n");
        printf("2. Insert node at the end\n");
        printf("3. Display all nodes in the linked list\n");
        printf("4. Delete node with a given data value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: // Insert node at the beginning
                printf("Enter the data value: ");
                scanf("%d", &data);
                insert_at_beginning(data);
                break;
            case 2: // Insert node at the end
                printf("Enter the data value: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 3: // Display all nodes
                display_all();
                break;
            case 4: // Delete node
                printf("Enter the data value to delete: ");
                scanf("%d", &data);
                delete_node(data);
                break;
            case 5: // Exit
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}