//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct list {
    node_t *head;
    node_t *tail;
} list_t;

void list_init(list_t *list) {
    list->head = NULL;
    list->tail = NULL;
}

void list_append(list_t *list, int data) {
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

void list_print(list_t *list) {
    node_t *current_node = list->head;

    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
}

int main() {
    list_t list;
    list_init(&list);

    list_append(&list, 1);
    list_append(&list, 2);
    list_append(&list, 3);
    list_append(&list, 4);
    list_append(&list, 5);

    list_print(&list);

    return 0;
}