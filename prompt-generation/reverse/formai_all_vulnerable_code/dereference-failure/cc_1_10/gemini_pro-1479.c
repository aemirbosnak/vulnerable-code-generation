//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

void print_list(node_t *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(node_t **head, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void insert_at_index(node_t **head, int data, int index) {
    if (index == 0) {
        insert_at_beginning(head, data);
    } else {
        node_t *new_node = malloc(sizeof(node_t));
        new_node->data = data;

        node_t *current = *head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void delete_at_beginning(node_t **head) {
    if (*head == NULL) {
        return;
    }

    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_at_end(node_t **head) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    node_t *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void delete_at_index(node_t **head, int index) {
    if (*head == NULL) {
        return;
    }

    if (index == 0) {
        delete_at_beginning(head);
    } else {
        node_t *current = *head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        node_t *temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

int main() {
    node_t *head = NULL;

    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_index(&head, 30, 1);

    print_list(head);

    delete_at_beginning(&head);
    delete_at_end(&head);
    delete_at_index(&head, 0);

    print_list(head);

    return 0;
}