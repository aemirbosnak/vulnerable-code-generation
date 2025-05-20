//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

void insert_at_head(node_t **head, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    assert(new_node != NULL);
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_tail(node_t **head, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    assert(new_node != NULL);
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

void insert_at_index(node_t **head, int index, int data) {
    assert(index >= 0);
    if (index == 0) {
        insert_at_head(head, data);
    } else {
        node_t *new_node = malloc(sizeof(node_t));
        assert(new_node != NULL);
        new_node->data = data;
        node_t *current = *head;
        for (int i = 0; i < index - 1; i++) {
            assert(current != NULL);
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void delete_at_head(node_t **head) {
    if (*head == NULL) {
        return;
    }
    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_at_tail(node_t **head) {
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
    assert(index >= 0);
    if (index == 0) {
        delete_at_head(head);
    } else {
        node_t *current = *head;
        for (int i = 0; i < index - 1; i++) {
            assert(current != NULL);
            current = current->next;
        }
        node_t *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

void reverse_list(node_t **head) {
    node_t *prev = NULL;
    node_t *current = *head;
    node_t *next;
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
    insert_at_head(&head, 1);
    insert_at_tail(&head, 2);
    insert_at_index(&head, 1, 3);
    print_list(head);  // Output: 1 3 2
    delete_at_head(&head);
    delete_at_tail(&head);
    delete_at_index(&head, 0);
    print_list(head);  // Output: Empty list
    reverse_list(&head);
    print_list(head);  // Output: Empty list
    return 0;
}