//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

void print_list(node_t *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(node_t **head, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    node_t *last_node = *head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

void insert_at_index(node_t **head, int data, int index) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (index == 0) {
        insert_at_beginning(head, data);
        return;
    }

    node_t *current_node = *head;
    int i = 0;
    while (current_node != NULL && i < index - 1) {
        current_node = current_node->next;
        i++;
    }

    if (current_node == NULL) {
        printf("Invalid index %d\n", index);
        return;
    }

    new_node->next = current_node->next;
    current_node->next = new_node;
}

void delete_at_beginning(node_t **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_at_end(node_t **head) {
    if (*head == NULL) {
        printf("List is empty\n");
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

void delete_at_index(node_t **head, int index) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (index == 0) {
        delete_at_beginning(head);
        return;
    }

    node_t *current_node = *head;
    int i = 0;
    while (current_node->next != NULL && i < index - 1) {
        current_node = current_node->next;
        i++;
    }

    if (current_node->next == NULL) {
        printf("Invalid index %d\n", index);
        return;
    }

    node_t *temp = current_node->next;
    current_node->next = temp->next;
    free(temp);
}

void reverse_list(node_t **head) {
    node_t *prev = NULL;
    node_t *current = *head;
    node_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

int main() {
    node_t *head = NULL;

    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_index(&head, 30, 1);
    insert_at_index(&head, 40, 3);

    print_list(head);

    delete_at_beginning(&head);
    delete_at_end(&head);
    delete_at_index(&head, 1);

    print_list(head);

    reverse_list(&head);

    print_list(head);

    return 0;
}