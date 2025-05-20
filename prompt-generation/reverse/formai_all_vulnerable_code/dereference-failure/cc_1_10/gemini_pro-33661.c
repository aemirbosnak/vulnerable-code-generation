//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *create_node(int data) {
    node *new_node = (node *) malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: malloc failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning(node **head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(node **head, int data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void insert_after_node(node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Error: prev_node cannot be NULL.\n");
        exit(1);
    }
    node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void delete_node(node **head, node *node_to_delete) {
    if (*head == node_to_delete) {
        *head = (*head)->next;
        free(node_to_delete);
        return;
    }
    node *current = *head;
    while (current->next != node_to_delete) {
        current = current->next;
        if (current == NULL) {
            printf("Error: node_to_delete not found.\n");
            exit(1);
        }
    }
    current->next = node_to_delete->next;
    free(node_to_delete);
}

void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;

    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    insert_after_node(head->next, 15);

    print_list(head);

    delete_node(&head, head);
    delete_node(&head, head->next->next);

    print_list(head);

    return 0;
}