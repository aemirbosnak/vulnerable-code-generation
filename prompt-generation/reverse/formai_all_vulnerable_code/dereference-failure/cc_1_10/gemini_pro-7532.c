//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Create a new node with the given data
Node *create_node(int data) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error allocating memory for new node\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the list
void insert_at_beginning(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a node at the end of the list
void insert_at_end(Node **head, int data) {
    Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node *current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

// Insert a node after a given node
void insert_after(Node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Error: Previous node cannot be NULL\n");
        exit(1);
    }
    Node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the beginning of the list
void delete_from_beginning(Node **head) {
    if (*head == NULL) {
        printf("Error: List is empty\n");
        exit(1);
    }
    Node *current_node = *head;
    *head = (*head)->next;
    free(current_node);
}

// Delete a node from the end of the list
void delete_from_end(Node **head) {
    if (*head == NULL) {
        printf("Error: List is empty\n");
        exit(1);
    }
    Node *current_node = *head;
    Node *previous_node = NULL;
    while (current_node->next != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (previous_node == NULL) {
        *head = NULL;
    } else {
        previous_node->next = NULL;
    }
    free(current_node);
}

// Delete a node from the middle of the list
void delete_from_middle(Node *node) {
    if (node == NULL) {
        printf("Error: Node cannot be NULL\n");
        exit(1);
    }
    Node *next_node = node->next;
    node->data = next_node->data;
    node->next = next_node->next;
    free(next_node);
}

// Print the list
void print_list(Node *head) {
    Node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Reverse the list
Node *reverse_list(Node *head) {
    Node *previous_node = NULL;
    Node *current_node = head;
    Node *next_node = NULL;
    while (current_node != NULL) {
        next_node = current_node->next;
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }
    return previous_node;
}

int main() {
    Node *head = NULL;

    // Insert some data into the list
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_after(head, 4);
    
    printf("Original list: ");
    print_list(head);

    // Delete some data from the list
    delete_from_beginning(&head);
    delete_from_end(&head);
    delete_from_middle(head->next);
    
    printf("Modified list: ");
    print_list(head);

    // Reverse the list
    head = reverse_list(head);
   
    printf("Reversed list: ");
    print_list(head);

    return 0;
}