//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char *data;
    struct node *next;
} node;

typedef struct list {
    node *head;
    node *tail;
} list;

void list_init(list *l) {
    l->head = NULL;
    l->tail = NULL;
}

void list_append(list *l, char *data) {
    node *n = malloc(sizeof(*n));
    if (n == NULL) {
        perror("malloc");
        exit(1);
    }
    n->data = data;
    n->next = NULL;
    if (l->head == NULL) {
        l->head = n;
    } else {
        l->tail->next = n;
    }
    l->tail = n;
}

void list_print(list *l) {
    node *n = l->head;
    while (n != NULL) {
        printf("%s ", n->data);
        n = n->next;
    }
    printf("\n");
}

int main(int argc, char **argv) {
    list l;
    list_init(&l);
    for (int i = 1; i < argc; i++) {
        list_append(&l, argv[i]);
    }
    list_print(&l);
    return 0;
}