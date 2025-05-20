//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct list {
    node_t *head;
    node_t *tail;
    int size;
} list_t;

list_t *create_list() {
    list_t *list = (list_t *) malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void destroy_list(list_t *list) {
    node_t *current = list->head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

bool is_empty(list_t *list) {
    return list->size == 0;
}

void push_back(list_t *list, int data) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (is_empty(list)) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

void pop_back(list_t *list) {
    if (is_empty(list)) {
        return;
    } else if (list->size == 1) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size--;
    } else {
        node_t *current = list->head;
        while (current->next != list->tail) {
            current = current->next;
        }
        free(list->tail);
        list->tail = current;
        list->tail->next = NULL;
        list->size--;
    }
}

void print_list(list_t *list) {
    node_t *current = list->head;
    printf("[");
    while (current != NULL) {
        printf("%d, ", current->data);
        current = current->next;
    }
    printf("]\n");
}

int main() {
    list_t *list = create_list();

    push_back(list, 1);
    push_back(list, 2);
    push_back(list, 3);
    push_back(list, 4);
    push_back(list, 5);

    print_list(list);

    pop_back(list);
    pop_back(list);

    print_list(list);

    destroy_list(list);

    return 0;
}