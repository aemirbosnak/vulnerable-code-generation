//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_NAME_LEN 100
#define MAX_NODE_VALUE_LEN 1000

typedef struct node_s {
    char name[MAX_NODE_NAME_LEN];
    char value[MAX_NODE_VALUE_LEN];
    struct node_s *next;
} node_t;

typedef struct {
    node_t *head;
    node_t *tail;
} linked_list_t;

linked_list_t *create_linked_list() {
    linked_list_t *list = (linked_list_t *)malloc(sizeof(linked_list_t));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void add_node(linked_list_t *list, char *name, char *value) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    strncpy(node->name, name, MAX_NODE_NAME_LEN);
    strncpy(node->value, value, MAX_NODE_VALUE_LEN);
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void print_linked_list(linked_list_t *list) {
    node_t *current = list->head;

    while (current!= NULL) {
        printf("Name: %s\nValue: %s\n", current->name, current->value);
        current = current->next;
    }
}

void free_linked_list(linked_list_t *list) {
    node_t *current = list->head;

    while (current!= NULL) {
        node_t *temp = current;
        current = current->next;
        free(temp);
    }

    free(list);
}

int main() {
    linked_list_t *list = create_linked_list();

    add_node(list, "name", "John");
    add_node(list, "age", "30");
    add_node(list, "city", "New York");

    print_linked_list(list);

    free_linked_list(list);

    return 0;
}