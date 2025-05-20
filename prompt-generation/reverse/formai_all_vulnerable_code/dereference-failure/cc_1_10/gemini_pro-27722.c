//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *create_node(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Error: Unable to allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of a linked list
void insert_at_beginning(struct Node **head, int data) {
    struct Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of a linked list
void insert_at_end(struct Node **head, int data) {
    struct Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node *current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

// Function to insert a node at a specific position in a linked list
void insert_at_position(struct Node **head, int data, int position) {
    if (position == 0) {
        insert_at_beginning(head, data);
        return;
    }
    struct Node *new_node = create_node(data);
    struct Node *current_node = *head;
    for (int i = 0; i < position - 1; i++) {
        if (current_node->next == NULL) {
            printf("Error: Position %d is beyond the end of the linked list.\n", position);
            free(new_node);
            return;
        }
        current_node = current_node->next;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
}

// Function to delete a node at the beginning of a linked list
void delete_at_beginning(struct Node **head) {
    if (*head == NULL) {
        printf("Error: Linked list is empty.\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node at the end of a linked list
void delete_at_end(struct Node **head) {
    if (*head == NULL) {
        printf("Error: Linked list is empty.\n");
        return;
    }
    struct Node *current_node = *head;
    struct Node *previous_node = NULL;
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

// Function to delete a node at a specific position in a linked list
void delete_at_position(struct Node **head, int position) {
    if (*head == NULL) {
        printf("Error: Linked list is empty.\n");
        return;
    }
    if (position == 0) {
        delete_at_beginning(head);
        return;
    }
    struct Node *current_node = *head;
    struct Node *previous_node = NULL;
    for (int i = 0; i < position; i++) {
        if (current_node->next == NULL) {
            printf("Error: Position %d is beyond the end of the linked list.\n", position);
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (previous_node == NULL) {
        *head = current_node->next;
    } else {
        previous_node->next = current_node->next;
    }
    free(current_node);
}

// Function to print a linked list
void print_linked_list(struct Node *head) {
    printf("Linked list: ");
    struct Node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Function to free a linked list
void free_linked_list(struct Node *head) {
    struct Node *current_node = head;
    struct Node *next_node;
    while (current_node != NULL) {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
}

// Driver code
int main() {
    // Create an empty linked list
    struct Node *head = NULL;

    // Insert nodes at the beginning of the linked list
    insert_at_beginning(&head, 1);
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 3);

    // Print the linked list
    print_linked_list(head);

    // Insert a node at the end of the linked list
    insert_at_end(&head, 4);

    // Print the linked list
    print_linked_list(head);

    // Insert a node at a specific position in the linked list
    insert_at_position(&head, 5, 2);

    // Print the linked list
    print_linked_list(head);

    // Delete a node at the beginning of the linked list
    delete_at_beginning(&head);

    // Print the linked list
    print_linked_list(head);

    // Delete a node at the end of the linked list
    delete_at_end(&head);

    // Print the linked list
    print_linked_list(head);

    // Delete a node at a specific position in the linked list
    delete_at_position(&head, 2);

    // Print the linked list
    print_linked_list(head);

    // Free the linked list
    free_linked_list(head);

    return 0;
}