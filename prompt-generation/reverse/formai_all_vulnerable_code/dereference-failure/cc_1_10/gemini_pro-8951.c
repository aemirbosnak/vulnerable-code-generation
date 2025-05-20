//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 256

typedef struct node {
    char name[MAX_NAME_LENGTH];
    struct node *next;
} node_t;

void print_list(node_t *head) {
    printf("Linked list: ");
    for (node_t *curr = head; curr != NULL; curr = curr->next) {
        printf("%s -> ", curr->name);
    }
    printf("NULL\n");
}

void insert_at_head(node_t **head, char *name) {
    node_t *new_node = malloc(sizeof(node_t));
    strcpy(new_node->name, name);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_tail(node_t **head, char *name) {
    node_t *new_node = malloc(sizeof(node_t));
    strcpy(new_node->name, name);
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

void insert_after(node_t *prev, char *name) {
    if (prev == NULL) {
        return;
    }

    node_t *new_node = malloc(sizeof(node_t));
    strcpy(new_node->name, name);
    new_node->next = prev->next;
    prev->next = new_node;
}

void delete_node(node_t **head, char *name) {
    if (*head == NULL) {
        return;
    }

    if (strcmp((*head)->name, name) == 0) {
        *head = (*head)->next;
        return;
    }

    node_t *curr = *head;
    node_t *prev = NULL;
    while (curr != NULL && strcmp(curr->name, name) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        return;
    }

    if (prev == NULL) {
        *head = curr->next;
    } else {
        prev->next = curr->next;
    }

    free(curr);
}

int main() {
    node_t *head = NULL;

    insert_at_head(&head, "Alice");
    insert_at_tail(&head, "Bob");
    insert_after(head, "Carol");
    insert_after(head->next, "Dave");

    print_list(head);

    delete_node(&head, "Carol");

    print_list(head);

    return 0;
}