//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    void *data;
    struct _node *next;
} node;

typedef struct _list {
    node *head;
    node *tail;
} list;

void list_init(list *l) {
    l->head = l->tail = NULL;
}

void list_append(list *l, void *data) {
    node *n = malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    if (l->tail) {
        l->tail->next = n;
    }
    l->tail = n;
    if (!l->head) {
        l->head = n;
    }
}

void list_free(list *l) {
    node *n = l->head;
    while (n) {
        node *next = n->next;
        free(n->data);
        free(n);
        n = next;
    }
    l->head = l->tail = NULL;
}

int main() {
    list l;
    list_init(&l);

    // Add some data to the list
    for (int i = 0; i < 10; i++) {
        int *data = malloc(sizeof(int));
        *data = i;
        list_append(&l, data);
    }

    // Print the data in the list
    node *n = l.head;
    while (n) {
        printf("%d\n", *(int *)n->data);
        n = n->next;
    }

    // Free the list
    list_free(&l);

    return 0;
}