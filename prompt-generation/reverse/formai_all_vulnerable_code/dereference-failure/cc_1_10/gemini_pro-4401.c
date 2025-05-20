//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a node for a linked list
struct node {
    int data;
    struct node *next;
};

// Create a new node with the given data
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the linked list
void insert_at_beginning(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a node at the end of the linked list
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

// Insert a node at the given index in the linked list
void insert_at_index(struct node **head, int index, int data) {
    if (index == 0) {
        insert_at_beginning(head, data);
    } else {
        struct node *new_node = create_node(data);
        struct node *current = *head;
        int i = 0;
        while (i < index - 1) {
            current = current->next;
            i++;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

// Delete a node from the beginning of the linked list
void delete_from_beginning(struct node **head) {
    if (*head == NULL) {
        return;
    } else {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Delete a node from the end of the linked list
void delete_from_end(struct node **head) {
    if (*head == NULL) {
        return;
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        struct node *current = *head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
}

// Delete a node from the given index in the linked list
void delete_from_index(struct node **head, int index) {
    if (index == 0) {
        delete_from_beginning(head);
    } else {
        struct node *current = *head;
        int i = 0;
        while (i < index - 1) {
            current = current->next;
            i++;
        }
        struct node *temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

// Print the linked list
void print_linked_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a linked list
    struct node *head = NULL;

    // Insert some data into the linked list
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_index(&head, 1, 15);

    // Print the linked list
    printf("Linked list: ");
    print_linked_list(head);

    // Delete a node from the beginning of the linked list
    delete_from_beginning(&head);

    // Print the linked list
    printf("Linked list after deleting from beginning: ");
    print_linked_list(head);

    // Delete a node from the end of the linked list
    delete_from_end(&head);

    // Print the linked list
    printf("Linked list after deleting from end: ");
    print_linked_list(head);

    // Delete a node from the given index in the linked list
    delete_from_index(&head, 1);

    // Print the linked list
    printf("Linked list after deleting from index 1: ");
    print_linked_list(head);

    return 0;
}