//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    int value;
    struct node *next;
} node_t;

typedef struct index {
    char *name;
    node_t *head;
} index_t;

index_t *create_index(char *name) {
    index_t *index = malloc(sizeof(index_t));
    index->name = strdup(name);
    index->head = NULL;
    return index;
}

void insert_index(index_t *index, char *key, int value) {
    node_t *node = malloc(sizeof(node_t));
    node->key = strdup(key);
    node->value = value;
    node->next = NULL;

    if (index->head == NULL) {
        index->head = node;
    } else {
        node->next = index->head;
        index->head = node;
    }
}

int find_index(index_t *index, char *key) {
    node_t *node = index->head;

    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }

    return -1;
}

void print_index(index_t *index) {
    node_t *node = index->head;

    while (node != NULL) {
        printf("%s: %d\n", node->key, node->value);
        node = node->next;
    }
}

int main() {
    index_t *index = create_index("my_index");

    insert_index(index, "key1", 1);
    insert_index(index, "key2", 2);
    insert_index(index, "key3", 3);

    print_index(index);

    printf("Value of key1: %d\n", find_index(index, "key1"));

    return 0;
}