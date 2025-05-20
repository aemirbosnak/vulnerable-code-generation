//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void insert_at_head(node **head, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_tail(node **head, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

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

void delete_at_head(node **head) {
    if (*head == NULL) {
        return;
    }

    node *to_delete = *head;
    *head = (*head)->next;
    free(to_delete);
}

void delete_at_tail(node **head) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

void print_list(node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;

    insert_at_head(&head, 1);
    insert_at_head(&head, 2);
    insert_at_head(&head, 3);
    insert_at_tail(&head, 4);
    insert_at_tail(&head, 5);
    insert_at_tail(&head, 6);

    print_list(head);

    delete_at_head(&head);
    delete_at_tail(&head);

    print_list(head);

    return 0;
}