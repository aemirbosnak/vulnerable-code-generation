//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t size;
} Buffer;

Buffer *buffer_create(size_t size) {
    Buffer *buffer = malloc(sizeof(Buffer));
    buffer->data = malloc(size);
    buffer->size = size;
    return buffer;
}

void buffer_destroy(Buffer *buffer) {
    free(buffer->data);
    free(buffer);
}

void buffer_write(Buffer *buffer, const void *data, size_t size) {
    memcpy(buffer->data, data, size);
}

void buffer_read(Buffer *buffer, void *data, size_t size) {
    memcpy(data, buffer->data, size);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("fopen");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0, SEEK_SET);

    Buffer *buffer = buffer_create(size);
    fread(buffer->data, 1, size, file);
    fclose(file);

    // Do something with the data in the buffer

    buffer_destroy(buffer);

    return 0;
}