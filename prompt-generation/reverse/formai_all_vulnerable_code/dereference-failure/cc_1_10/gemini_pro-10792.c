//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *data;
    struct node *next;
} node_t;

typedef struct {
    node_t *head;
    node_t *tail;
    int size;
} list_t;

void list_init(list_t *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void list_destroy(list_t *list) {
    node_t *current = list->head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void list_push_back(list_t *list, char *data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = strdup(data);
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

void list_print(list_t *list) {
    node_t *current = list->head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

int main() {
    list_t list;
    list_init(&list);
    list_push_back(&list, "Hello");
    list_push_back(&list, "World");
    list_push_back(&list, "!");
    list_print(&list);
    list_destroy(&list);
    return 0;
}