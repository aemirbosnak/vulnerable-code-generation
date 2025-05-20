//FormAI DATASET v1.0 Category: Data structures visualization ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Define the structure
struct node {
    int value;
    struct node* next;
};

// Create a function to add a new node to the list
void insert(struct node** head_ref, int new_value) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->value = new_value;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Create a function to print out the list
void print_list(struct node* node){
    printf("List: ");
    while (node != NULL){
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

// Create a function to delete a specific node from the list
void delete_node(struct node **head_ref, int key){
    struct node* temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->value == key){
        *head_ref = temp->next; // Change head
        free(temp);            // Free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->value != key){
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp);  // Free memory
}

int main() {
    // Initialize the linked list
    struct node* head = NULL;

    // Insert some numbers into the list
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    // Print out the original list
    print_list(head);

    // Delete a specific node (value 3 in this example)
    delete_node(&head, 3);

    // Print out the modified list
    print_list(head);

    // Free the memory used by the linked list
    struct node* current = head;
    struct node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    // Set the head of the linked list to NULL
    head = NULL;

    return 0;
}