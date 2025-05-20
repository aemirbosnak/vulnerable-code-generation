//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure of a node in a linked list.
struct node {
    int data;
    struct node *next;
};

// Create a new node with the given data.
struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of the linked list.
void insert_at_beginning(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a new node at the end of the linked list.
void insert_at_end(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Delete the first node in the linked list.
void delete_first_node(struct node **head) {
    if (*head == NULL) {
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete the last node in the linked list.
void delete_last_node(struct node **head) {
    if (*head == NULL) {
        return;
    }
    struct node *current = *head;
    if (current->next == NULL) {
        *head = NULL;
        free(current);
        return;
    }
    while (current->next->next != NULL) {
        current = current->next;
    }
    struct node *temp = current->next;
    current->next = NULL;
    free(temp);
}

// Print the linked list.
void print_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free the linked list.
void free_list(struct node **head) {
    struct node *current = *head;
    while (current != NULL) {
        struct node *temp = current->next;
        free(current);
        current = temp;
    }
    *head = NULL;
}

int main() {
    // Create a linked list.
    struct node *head = NULL;

    // Insert some data into the linked list.
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_beginning(&head, 3);
    insert_at_end(&head, 4);

    // Print the linked list.
    print_list(head);

    // Delete the first node in the linked list.
    delete_first_node(&head);

    // Delete the last node in the linked list.
    delete_last_node(&head);

    // Print the linked list.
    print_list(head);

    // Free the linked list.
    free_list(&head);

    return 0;
}