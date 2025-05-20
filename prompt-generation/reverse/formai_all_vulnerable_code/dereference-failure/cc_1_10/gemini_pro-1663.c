//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: shape shifting
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int size;
    int capacity;
} buffer_t;

buffer_t *buffer_create() {
    buffer_t *buffer = malloc(sizeof(buffer_t));
    buffer->data = malloc(1024);
    buffer->size = 0;
    buffer->capacity = 1024;
    return buffer;
}

void buffer_destroy(buffer_t *buffer) {
    free(buffer->data);
    free(buffer);
}

void buffer_append(buffer_t *buffer, const char *data, int size) {
    if (buffer->size + size > buffer->capacity) {
        buffer->data = realloc(buffer->data, buffer->capacity * 2);
        buffer->capacity *= 2;
    }
    memcpy(buffer->data + buffer->size, data, size);
    buffer->size += size;
}

int main() {
    buffer_t *buffer = buffer_create();
    char *input = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas eget lacus eget nunc tincidunt laoreet. Nunc eget lacus eget nunc tincidunt laoreet. Nunc eget lacus eget nunc tincidunt laoreet. Nunc eget lacus eget nunc tincidunt laoreet.";
    buffer_append(buffer, input, strlen(input));

    // Compress the data using a simple run-length encoding algorithm
    int i, j, count;
    char *compressed = malloc(buffer->size);
    j = 0;
    for (i = 0; i < buffer->size; i++) {
        count = 1;
        while (i + 1 < buffer->size && buffer->data[i] == buffer->data[i + 1]) {
            count++;
            i++;
        }
        compressed[j++] = buffer->data[i];
        compressed[j++] = count;
    }

    // Print the compressed data
    printf("Compressed data:\n");
    for (i = 0; i < j; i++) {
        printf("%c", compressed[i]);
    }
    printf("\n");

    // Decompress the data
    char *decompressed = malloc(buffer->size);
    j = 0;
    for (i = 0; i < j; i += 2) {
        memset(decompressed + j, compressed[i], compressed[i + 1]);
        j += compressed[i + 1];
    }

    // Print the decompressed data
    printf("Decompressed data:\n");
    printf("%s\n", decompressed);

    // Free the allocated memory
    free(compressed);
    free(decompressed);
    buffer_destroy(buffer);
    return 0;
}