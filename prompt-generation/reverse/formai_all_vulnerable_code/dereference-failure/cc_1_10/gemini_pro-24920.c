//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *create_node(int data) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node_at_head(node_t **head, int data) {
    node_t *new_node = create_node(data);
    if (new_node == NULL) {
        return;
    }
    new_node->next = *head;
    *head = new_node;
}

void insert_node_at_tail(node_t **head, int data) {
    node_t *new_node = create_node(data);
    if (new_node == NULL) {
        return;
    }
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node_t *current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

void insert_node_at_index(node_t **head, int index, int data) {
    if (index == 0) {
        insert_node_at_head(head, data);
        return;
    }
    node_t *new_node = create_node(data);
    if (new_node == NULL) {
        return;
    }
    node_t *current_node = *head;
    int i = 0;
    while (current_node != NULL && i < index - 1) {
        current_node = current_node->next;
        i++;
    }
    if (current_node == NULL) {
        return;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
}

void delete_node_at_head(node_t **head) {
    if (*head == NULL) {
        return;
    }
    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_node_at_tail(node_t **head) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    node_t *current_node = *head;
    while (current_node->next->next != NULL) {
        current_node = current_node->next;
    }
    free(current_node->next);
    current_node->next = NULL;
}

void delete_node_at_index(node_t **head, int index) {
    if (index == 0) {
        delete_node_at_head(head);
        return;
    }
    node_t *current_node = *head;
    int i = 0;
    while (current_node != NULL && i < index - 1) {
        current_node = current_node->next;
        i++;
    }
    if (current_node == NULL || current_node->next == NULL) {
        return;
    }
    node_t *temp = current_node->next;
    current_node->next = temp->next;
    free(temp);
}

void print_list(node_t *head) {
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    node_t *head = NULL;

    insert_node_at_head(&head, 1);
    insert_node_at_tail(&head, 2);
    insert_node_at_index(&head, 1, 3);

    print_list(head);

    delete_node_at_head(&head);
    delete_node_at_tail(&head);
    delete_node_at_index(&head, 0);

    print_list(head);

    return 0;
}