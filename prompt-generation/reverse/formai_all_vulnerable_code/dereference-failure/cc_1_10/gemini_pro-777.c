//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct list {
    node_t *head;
    node_t *tail;
} list_t;

void init_list(list_t *list) {
    list->head = NULL;
    list->tail = NULL;
}

void add_node(list_t *list, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void print_list(list_t *list) {
    node_t *current_node = list->head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

void free_list(list_t *list) {
    node_t *current_node = list->head;
    while (current_node != NULL) {
        node_t *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    list->head = NULL;
    list->tail = NULL;
}

int main() {
    list_t list;
    init_list(&list);
    add_node(&list, 1);
    add_node(&list, 2);
    add_node(&list, 3);
    add_node(&list, 4);
    add_node(&list, 5);
    print_list(&list);
    free_list(&list);
    return 0;
}