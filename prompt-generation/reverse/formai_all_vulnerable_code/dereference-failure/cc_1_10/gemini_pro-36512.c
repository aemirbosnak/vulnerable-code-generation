//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

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

void add_to_head(node **head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void add_to_tail(node **head, int data) {
    node *new_node = create_node(data);
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

void remove_from_head(node **head) {
    if (*head == NULL) {
        return;
    }
    node *current = *head;
    *head = (*head)->next;
    free(current);
}

void remove_from_tail(node **head) {
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

    add_to_head(&head, 1);
    add_to_head(&head, 2);
    add_to_head(&head, 3);
    add_to_tail(&head, 4);
    add_to_tail(&head, 5);
    add_to_tail(&head, 6);

    print_list(head);

    remove_from_head(&head);
    remove_from_tail(&head);

    print_list(head);

    return 0;
}