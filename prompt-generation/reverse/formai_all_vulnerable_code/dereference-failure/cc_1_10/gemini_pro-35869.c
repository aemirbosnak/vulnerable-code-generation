//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_head(node_t **head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_tail(node_t **head, int data) {
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

void insert_at_index(node_t **head, int data, int index) {
    if (index == 0) {
        insert_at_head(head, data);
        return;
    }
    node_t *new_node = create_node(data);
    node_t *current = *head;
    for (int i = 0; i < index - 1; i++) {
        if (current == NULL) {
            printf("Index out of bounds\n");
            return;
        }
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

void delete_at_head(node_t **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    node_t *to_be_deleted = *head;
    *head = (*head)->next;
    free(to_be_deleted);
}

void delete_at_tail(node_t **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    node_t *current = *head;
    node_t *previous = NULL;
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

void delete_at_index(node_t **head, int index) {
    if (index == 0) {
        delete_at_head(head);
        return;
    }
    node_t *current = *head;
    node_t *previous = NULL;
    for (int i = 0; i < index; i++) {
        if (current == NULL) {
            printf("Index out of bounds\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node_t *head = NULL;
    insert_at_tail(&head, 1);
    insert_at_tail(&head, 2);
    insert_at_tail(&head, 3);
    insert_at_tail(&head, 4);
    insert_at_tail(&head, 5);
    print_list(head);
    delete_at_head(&head);
    print_list(head);
    delete_at_tail(&head);
    print_list(head);
    delete_at_index(&head, 2);
    print_list(head);
    insert_at_index(&head, 6, 2);
    print_list(head);
    return 0;
}