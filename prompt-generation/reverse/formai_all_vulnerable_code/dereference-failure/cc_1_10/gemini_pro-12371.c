//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

void insert_at_position(struct node **head, int data, int position) {
    if (position == 0) {
        insert_at_beginning(head, data);
        return;
    }
    struct node *new_node = create_node(data);
    struct node *current_node = *head;
    for (int i = 0; i < position - 1; i++) {
        current_node = current_node->next;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
}

void delete_at_beginning(struct node **head) {
    if (*head == NULL) {
        return;
    }
    struct node *current_node = *head;
    *head = (*head)->next;
    free(current_node);
}

void delete_at_end(struct node **head) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node *current_node = *head;
    while (current_node->next->next != NULL) {
        current_node = current_node->next;
    }
    free(current_node->next);
    current_node->next = NULL;
}

void delete_at_position(struct node **head, int position) {
    if (position == 0) {
        delete_at_beginning(head);
        return;
    }
    struct node *current_node = *head;
    for (int i = 0; i < position - 1; i++) {
        current_node = current_node->next;
    }
    struct node *node_to_delete = current_node->next;
    current_node->next = node_to_delete->next;
    free(node_to_delete);
}

void print_list(struct node *head) {
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_position(&head, 30, 1);
    insert_at_position(&head, 40, 2);
    print_list(head);  // 10 30 40 20
    delete_at_beginning(&head);
    delete_at_end(&head);
    delete_at_position(&head, 1);
    print_list(head);  // 30
    return 0;
}