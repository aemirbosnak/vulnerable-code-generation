//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node_t {
    char *word;
    int count;
    struct node_t *next;
} node_t;

typedef struct map_t {
    node_t **table;
    size_t size;
} map_t;

static inline size_t hash(const char *key, size_t size) {
    size_t h = 0;
    for (size_t i = 0; key[i] != '\0'; i++) {
        h = (h << 5) - h + key[i];
    }
    return h % size;
}

map_t *map_new(size_t size) {
    map_t *map = malloc(sizeof(map_t));
    if (map == NULL) {
        return NULL;
    }
    map->table = calloc(size, sizeof(node_t *));
    if (map->table == NULL) {
        free(map);
        return NULL;
    }
    map->size = size;
    return map;
}

void map_free(map_t *map) {
    for (size_t i = 0; i < map->size; i++) {
        node_t *node = map->table[i];
        while (node != NULL) {
            node_t *next = node->next;
            free(node->word);
            free(node);
            node = next;
        }
    }
    free(map->table);
    free(map);
}

bool map_insert(map_t *map, const char *key, int value) {
    size_t index = hash(key, map->size);
    node_t *node = map->table[index];
    while (node != NULL) {
        if (strcmp(node->word, key) == 0) {
            node->count += value;
            return true;
        }
        node = node->next;
    }
    node = malloc(sizeof(node_t));
    if (node == NULL) {
        return false;
    }
    node->word = strdup(key);
    if (node->word == NULL) {
        free(node);
        return false;
    }
    node->count = value;
    node->next = map->table[index];
    map->table[index] = node;
    return true;
}

int map_get(map_t *map, const char *key) {
    size_t index = hash(key, map->size);
    node_t *node = map->table[index];
    while (node != NULL) {
        if (strcmp(node->word, key) == 0) {
            return node->count;
        }
        node = node->next;
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s FILE\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    map_t *map = map_new(1024);
    if (map == NULL) {
        fprintf(stderr, "map_new failed\n");
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char *word = strtok(buffer, " \n\t");
        while (word != NULL) {
            map_insert(map, word, 1);
            word = strtok(NULL, " \n\t");
        }
    }

    fclose(file);

    for (size_t i = 0; i < map->size; i++) {
        node_t *node = map->table[i];
        while (node != NULL) {
            printf("%s: %d\n", node->word, node->count);
            node = node->next;
        }
    }

    map_free(map);

    return 0;
}