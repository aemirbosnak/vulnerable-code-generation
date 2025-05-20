//GEMINI-pro DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int size;
    int capacity;
} buffer_t;

#define BUFFER_INITIAL_CAPACITY 1024

buffer_t *buffer_create() {
    buffer_t *buffer = malloc(sizeof(buffer_t));
    buffer->data = malloc(BUFFER_INITIAL_CAPACITY);
    buffer->size = 0;
    buffer->capacity = BUFFER_INITIAL_CAPACITY;
    return buffer;
}

void buffer_destroy(buffer_t *buffer) {
    free(buffer->data);
    free(buffer);
}

void buffer_write(buffer_t *buffer, const char *data, int size) {
    if (buffer->size + size > buffer->capacity) {
        int new_capacity = buffer->capacity * 2;
        while (buffer->size + size > new_capacity) {
            new_capacity *= 2;
        }
        buffer->data = realloc(buffer->data, new_capacity);
        buffer->capacity = new_capacity;
    }
    memcpy(buffer->data + buffer->size, data, size);
    buffer->size += size;
}

char *buffer_get_data(buffer_t *buffer) {
    return buffer->data;
}

int buffer_get_size(buffer_t *buffer) {
    return buffer->size;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    buffer_t *buffer = buffer_create();

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, file)) != -1) {
        buffer_write(buffer, line, read);
    }
    free(line);

    fclose(file);

    printf("%s", buffer_get_data(buffer));

    buffer_destroy(buffer);

    return EXIT_SUCCESS;
}