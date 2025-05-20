//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024 * 1024 * 10 // 10 MB

typedef struct {
    char *data;
    int size;
} buffer_t;

buffer_t *buffer_create() {
    buffer_t *buffer = malloc(sizeof(buffer_t));
    buffer->data = malloc(MAX_SIZE);
    buffer->size = 0;
    return buffer;
}

void buffer_destroy(buffer_t *buffer) {
    free(buffer->data);
    free(buffer);
}

void buffer_write(buffer_t *buffer, const char *data, int size) {
    if (buffer->size + size >= MAX_SIZE) {
        fprintf(stderr, "Buffer overflow\n");
        exit(1);
    }
    memcpy(buffer->data + buffer->size, data, size);
    buffer->size += size;
}

int buffer_read(buffer_t *buffer, char *data, int size) {
    int bytes_read = 0;
    if (buffer->size == 0) {
        return 0;
    }
    if (size > buffer->size) {
        size = buffer->size;
    }
    memcpy(data, buffer->data, size);
    buffer->size -= size;
    bytes_read = size;
    return bytes_read;
}

int main() {
    buffer_t *buffer = buffer_create();
    char *data = "This is a test of the buffer component.";
    int data_size = strlen(data);

    buffer_write(buffer, data, data_size);
    char read_data[data_size];
    int bytes_read = buffer_read(buffer, read_data, data_size);

    printf("Original data: %s\n", data);
    printf("Read data: %s\n", read_data);

    buffer_destroy(buffer);
    return 0;
}