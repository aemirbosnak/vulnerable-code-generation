//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    char *key;
    char *value;
    struct _node *next;
} node;

typedef struct _list {
    node *head;
    node *tail;
} list;

void init_list(list *l) {
    l->head = NULL;
    l->tail = NULL;
}

void add_to_list(list *l, char *key, char *value) {
    node *new_node = malloc(sizeof(node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;

    if (l->head == NULL) {
        l->head = new_node;
        l->tail = new_node;
    } else {
        l->tail->next = new_node;
        l->tail = new_node;
    }
}

void print_list(list *l) {
    node *current_node = l->head;

    while (current_node != NULL) {
        printf("%s: %s\n", current_node->key, current_node->value);
        current_node = current_node->next;
    }
}

void free_list(list *l) {
    node *current_node = l->head;

    while (current_node != NULL) {
        node *next_node = current_node->next;
        free(current_node->key);
        free(current_node->value);
        free(current_node);
        current_node = next_node;
    }

    l->head = NULL;
    l->tail = NULL;
}

int main() {
    list l;

    init_list(&l);
    add_to_list(&l, "key1", "value1");
    add_to_list(&l, "key2", "value2");
    add_to_list(&l, "key3", "value3");

    print_list(&l);

    free_list(&l);

    return 0;
}