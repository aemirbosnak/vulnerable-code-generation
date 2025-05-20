//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *bytes;
    unsigned int length;
} BinaryBuffer;

BinaryBuffer *binary_buffer_create(unsigned int length) {
    BinaryBuffer *buffer = malloc(sizeof(BinaryBuffer));
    buffer->bytes = malloc(length);
    buffer->length = length;
    return buffer;
}

void binary_buffer_destroy(BinaryBuffer *buffer) {
    free(buffer->bytes);
    free(buffer);
}

void binary_buffer_append(BinaryBuffer *buffer, unsigned char byte) {
    if (buffer->length == 0) {
        buffer->bytes = malloc(1);
        buffer->length = 1;
    } else {
        buffer->bytes = realloc(buffer->bytes, buffer->length + 1);
        buffer->length++;
    }
    buffer->bytes[buffer->length - 1] = byte;
}

unsigned char binary_buffer_get(BinaryBuffer *buffer, unsigned int index) {
    if (index >= buffer->length) {
        printf("Error: Index out of bounds.\n");
        exit(1);
    }
    return buffer->bytes[index];
}

void binary_buffer_set(BinaryBuffer *buffer, unsigned int index, unsigned char byte) {
    if (index >= buffer->length) {
        printf("Error: Index out of bounds.\n");
        exit(1);
    }
    buffer->bytes[index] = byte;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <binary string>\n", argv[0]);
        return 1;
    }

    char *binary_string = argv[1];

    // Create a binary buffer to store the binary data.
    BinaryBuffer *buffer = binary_buffer_create(strlen(binary_string));

    // Convert the binary string to a byte array.
    for (int i = 0; i < strlen(binary_string); i++) {
        if (binary_string[i] == '0') {
            binary_buffer_append(buffer, 0);
        } else if (binary_string[i] == '1') {
            binary_buffer_append(buffer, 1);
        } else {
            printf("Error: Invalid binary string.\n");
            return 1;
        }
    }

    // Print the binary data in hexadecimal format.
    printf("Binary data (hex): ");
    for (int i = 0; i < buffer->length; i++) {
        printf("%02X", binary_buffer_get(buffer, i));
    }
    printf("\n");

    // Destroy the binary buffer.
    binary_buffer_destroy(buffer);

    return 0;
}