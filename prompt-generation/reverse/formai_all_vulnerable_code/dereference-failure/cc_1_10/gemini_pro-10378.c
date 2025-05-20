//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *create_node(int data) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
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

void insert_at_index(node **head, int data, int index) {
    if (index == 0) {
        insert_at_beginning(head, data);
        return;
    }
    node *new_node = create_node(data);
    node *current = *head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

void delete_at_beginning(node **head) {
    if (*head == NULL) {
        return;
    }
    node *current = *head;
    *head = (*head)->next;
    free(current);
}

void delete_at_end(node **head) {
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

void delete_at_index(node **head, int index) {
    if (*head == NULL) {
        return;
    }
    if (index == 0) {
        delete_at_beginning(head);
        return;
    }
    node *current = *head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    node *to_delete = current->next;
    current->next = to_delete->next;
    free(to_delete);
}

int main() {
    node *head = NULL;
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_index(&head, 3, 1);
    print_list(head);
    delete_at_beginning(&head);
    delete_at_end(&head);
    delete_at_index(&head, 0);
    print_list(head);
    free(head);
    return 0;
}