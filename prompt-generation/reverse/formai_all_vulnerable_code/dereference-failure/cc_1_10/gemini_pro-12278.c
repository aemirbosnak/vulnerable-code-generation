//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    size_t length;
} Buffer;

Buffer *buffer_create(size_t length) {
    Buffer *buffer = malloc(sizeof(Buffer));
    if (buffer == NULL) {
        return NULL;
    }
    buffer->data = malloc(length);
    if (buffer->data == NULL) {
        free(buffer);
        return NULL;
    }
    buffer->length = length;
    return buffer;
}

void buffer_destroy(Buffer *buffer) {
    if (buffer == NULL) {
        return;
    }
    free(buffer->data);
    free(buffer);
}

int buffer_read_file(Buffer *buffer, FILE *file) {
    if (buffer == NULL || file == NULL) {
        return -1;
    }
    size_t bytes_read = fread(buffer->data, 1, buffer->length, file);
    if (bytes_read != buffer->length) {
        return -1;
    }
    return 0;
}

int buffer_write_file(Buffer *buffer, FILE *file) {
    if (buffer == NULL || file == NULL) {
        return -1;
    }
    size_t bytes_written = fwrite(buffer->data, 1, buffer->length, file);
    if (bytes_written != buffer->length) {
        return -1;
    }
    return 0;
}

int buffer_encrypt(Buffer *buffer, unsigned char *key, size_t key_length) {
    if (buffer == NULL || key == NULL || key_length == 0) {
        return -1;
    }
    for (size_t i = 0; i < buffer->length; i++) {
        buffer->data[i] ^= key[i % key_length];
    }
    return 0;
}

int buffer_decrypt(Buffer *buffer, unsigned char *key, size_t key_length) {
    if (buffer == NULL || key == NULL || key_length == 0) {
        return -1;
    }
    for (size_t i = 0; i < buffer->length; i++) {
        buffer->data[i] ^= key[i % key_length];
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input file> <output file> <key>\n", argv[0]);
        return -1;
    }
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input file: %s\n", argv[1]);
        return -1;
    }
    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", argv[2]);
        return -1;
    }
    size_t key_length = strlen(argv[3]);
    Buffer *buffer = buffer_create(1024);
    if (buffer == NULL) {
        printf("Error creating buffer\n");
        return -1;
    }
    while (buffer_read_file(buffer, input_file) == 0) {
        buffer_encrypt(buffer, argv[3], key_length);
        buffer_write_file(buffer, output_file);
    }
    buffer_destroy(buffer);
    fclose(input_file);
    fclose(output_file);
    return 0;
}