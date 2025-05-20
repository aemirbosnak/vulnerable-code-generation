//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_SIZE 1024

typedef struct {
    char *name;
    char *value;
    struct node *next;
} node_t;

typedef struct {
    node_t *head;
    node_t *tail;
    int size;
} linked_list_t;

linked_list_t *create_list() {
    linked_list_t *list = (linked_list_t *) malloc(sizeof(linked_list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void add_node(linked_list_t *list, char *name, char *value) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->name = strdup(name);
    new_node->value = strdup(value);
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

void print_list(linked_list_t *list) {
    node_t *current = list->head;

    while (current!= NULL) {
        printf("Name: %s, Value: %s\n", current->name, current->value);
        current = current->next;
    }
}

void destroy_list(linked_list_t *list) {
    node_t *current = list->head;
    node_t *next;

    while (current!= NULL) {
        next = current->next;
        free(current->name);
        free(current->value);
        free(current);
        current = next;
    }

    free(list);
}

int main() {
    linked_list_t *list = create_list();

    add_node(list, "name1", "value1");
    add_node(list, "name2", "value2");
    add_node(list, "name3", "value3");

    print_list(list);

    destroy_list(list);

    return 0;
}