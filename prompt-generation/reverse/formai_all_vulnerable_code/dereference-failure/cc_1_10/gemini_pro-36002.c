//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

#define CHUNK_SIZE 1024

typedef struct {
    byte *data;
    int length;
} buffer;

buffer *new_buffer(int size) {
    buffer *b = malloc(sizeof(buffer));
    b->data = malloc(size);
    b->length = 0;
    return b;
}

void free_buffer(buffer *b) {
    free(b->data);
    free(b);
}

void write_byte(buffer *b, byte c) {
    if (b->length == CHUNK_SIZE) {
        b->data = realloc(b->data, 2 * CHUNK_SIZE);
    }
    b->data[b->length++] = c;
}

void write_int(buffer *b, int i) {
    write_byte(b, i >> 24);
    write_byte(b, i >> 16);
    write_byte(b, i >> 8);
    write_byte(b, i);
}

void write_string(buffer *b, const char *s) {
    int len = strlen(s);
    write_int(b, len);
    for (int i = 0; i < len; i++) {
        write_byte(b, s[i]);
    }
}

buffer *compress(const char *input) {
    buffer *b = new_buffer(CHUNK_SIZE);
    int prev = -1;
    int count = 0;
    for (int i = 0; input[i]; i++) {
        if (input[i] == prev) {
            count++;
        } else {
            if (count > 0) {
                write_byte(b, prev);
                write_int(b, count);
            }
            prev = input[i];
            count = 1;
        }
    }
    if (count > 0) {
        write_byte(b, prev);
        write_int(b, count);
    }
    return b;
}

char *decompress(buffer *b) {
    char *output = malloc(CHUNK_SIZE);
    int output_length = 0;
    int prev = -1;
    int count = 0;
    for (int i = 0; i < b->length; i++) {
        byte c = b->data[i];
        if (prev == -1) {
            prev = c;
            count = 1;
        } else if (prev == c) {
            count++;
        } else {
            for (int j = 0; j < count; j++) {
                output[output_length++] = prev;
            }
            prev = c;
            count = 1;
        }
    }
    for (int j = 0; j < count; j++) {
        output[output_length++] = prev;
    }
    return output;
}

int main() {
    buffer *compressed = compress("Hello world!");
    char *decompressed = decompress(compressed);
    printf("%s\n", decompressed);
    free_buffer(compressed);
    free(decompressed);
    return 0;
}