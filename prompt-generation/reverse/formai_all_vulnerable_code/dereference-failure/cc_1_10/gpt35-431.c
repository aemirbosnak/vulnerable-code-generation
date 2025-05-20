//FormAI DATASET v1.0 Category: Linked list operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define a structure for each node of the linked list
struct node {
    int data;
    struct node *next;
};

// Function to insert a new node at the beginning of the linked list
void insert_first(struct node **head, int data) {
    // Allocate memory for a new node
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    
    // Set the data and next fields of the new node
    new_node->data = data;
    new_node->next = *head;
    
    // Update the head of the linked list
    *head = new_node;
}

// Function to delete a node from the linked list
void delete_node(struct node **head, int key) {
    // Store the head node
    struct node* current_node = *head;
    struct node* prev_node = NULL;
    
    // Traverse the linked list until the key is found
    while (current_node != NULL && current_node->data != key) {
        prev_node = current_node;
        current_node = current_node->next;
    }
    
    // If the key is not found in the linked list
    if (current_node == NULL) {
        printf("Key %d not found in the linked list.\n", key);
        return;
    }
    
    // If the key is found in the linked list
    if (prev_node == NULL) {
        *head = current_node->next;
    } else {
        prev_node->next = current_node->next;
    }
    
    // Free the memory of the deleted node
    free(current_node);
}

// Function to print the linked list
void print_list(struct node *head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the memory of the linked list
void free_list(struct node **head) {
    struct node* current_node = *head;
    struct node* next_node;
    
    while (current_node != NULL) {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    
    *head = NULL;
}

int main() {
    struct node* head = NULL;
    
    // Insert some nodes into the linked list
    insert_first(&head, 5);
    insert_first(&head, 10);
    insert_first(&head, 15);
    insert_first(&head, 20);
    insert_first(&head, 25);
    
    // Print the linked list
    print_list(head);
    
    // Delete some nodes from the linked list
    delete_node(&head, 15);
    delete_node(&head, 10);
    
    // Print the linked list again
    print_list(head);
    
    // Free the memory of the linked list
    free_list(&head);
    
    return 0;
}