//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MIN_LENGTH 3

typedef struct {
    unsigned char data[BUFFER_SIZE];
    size_t pos;
} CompressBuffer;

void compress(unsigned char *input, size_t length, CompressBuffer *buffer);
void compress_recursive(unsigned char *input, size_t length, CompressBuffer *buffer);
void write_byte(CompressBuffer *buffer, unsigned char byte);
void write_bytes(CompressBuffer *buffer, unsigned char *bytes, size_t length);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    size_t file_size = fseek(file, 0, SEEK_END);
    rewind(file);

    unsigned char *input = malloc(file_size);
    fread(input, 1, file_size, file);

    CompressBuffer buffer;
    compress(input, file_size, &buffer);

    fwrite(buffer.data, buffer.pos, 1, stdout);

    free(input);
    fclose(file);

    return 0;
}

void compress(unsigned char *input, size_t length, CompressBuffer *buffer) {
    compress_recursive(input, length, buffer);
}

void compress_recursive(unsigned char *input, size_t length, CompressBuffer *buffer) {
    if (length < MIN_LENGTH) {
        write_byte(buffer, *input);
        return;
    }

    unsigned char current = *input;
    size_t count = 1;

    while (++count < length && *++input == current) {}

    write_byte(buffer, count | 0x80);
    write_byte(buffer, current);

    if (count < length) {
        compress_recursive(input, length - count, buffer);
    }
}

void write_byte(CompressBuffer *buffer, unsigned char byte) {
    if (buffer->pos + sizeof(unsigned char) >= BUFFER_SIZE) {
        fprintf(stderr, "Buffer overflow\n");
        exit(1);
    }

    buffer->data[buffer->pos++] = byte;
}

void write_bytes(CompressBuffer *buffer, unsigned char *bytes, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        write_byte(buffer, bytes[i]);
    }
}