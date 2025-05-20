//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 20

typedef struct {
    size_t capacity;
    size_t size;
    char* buffer;
} CircularBuffer;

CircularBuffer cb;
char* strings[BUFFER_SIZE];
size_t string_index = 0;

void init_buffer(CircularBuffer* cb) {
    cb->capacity = BUFFER_SIZE;
    cb->size = 0;
    cb->buffer = calloc(BUFFER_SIZE, sizeof(char) * BUFFER_SIZE);
    if (!cb->buffer) {
        fprintf(stderr, "Error allocating buffer\n");
        exit(EXIT_FAILURE);
    }
}

void destroy_buffer(CircularBuffer* cb) {
    free(cb->buffer);
}

void put_string(const char* str) {
    size_t len = strlen(str) + 1;

    if (cb.size + len > cb.capacity) {
        fprintf(stderr, "Buffer is full\n");
        return;
    }

    memcpy(cb.buffer + string_index * BUFFER_SIZE, str, len * sizeof(char));
    strings[string_index] = cb.buffer + string_index * BUFFER_SIZE;
    cb.size += len;
    string_index = (string_index + 1) % BUFFER_SIZE;
}

int main() {
    init_buffer(&cb);

    put_string("Hello");
    put_string("World");
    put_string("This");
    put_string("is");
    put_string("a");
    put_string("test");

    for (size_t i = 0; i < cb.size / BUFFER_SIZE; ++i) {
        printf("%s\n", strings[i]);
        free(strings[i]);
    }

    destroy_buffer(&cb);

    return EXIT_SUCCESS;
}