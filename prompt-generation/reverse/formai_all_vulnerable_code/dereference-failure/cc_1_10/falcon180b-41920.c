//Falcon-180B DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 1000

typedef struct {
    size_t size;
    char *data;
} chunk_t;

chunk_t *create_chunk(size_t size) {
    chunk_t *chunk = (chunk_t *) malloc(sizeof(chunk_t));
    if (chunk!= NULL) {
        chunk->size = size;
        chunk->data = (char *) malloc(size);
        if (chunk->data == NULL) {
            free(chunk);
            chunk = NULL;
        }
    }

    return chunk;
}

void destroy_chunk(chunk_t *chunk) {
    if (chunk!= NULL) {
        free(chunk->data);
        free(chunk);
    }
}

void *my_malloc(size_t size) {
    chunk_t *chunk = create_chunk(size);
    if (chunk!= NULL) {
        return chunk->data;
    }

    return NULL;
}

void my_free(void *ptr) {
    chunk_t *chunk = (chunk_t *) ptr - sizeof(chunk_t);
    destroy_chunk(chunk);
}

int main() {
    char *str1 = (char *) my_malloc(10);
    strcpy(str1, "Hello");

    char *str2 = (char *) my_malloc(15);
    strcpy(str2, "World!");

    printf("%s %s\n", str1, str2);

    my_free(str1);
    my_free(str2);

    return 0;
}