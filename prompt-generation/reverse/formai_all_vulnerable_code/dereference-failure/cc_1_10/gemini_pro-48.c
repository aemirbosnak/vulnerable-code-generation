//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#define CHUNK_SIZE 512

typedef struct {
    uint8_t *data;
    size_t size;
} Buffer;

Buffer *create_buffer(size_t size)
{
    Buffer *buffer = malloc(sizeof(Buffer));
    if (!buffer) {
        return NULL;
    }
    buffer->data = malloc(size);
    if (!buffer->data) {
        free(buffer);
        return NULL;
    }
    buffer->size = size;
    return buffer;
}

void destroy_buffer(Buffer *buffer)
{
    if (buffer) {
        if (buffer->data) {
            free(buffer->data);
            buffer->data = NULL;
        }
        free(buffer);
        buffer = NULL;
    }
}

int main(int argc, char **argv)
{
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input-image> <output-image> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    fseek(input_file, 0, SEEK_END);
    size_t input_file_size = ftell(input_file);
    rewind(input_file);

    Buffer *input_buffer = create_buffer(input_file_size);
    if (!input_buffer) {
        fclose(input_file);
        return EXIT_FAILURE;
    }
    fread(input_buffer->data, input_file_size, 1, input_file);
    fclose(input_file);

    size_t message_length = strlen(argv[3]);
    if (message_length > (input_file_size - CHUNK_SIZE)) {
        fprintf(stderr, "Message too long\n");
        destroy_buffer(input_buffer);
        return EXIT_FAILURE;
    }

    for (size_t i = CHUNK_SIZE; i < input_file_size; i++) {
        if (i % CHUNK_SIZE == 0) {
            if (message_length == 0) {
                break;
            }
            input_buffer->data[i] = argv[3][message_length - 1];
            message_length--;
        } else {
            input_buffer->data[i] = input_buffer->data[i] & 0xFE;
        }
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        perror("fopen");
        destroy_buffer(input_buffer);
        return EXIT_FAILURE;
    }
    fwrite(input_buffer->data, input_file_size, 1, output_file);
    fclose(output_file);

    destroy_buffer(input_buffer);
    return EXIT_SUCCESS;
}