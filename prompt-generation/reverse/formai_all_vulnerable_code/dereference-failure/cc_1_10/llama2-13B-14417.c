//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRLEN 100
#define MAX_ARRAY_SIZE 10

typedef struct node {
    char *data;
    struct node *next;
} node_t;

typedef struct list {
    node_t *head;
    node_t *tail;
} list_t;

node_t *create_node(char *data) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

list_t *create_list() {
    list_t *list = (list_t *)malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insert_node(list_t *list, char *data) {
    node_t *node = create_node(data);
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void print_list(list_t *list) {
    node_t *current = list->head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

void free_list(list_t *list) {
    node_t *current = list->head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
}

int main() {
    srand(time(NULL));

    list_t *list = create_list();

    for (int i = 0; i < 10; i++) {
        char *data = malloc(MAX_STRLEN);
        snprintf(data, MAX_STRLEN, "Hello, world! %d", i);
        insert_node(list, data);
    }

    print_list(list);

    for (int i = 0; i < 5; i++) {
        char *data = malloc(MAX_STRLEN);
        snprintf(data, MAX_STRLEN, "Goodbye, world! %d", i);
        insert_node(list, data);
    }

    print_list(list);

    free_list(list);

    return 0;
}