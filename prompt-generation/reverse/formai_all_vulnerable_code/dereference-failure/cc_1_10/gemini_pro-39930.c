//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *value;
    struct node *next;
} node;

typedef struct {
    node *head;
    node *tail;
} list;

void list_init(list *l) {
    l->head = NULL;
    l->tail = NULL;
}

void list_append(list *l, char *value) {
    node *n = malloc(sizeof(node));
    n->value = strdup(value);
    n->next = NULL;

    if (l->head == NULL) {
        l->head = n;
        l->tail = n;
    } else {
        l->tail->next = n;
        l->tail = n;
    }
}

void list_print(list *l) {
    node *n = l->head;
    while (n != NULL) {
        printf("%s\n", n->value);
        n = n->next;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        perror("fopen");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    list l;
    list_init(&l);

    while ((read = getline(&line, &len, f)) != -1) {
        char *value = strdup(line);
        list_append(&l, value);
    }

    free(line);
    fclose(f);

    list_print(&l);

    return 0;
}