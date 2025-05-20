//GEMINI-pro DATASET v1.0 Category: Educational ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a linked list node
struct node {
    int data;
    struct node *next;
};

// A function to create a new linked list node
struct node *create_node(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error allocating memory for new node\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// A function to insert a new node at the beginning of a linked list
void insert_node_at_beginning(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// A function to insert a new node at the end of a linked list
void insert_node_at_end(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

// A function to delete a node from the beginning of a linked list
void delete_node_from_beginning(struct node **head) {
    if (*head == NULL) {
        printf("Error: Cannot delete from an empty list\n");
        return;
    }
    struct node *current_node = *head;
    *head = current_node->next;
    free(current_node);
}

// A function to delete a node from the end of a linked list
void delete_node_from_end(struct node **head) {
    if (*head == NULL) {
        printf("Error: Cannot delete from an empty list\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node *current_node = *head;
    struct node *previous_node = NULL;
    while (current_node->next != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    previous_node->next = NULL;
    free(current_node);
}

// A function to print a linked list
void print_linked_list(struct node *head) {
    if (head == NULL) {
        printf("[]\n");
        return;
    }
    printf("[");
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%d, ", current_node->data);
        current_node = current_node->next;
    }
    printf("\b\b]\n");
}

int main() {
    // Create a linked list
    struct node *head = NULL;

    // Insert nodes at the beginning and end of the list
    insert_node_at_beginning(&head, 10);
    insert_node_at_end(&head, 20);
    insert_node_at_beginning(&head, 30);
    insert_node_at_end(&head, 40);

    // Print the linked list
    print_linked_list(head);

    // Delete nodes from the beginning and end of the list
    delete_node_from_beginning(&head);
    delete_node_from_end(&head);

    // Print the linked list again
    print_linked_list(head);

    // Free the linked list
    struct node *current_node = head;
    while (current_node != NULL) {
        struct node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    head = NULL;

    return 0;
}