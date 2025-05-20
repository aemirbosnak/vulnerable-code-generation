//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error: Couldn't allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(node_t **head, int data) {
    node_t *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node_t *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void insert_after_node(node_t *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Error: Previous node cannot be NULL.\n");
        return;
    }
    node_t *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void delete_node(node_t **head, int data) {
    node_t *current = *head;
    node_t *prev = NULL;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Error: Node with data %d not found.\n", data);
        return;
    }
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

void print_list(node_t *head) {
    node_t *current = head;
    printf("Linked list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node_t *head = NULL;
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_after_node(head, 15);
    print_list(head);  // Output: Linked list: 10 15 20

    delete_node(&head, 15);
    print_list(head);  // Output: Linked list: 10 20

    delete_node(&head, 10);
    print_list(head);  // Output: Linked list: 20

    delete_node(&head, 20);
    print_list(head);  // Output: Linked list:

    return 0;
}