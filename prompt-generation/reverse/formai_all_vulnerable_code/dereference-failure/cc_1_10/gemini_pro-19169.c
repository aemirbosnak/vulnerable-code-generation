//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 1024

typedef struct {
    char *buffer;
    int size;
    int capacity;
} Buffer;

Buffer *create_buffer() {
    Buffer *buffer = malloc(sizeof(Buffer));
    buffer->buffer = malloc(CHUNK_SIZE);
    buffer->size = 0;
    buffer->capacity = CHUNK_SIZE;
    return buffer;
}

void free_buffer(Buffer *buffer) {
    free(buffer->buffer);
    free(buffer);
}

void write_byte(Buffer *buffer, unsigned char byte) {
    if (buffer->size == buffer->capacity) {
        buffer->capacity *= 2;
        buffer->buffer = realloc(buffer->buffer, buffer->capacity);
    }
    buffer->buffer[buffer->size++] = byte;
}

void write_string(Buffer *buffer, const char *string) {
    int length = strlen(string);
    write_byte(buffer, (unsigned char) length);
    for (int i = 0; i < length; i++) {
        write_byte(buffer, (unsigned char) string[i]);
    }
}

void write_int(Buffer *buffer, int value) {
    write_byte(buffer, (unsigned char) (value >> 24));
    write_byte(buffer, (unsigned char) (value >> 16));
    write_byte(buffer, (unsigned char) (value >> 8));
    write_byte(buffer, (unsigned char) value);
}

unsigned char read_byte(Buffer *buffer) {
    return buffer->buffer[buffer->size++];
}

char *read_string(Buffer *buffer) {
    int length = read_byte(buffer);
    char *string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = read_byte(buffer);
    }
    string[length] = '\0';
    return string;
}

int read_int(Buffer *buffer) {
    return (read_byte(buffer) << 24) | (read_byte(buffer) << 16) | (read_byte(buffer) << 8) | read_byte(buffer);
}

int main() {
    Buffer *buffer = create_buffer();

    write_string(buffer, "Hello, world!");
    write_int(buffer, 12345);

    FILE *file = fopen("test.txt", "wb");
    fwrite(buffer->buffer, 1, buffer->size, file);
    fclose(file);

    free_buffer(buffer);

    return 0;
}