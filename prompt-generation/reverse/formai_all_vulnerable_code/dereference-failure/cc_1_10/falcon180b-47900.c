//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_KEYS 1000
#define MAX_VALUES 1000

typedef struct {
    char *key;
    int value;
} node_t;

typedef struct {
    node_t *nodes[MAX_NODES];
    int num_nodes;
} index_t;

void index_init(index_t *index) {
    index->num_nodes = 0;
}

int index_add(index_t *index, char *key, int value) {
    node_t *node = malloc(sizeof(node_t));
    if (node == NULL) {
        return -1;
    }
    node->key = strdup(key);
    node->value = value;
    index->nodes[index->num_nodes++] = node;
    return 0;
}

int index_search(index_t *index, char *key, int *value) {
    int i;
    for (i = 0; i < index->num_nodes; i++) {
        node_t *node = index->nodes[i];
        if (strcmp(node->key, key) == 0) {
            *value = node->value;
            return 0;
        }
    }
    return -1;
}

void index_destroy(index_t *index) {
    int i;
    for (i = 0; i < index->num_nodes; i++) {
        node_t *node = index->nodes[i];
        free(node->key);
        free(node);
    }
    index->num_nodes = 0;
}

int main() {
    index_t index;
    index_init(&index);

    index_add(&index, "John", 123);
    index_add(&index, "Jane", 456);
    index_add(&index, "Alice", 789);

    int value;
    index_search(&index, "Jane", &value);
    printf("Value for Jane: %d\n", value);

    index_destroy(&index);

    return 0;
}