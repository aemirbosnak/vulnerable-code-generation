//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    char *data;
    int size;
} Buffer;

Buffer *create_buffer(int size) {
    Buffer *buffer = malloc(sizeof(Buffer));
    buffer->data = malloc(size);
    buffer->size = size;
    return buffer;
}

void free_buffer(Buffer *buffer) {
    free(buffer->data);
    free(buffer);
}

int compress(Buffer *input, Buffer *output) {
    int i, j, k;
    char *in_ptr = input->data;
    char *out_ptr = output->data;

    for (i = 0; i < input->size; i++) {
        for (j = i + 1; j < input->size; j++) {
            if (in_ptr[i] == in_ptr[j]) {
                k = j - i;
                while (k > 255) {
                    *out_ptr++ = 0xFF;
                    k -= 255;
                }
                *out_ptr++ = k;
                *out_ptr++ = in_ptr[i];
                i = j;
                break;
            }
        }
        *out_ptr++ = in_ptr[i];
    }

    return out_ptr - output->data;
}

int decompress(Buffer *input, Buffer *output) {
    int i, j, k;
    char *in_ptr = input->data;
    char *out_ptr = output->data;

    while (*in_ptr) {
        if (*in_ptr == 0xFF) {
            in_ptr++;
            k = *in_ptr++ + 255;
        } else {
            k = *in_ptr++;
        }
        for (i = 0; i < k; i++) {
            *out_ptr++ = *in_ptr;
        }
    }

    return out_ptr - output->data;
}

int main() {
    Buffer *input = create_buffer(MAX_SIZE);
    Buffer *output = create_buffer(MAX_SIZE);

    printf("Enter text to compress:\n");
    fgets(input->data, MAX_SIZE, stdin);

    int compressed_size = compress(input, output);
    printf("Compressed size: %d\n", compressed_size);

    Buffer *decompressed = create_buffer(MAX_SIZE);
    int decompressed_size = decompress(output, decompressed);
    printf("Decompressed size: %d\n", decompressed_size);

    printf("Decompressed text:\n%s", decompressed->data);

    free_buffer(input);
    free_buffer(output);
    free_buffer(decompressed);

    return 0;
}