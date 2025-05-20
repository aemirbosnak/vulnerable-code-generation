//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: complex
#include <stdlib.h>
#include <stdio.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_at_end(struct node **head, int data) {
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

// Function to insert a node after a given node
void insert_after(struct node **head, int data, int after_data) {
    struct node *new_node = create_node(data);
    struct node *current_node = *head;
    while (current_node != NULL) {
        if (current_node->data == after_data) {
            new_node->next = current_node->next;
            current_node->next = new_node;
            return;
        }
        current_node = current_node->next;
    }
    printf("Node with data %d not found\n", after_data);
}

// Function to delete a node from the beginning of the linked list
void delete_from_beginning(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end of the linked list
void delete_from_end(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *current_node = *head;
    struct node *previous_node = NULL;
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

// Function to delete a node from the middle of the linked list
void delete_from_middle(struct node **head, int data) {
    struct node *current_node = *head;
    struct node *previous_node = NULL;
    while (current_node != NULL) {
        if (current_node->data == data) {
            if (previous_node == NULL) {
                *head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
    printf("Node with data %d not found\n", data);
}

// Function to print the linked list
void print_list(struct node *head) {
    printf("[");
    while (head != NULL) {
        printf("%d, ", head->data);
        head = head->next;
    }
    printf("]\n");
}

// Driver code
int main() {
    // Create a new linked list
    struct node *head = NULL;

    // Insert some nodes into the linked list
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_after(&head, 3, 1);
    insert_after(&head, 4, 2);

    // Print the linked list
    printf("Linked list: ");
    print_list(head);

    // Delete a node from the beginning of the linked list
    delete_from_beginning(&head);

    // Print the linked list
    printf("Linked list after deleting from beginning: ");
    print_list(head);

    // Delete a node from the end of the linked list
    delete_from_end(&head);

    // Print the linked list
    printf("Linked list after deleting from end: ");
    print_list(head);

    // Delete a node from the middle of the linked list
    delete_from_middle(&head, 3);

    // Print the linked list
    printf("Linked list after deleting from middle: ");
    print_list(head);

    return 0;
}