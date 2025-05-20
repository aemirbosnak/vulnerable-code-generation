//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10

struct matrix_entry {
    char *key;
    char *value;
};

struct matrix {
    struct matrix_entry *entries;
    int size;
};

void matrix_init(struct matrix *matrix) {
    matrix->entries = NULL;
    matrix->size = 0;
}

void matrix_add(struct matrix *matrix, char *key, char *value) {
    struct matrix_entry *new_entry = malloc(sizeof(struct matrix_entry));
    new_entry->key = strdup(key);
    new_entry->value = strdup(value);
    matrix->entries = realloc(matrix->entries, (matrix->size + 1) * sizeof(struct matrix_entry));
    matrix->entries[matrix->size++] = *new_entry;
}

char *matrix_get(struct matrix *matrix, char *key) {
    for (int i = 0; i < matrix->size; i++) {
        if (strcmp(matrix->entries[i].key, key) == 0) {
            return matrix->entries[i].value;
        }
    }
    return NULL;
}

void matrix_free(struct matrix *matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->entries[i].key);
        free(matrix->entries[i].value);
    }
    free(matrix->entries);
}

int main(int argc, char *argv[]) {
    struct matrix matrix;
    matrix_init(&matrix);

    matrix_add(&matrix, "name", "Neo");
    matrix_add(&matrix, "age", "30");
    matrix_add(&matrix, "city", "Zion");

    printf("Name: %s\n", matrix_get(&matrix, "name"));
    printf("Age: %s\n", matrix_get(&matrix, "age"));
    printf("City: %s\n", matrix_get(&matrix, "city"));

    matrix_free(&matrix);

    return 0;
}