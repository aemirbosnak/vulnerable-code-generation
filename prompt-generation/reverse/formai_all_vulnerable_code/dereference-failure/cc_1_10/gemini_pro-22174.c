//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: Couldn't allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the list
void insert_at_beginning(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of the list
void insert_at_end(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Function to insert a node after a given node
void insert_after(struct node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Error: Previous node cannot be null.\n");
        exit(1);
    }
    struct node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to delete a node from the beginning of the list
void delete_from_beginning(struct node **head) {
    if (*head == NULL) {
        printf("Error: List is empty.\n");
        exit(1);
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end of the list
void delete_from_end(struct node **head) {
    if (*head == NULL) {
        printf("Error: List is empty.\n");
        exit(1);
    }
    struct node *current = *head;
    struct node *prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }
    free(current);
}

// Function to delete a node from the list
void delete_node(struct node **head, struct node *node) {
    if (*head == NULL || node == NULL) {
        printf("Error: List or node is empty.\n");
        exit(1);
    }
    if (*head == node) {
        delete_from_beginning(head);
        return;
    }
    struct node *current = *head;
    struct node *prev = NULL;
    while (current != node) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Error: Node not found in the list.\n");
        exit(1);
    }
    if (current->next == NULL) {
        delete_from_end(head);
        return;
    }
    prev->next = current->next;
    free(current);
}

// Function to print the list
void print_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create an empty list
    struct node *head = NULL;

    // Insert some nodes into the list
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_after(head, 3);
    insert_at_beginning(&head, 4);
    insert_at_end(&head, 5);

    // Print the list
    printf("Original list: ");
    print_list(head);

    // Delete a node from the beginning of the list
    delete_from_beginning(&head);

    // Print the list
    printf("List after deleting a node from the beginning: ");
    print_list(head);

    // Delete a node from the end of the list
    delete_from_end(&head);

    // Print the list
    printf("List after deleting a node from the end: ");
    print_list(head);

    // Delete a node from the middle of the list
    delete_node(&head, head->next);

    // Print the list
    printf("List after deleting a node from the middle: ");
    print_list(head);

    return 0;
}