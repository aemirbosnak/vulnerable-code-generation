//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _node {
    char *name;
    struct _node *next;
} node;

typedef struct _list {
    node *head;
    node *tail;
} list;

void list_init(list *l) {
    l->head = NULL;
    l->tail = NULL;
}

void list_add(list *l, char *name) {
    node *n = malloc(sizeof(node));
    n->name = strdup(name);
    n->next = NULL;
    if (l->tail == NULL) {
        l->head = n;
        l->tail = n;
    } else {
        l->tail->next = n;
        l->tail = n;
    }
}

void list_free(list *l) {
    node *n = l->head;
    while (n != NULL) {
        node *next = n->next;
        free(n->name);
        free(n);
        n = next;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *file = argv[1];

    FILE *f = fopen(file, "r");
    if (f == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    list l;
    list_init(&l);

    char line[1024];
    while (fgets(line, sizeof(line), f) != NULL) {
        char *name = strtok(line, "\n");
        list_add(&l, name);
    }

    fclose(f);

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    char backup_file[1024];
    snprintf(backup_file, sizeof(backup_file), "%s.%d-%02d-%02d_%02d-%02d-%02d.txt", file, tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);

    f = fopen(backup_file, "w");
    if (f == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    node *n = l.head;
    while (n != NULL) {
        fprintf(f, "%s\n", n->name);
        n = n->next;
    }

    fclose(f);

    list_free(&l);

    return EXIT_SUCCESS;
}