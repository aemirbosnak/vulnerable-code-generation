//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// A simple linked list node
struct node {
    int data;
    struct node *next;
};

// A function to create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// A function to insert a node at the beginning of a linked list
void insert_at_beginning(struct node **head, struct node *new_node) {
    new_node->next = *head;
    *head = new_node;
}

// A function to insert a node at the end of a linked list
void insert_at_end(struct node **head, struct node *new_node) {
    struct node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// A function to insert a node after a given node
void insert_after(struct node *prev_node, struct node *new_node) {
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// A function to delete a node from a linked list
void delete_node(struct node **head, struct node *node_to_delete) {
    if (*head == node_to_delete) {
        *head = (*head)->next;
    } else {
        struct node *current = *head;
        while (current->next != node_to_delete) {
            current = current->next;
        }
        current->next = node_to_delete->next;
    }
    free(node_to_delete);
}

// A function to print the contents of a linked list
void print_linked_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Let's create a linked list of integers

    struct node *head = NULL;

    // Let's create a few nodes and insert them into the linked list

    struct node *node1 = create_node(1);
    struct node *node2 = create_node(2);
    struct node *node3 = create_node(3);
    struct node *node4 = create_node(4);
    struct node *node5 = create_node(5);

    insert_at_beginning(&head, node1);
    insert_at_beginning(&head, node2);
    insert_at_end(&head, node3);
    insert_at_beginning(&head, node4);
    insert_after(node2, node5);

    // Let's print the contents of the linked list

    print_linked_list(head);

    // Let's delete a few nodes from the linked list

    delete_node(&head, node2);
    delete_node(&head, node4);
    delete_node(&head, node5);

    // Let's print the contents of the linked list again

    print_linked_list(head);

    // Finally, let's free the memory allocated for the linked list

    while (head != NULL) {
        struct node *next_node = head->next;
        free(head);
        head = next_node;
    }

    return 0;
}