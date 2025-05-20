//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = create_node(data);
    if (new_node == NULL) {
        return;
    }
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(node_t **head, int data) {
    node_t *new_node = create_node(data);
    if (new_node == NULL) {
        return;
    }
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
        insert_at_beginning(head, data);
        return;
    }
    node_t *new_node = create_node(data);
    if (new_node == NULL) {
        return;
    }
    node_t *current = *head;
    int i = 0;
    while (current->next != NULL && i < index - 1) {
        current = current->next;
        i++;
    }
    if (i == index - 1) {
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
    if (index == 0) {
        delete_at_beginning(head);
        return;
    }
    node_t *current = *head;
    int i = 0;
    while (current->next != NULL && i < index - 1) {
        current = current->next;
        i++;
    }
    if (i == index - 1) {
        node_t *temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
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
    insert_at_end(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_at_end(&head, 4);
    insert_at_end(&head, 5);
    print_list(head);
    delete_at_beginning(&head);
    print_list(head);
    delete_at_end(&head);
    print_list(head);
    delete_at_index(&head, 2);
    print_list(head);
    return 0;
}