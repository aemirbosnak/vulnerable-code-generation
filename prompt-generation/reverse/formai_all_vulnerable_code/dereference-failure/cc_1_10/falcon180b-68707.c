//Falcon-180B DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *data;
    size_t size;
} buffer_t;

buffer_t *buffer_create(void) {
    buffer_t *buffer = malloc(sizeof(buffer_t));
    buffer->data = malloc(MAX_LINE_SIZE);
    buffer->size = 0;
    return buffer;
}

void buffer_destroy(buffer_t *buffer) {
    free(buffer->data);
    free(buffer);
}

void buffer_append(buffer_t *buffer, const char *data, size_t size) {
    if (buffer->size + size >= MAX_LINE_SIZE) {
        buffer->data = realloc(buffer->data, buffer->size + size + MAX_LINE_SIZE);
        buffer->size += MAX_LINE_SIZE;
    }
    memcpy(buffer->data + buffer->size, data, size);
    buffer->size += size;
}

void buffer_clear(buffer_t *buffer) {
    buffer->size = 0;
}

char *buffer_data(buffer_t *buffer) {
    return buffer->data;
}

size_t buffer_size(buffer_t *buffer) {
    return buffer->size;
}

int main(int argc, char **argv) {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    buffer_t *buffer = buffer_create();
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        buffer_append(buffer, &ch, 1);
    }
    fclose(file);

    printf("File content:\n%s", buffer_data(buffer));

    buffer_destroy(buffer);
    return 0;
}