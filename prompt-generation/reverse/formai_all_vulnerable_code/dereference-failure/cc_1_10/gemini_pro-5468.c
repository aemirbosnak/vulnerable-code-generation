//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int size;
} Buffer;

Buffer *read_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    Buffer *buffer = malloc(sizeof(Buffer));
    buffer->data = malloc(size);
    buffer->size = size;

    if (fread(buffer->data, 1, size, fp) != size) {
        perror("fread");
        exit(EXIT_FAILURE);
    }

    fclose(fp);
    return buffer;
}

void write_file(const char *filename, Buffer *buffer) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    if (fwrite(buffer->data, 1, buffer->size, fp) != buffer->size) {
        perror("fwrite");
        exit(EXIT_FAILURE);
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image> <message> <output>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Buffer *image = read_file(argv[1]);
    Buffer *message = read_file(argv[2]);

    // Paranoid mode: encrypt the message using a simple XOR cipher
    for (int i = 0; i < message->size; i++) {
        message->data[i] ^= 0x55;
    }

    // Hide the message in the image's least significant bits
    for (int i = 0; i < message->size; i++) {
        image->data[i] &= 0xF0;
        image->data[i] |= message->data[i] >> 4;
    }

    // Write the stegged image to a file
    write_file(argv[3], image);

    // Release memory
    free(image->data);
    free(image);
    free(message->data);
    free(message);

    return EXIT_SUCCESS;
}