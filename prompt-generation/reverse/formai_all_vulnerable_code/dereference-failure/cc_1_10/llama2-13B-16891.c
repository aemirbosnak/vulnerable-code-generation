//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define BUFFER_SIZE 64

typedef struct {
    char *buffer;
    size_t length;
} compression_buffer_t;

void compression_init(compression_buffer_t *buffer) {
    buffer->buffer = (char *)calloc(1, BUFFER_SIZE);
    buffer->length = 0;
}

void compression_append(compression_buffer_t *buffer, const char *data, size_t size) {
    size_t remaining = BUFFER_SIZE - buffer->length;
    if (remaining < size) {
        buffer->buffer = (char *)realloc(buffer->buffer, remaining + size);
    }
    memcpy(buffer->buffer + buffer->length, data, size);
    buffer->length += size;
}

void compression_flush(compression_buffer_t *buffer) {
    if (buffer->length > 0) {
        compression_append(buffer, NULL, 0);
    }
}

size_t compression_get_length(compression_buffer_t *buffer) {
    return buffer->length;
}

int main() {
    compression_buffer_t buffer;
    compression_init(&buffer);

    char data[] = "The quick brown fox jumps over the lazy dog";
    size_t data_len = strlen(data);
    compression_append(&buffer, data, data_len);

    char *compressed = (char *)calloc(1, buffer.length);
    compression_flush(&buffer);
    memcpy(compressed, buffer.buffer, buffer.length);

    printf("Original string: %s\n", data);
    printf("Compressed string: %s\n", compressed);

    free(compressed);
    return 0;
}