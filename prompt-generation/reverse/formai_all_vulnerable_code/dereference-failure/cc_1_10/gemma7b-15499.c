//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CMeta {
    char **data;
    int size;
    int capacity;
} CMeta;

CMeta *cmeta_init(int capacity) {
    CMeta *meta = malloc(sizeof(CMeta));
    meta->data = NULL;
    meta->size = 0;
    meta->capacity = capacity;

    return meta;
}

void cmeta_append(CMeta *meta, char *data) {
    if (meta->size == meta->capacity) {
        meta->data = realloc(meta->data, meta->capacity * 2);
        meta->capacity *= 2;
    }

    meta->data = realloc(meta->data, (meta->size + 1) * sizeof(char *));
    meta->data[meta->size++] = data;
}

void cmeta_free(CMeta *meta) {
    free(meta->data);
    free(meta);
}

int main() {
    CMeta *meta = cmeta_init(10);

    char *data1 = "Hello, world!";
    cmeta_append(meta, data1);

    char *data2 = "This is a second piece of data.";
    cmeta_append(meta, data2);

    for (int i = 0; i < meta->size; i++) {
        printf("%s\n", meta->data[i]);
    }

    cmeta_free(meta);

    return 0;
}