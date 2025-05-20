//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in a linked list
struct node {
    int data;
    struct node *next;
};

// Create a new node with the given data and next pointer
struct node *create_node(int data, struct node *next) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = next;
    return new_node;
}

// Insert a new node at the beginning of the linked list
struct node *insert_at_beginning(struct node *head, int data) {
    return create_node(data, head);
}

// Insert a new node at the end of the linked list
struct node *insert_at_end(struct node *head, int data) {
    if (head == NULL) {
        return create_node(data, NULL);
    }
    head->next = insert_at_end(head->next, data);
    return head;
}

// Insert a new node after a given node in the linked list
struct node *insert_after(struct node *head, struct node *node, int data) {
    if (node == NULL) {
        return NULL;
    }
    node->next = create_node(data, node->next);
    return head;
}

// Delete the first node in the linked list
struct node *delete_first(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct node *new_head = head->next;
    free(head);
    return new_head;
}

// Delete the last node in the linked list
struct node *delete_last(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    head->next = delete_last(head->next);
    return head;
}

// Delete a node in the linked list
struct node *delete_node(struct node *head, struct node *node) {
    if (head == NULL || node == NULL) {
        return NULL;
    }
    if (head == node) {
        return delete_first(head);
    }
    head->next = delete_node(head->next, node);
    return head;
}

// Print the linked list
void print_list(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Free the linked list
void free_list(struct node *head) {
    while (head != NULL) {
        struct node *next = head->next;
        free(head);
        head = next;
    }
}

int main() {
    // Create an empty linked list
    struct node *head = NULL;

    // Insert some nodes into the linked list
    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_after(head, head->next, 4);

    // Print the linked list
    printf("Linked list: ");
    print_list(head);

    // Delete some nodes from the linked list
    head = delete_first(head);
    head = delete_last(head);
    head = delete_node(head, head->next);

    // Print the linked list
    printf("Linked list: ");
    print_list(head);

    // Free the linked list
    free_list(head);

    return 0;
}