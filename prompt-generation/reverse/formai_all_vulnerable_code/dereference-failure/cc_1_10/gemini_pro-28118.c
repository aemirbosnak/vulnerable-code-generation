//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: curious
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct linked_list {
    node_t *head;
    node_t *tail;
    int size;
} linked_list_t;

void init_linked_list(linked_list_t *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void insert_node(linked_list_t *list, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
}

void print_linked_list(linked_list_t *list) {
    node_t *current_node = list->head;

    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
}

void reverse_linked_list(linked_list_t *list) {
    node_t *current_node = list->head;
    node_t *previous_node = NULL;
    node_t *next_node;

    while (current_node != NULL) {
        next_node = current_node->next;
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }

    list->head = previous_node;
}

int main() {
    linked_list_t list;

    init_linked_list(&list);

    for (int i = 0; i < MAX_SIZE; i++) {
        insert_node(&list, i);
    }

    print_linked_list(&list);

    reverse_linked_list(&list);

    print_linked_list(&list);

    return 0;
}