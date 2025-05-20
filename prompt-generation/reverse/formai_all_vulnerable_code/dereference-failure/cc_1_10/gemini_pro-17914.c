//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *create_list(int *arr, int size) {
    node_t *head = NULL, *tail = NULL;
    for (int i = 0; i < size; i++) {
        node_t *new_node = malloc(sizeof(node_t));
        new_node->data = arr[i];
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    return head;
}

void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

node_t *insert_at_beginning(node_t *head, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

node_t *insert_at_end(node_t *head, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        return new_node;
    }
    node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

node_t *insert_at_index(node_t *head, int data, int index) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    if (index == 0) {
        return insert_at_beginning(head, data);
    }
    node_t *current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}

node_t *delete_from_beginning(node_t *head) {
    if (head == NULL) {
        return NULL;
    }
    node_t *new_head = head->next;
    free(head);
    return new_head;
}

node_t *delete_from_end(node_t *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    node_t *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

node_t *delete_at_index(node_t *head, int index) {
    if (index == 0) {
        return delete_from_beginning(head);
    }
    node_t *current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    node_t *temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    node_t *head = create_list(arr, size);
    print_list(head);
    head = insert_at_beginning(head, 0);
    print_list(head);
    head = insert_at_end(head, 6);
    print_list(head);
    head = insert_at_index(head, 7, 3);
    print_list(head);
    head = delete_from_beginning(head);
    print_list(head);
    head = delete_from_end(head);
    print_list(head);
    head = delete_at_index(head, 2);
    print_list(head);
    return 0;
}