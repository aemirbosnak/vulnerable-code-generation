//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Linked list operations
void insert_at_beginning(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void insert_at_position(node **head, int data, int position) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    if (position == 1) {
        new_node->next = *head;
        *head = new_node;
    } else {
        node *current = *head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void delete_at_beginning(node **head) {
    if (*head == NULL) {
        return;
    }
    node *current = *head;
    *head = current->next;
    free(current);
}

void delete_at_end(node **head) {
    if (*head == NULL) {
        return;
    }
    node *current = *head;
    node *previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        *head = NULL;
    } else {
        previous->next = NULL;
    }
    free(current);
}

void delete_at_position(node **head, int position) {
    if (*head == NULL) {
        return;
    }
    node *current = *head;
    node *previous = NULL;
    if (position == 1) {
        *head = current->next;
        free(current);
    } else {
        for (int i = 1; i < position; i++) {
            previous = current;
            current = current->next;
        }
        if (current == NULL) {
            return;
        }
        if (previous == NULL) {
            *head = NULL;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

void print_linked_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    node *head = NULL;

    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_position(&head, 30, 2);
    insert_at_beginning(&head, 5);
    insert_at_position(&head, 25, 3);
    insert_at_end(&head, 15);

    print_linked_list(head);

    delete_at_beginning(&head);
    delete_at_end(&head);
    delete_at_position(&head, 2);

    print_linked_list(head);

    return 0;
}