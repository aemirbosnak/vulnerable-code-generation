//FormAI DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define a node in the Linked List
typedef struct node {
    int data;
    struct node *next;
} Node;

// Create a new node
Node* create_node(int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the Linked List
void insert_beginning(Node **head, int data) {
    // Create a new node
    Node *new_node = create_node(data);
    
    // Set the new node's next to the current head
    new_node->next = *head;
    
    // Set the head to the new node
    *head = new_node;
}

// Insert a node at the end of the Linked List
void insert_end(Node **head, int data) {
    // Create a new node
    Node *new_node = create_node(data);
    
    if (*head == NULL) {
        // If the Linked List is empty, set the head to the new node
        *head = new_node;
        return;
    }
    
    // Traverse to the end of the Linked List
    Node *curr_node = *head;
    while (curr_node->next != NULL) {
        curr_node = curr_node->next;
    }
    
    // Set the last node's next to the new node
    curr_node->next = new_node;
}

// Delete a node with a specific value from the Linked List
void delete(Node **head, int data) {
    Node *curr_node = *head;
    Node *prev_node = NULL;
    
    // Traverse the Linked List until the desired value is found
    while (curr_node != NULL && curr_node->data != data) {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    
    if (curr_node == NULL) {
        // Value not found in Linked List
        return;
    }
    
    if (prev_node == NULL) {
        // Removing the head of the Linked List
        *head = curr_node->next;
    } else {
        // Remove a node in the middle or end of the Linked List
        prev_node->next = curr_node->next;
    }
    
    // Free the memory used by the deleted node
    free(curr_node);
    curr_node = NULL;
}

// Print the Linked List
void print(Node *head) {
    if (head == NULL) {
        // Empty Linked List
        printf("Empty Linked List\n");
    }
    
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    
    // Insert nodes at the beginning
    insert_beginning(&head, 5);
    insert_beginning(&head, 4);
    insert_beginning(&head, 3);
    print(head);
    
    // Insert nodes at the end
    insert_end(&head, 6);
    insert_end(&head, 7);
    print(head);
    
    // Delete a node
    delete(&head, 4);
    print(head);
    
    // Delete a node that doesn't exist in the Linked List
    delete(&head, 10);
    print(head);
    
    return 0;
}