//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_head(node **head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_tail(node **head, int data) {
    if (*head == NULL) {
        *head = create_node(data);
        return;
    }
    insert_at_tail(&(*head)->next, data);
}

void delete_node(node **head, int data) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->data == data) {
        *head = (*head)->next;
        return;
    }
    delete_node(&(*head)->next, data);
}

void print_list(node *head) {
    if (head == NULL) {
        printf("[]\n");
        return;
    }
    printf("[%d", head->data);
    print_list(head->next);
}

int main() {
    node *head = NULL;

    insert_at_head(&head, 1);
    insert_at_tail(&head, 2);
    insert_at_tail(&head, 3);
    insert_at_tail(&head, 4);
    insert_at_tail(&head, 5);

    print_list(head);

    delete_node(&head, 3);

    print_list(head);

    return 0;
}