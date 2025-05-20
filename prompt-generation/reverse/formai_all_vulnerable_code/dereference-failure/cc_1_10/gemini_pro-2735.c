//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Claude Shannon
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct node {
    int data;
    struct node *next;
};

// Create a new linked list
struct node *create_list() {
    return NULL;
}

// Insert a new node at the beginning of the list
struct node *insert_at_beginning(struct node *head, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

// Insert a new node at the end of the list
struct node *insert_at_end(struct node *head, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    struct node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = new_node;
    return head;
}

// Insert a new node after a given node
struct node *insert_after(struct node *head, int data, int after) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;

    if (head == NULL) {
        return new_node;
    }

    struct node *current_node = head;
    while (current_node != NULL) {
        if (current_node->data == after) {
            new_node->next = current_node->next;
            current_node->next = new_node;
            return head;
        }
        current_node = current_node->next;
    }

    return head;
}

// Delete a node from the list
struct node *delete_node(struct node *head, int data) {
    if (head == NULL) {
        return NULL;
    }

    if (head->data == data) {
        struct node *new_head = head->next;
        free(head);
        return new_head;
    }

    struct node *current_node = head;
    while (current_node->next != NULL) {
        if (current_node->next->data == data) {
            struct node *node_to_delete = current_node->next;
            current_node->next = node_to_delete->next;
            free(node_to_delete);
            return head;
        }
        current_node = current_node->next;
    }

    return head;
}

// Print the list
void print_list(struct node *head) {
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Free the list
void free_list(struct node *head) {
    struct node *current_node = head;
    while (current_node != NULL) {
        struct node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
}

int main() {
    struct node *head = create_list();

    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_after(head, 3, 1);
    head = delete_node(head, 2);

    print_list(head);

    free_list(head);

    return 0;
}