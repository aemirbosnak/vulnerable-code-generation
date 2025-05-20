//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    int data;
    struct _node *next;
} node;

typedef struct _list {
    node *head;
    node *tail;
} list;

void insert_at_head(list *l, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = l->head;
    l->head = new_node;
    if (l->tail == NULL) {
        l->tail = new_node;
    }
}

void insert_at_tail(list *l, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (l->tail == NULL) {
        l->head = new_node;
        l->tail = new_node;
    } else {
        l->tail->next = new_node;
        l->tail = new_node;
    }
}

void print_list(list *l) {
    node *current = l->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    list *l = malloc(sizeof(list));
    l->head = NULL;
    l->tail = NULL;

    insert_at_head(l, 1);
    insert_at_head(l, 2);
    insert_at_tail(l, 3);
    insert_at_tail(l, 4);

    print_list(l);

    return 0;
}