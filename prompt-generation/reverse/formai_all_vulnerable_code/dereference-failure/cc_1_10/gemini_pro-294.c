//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t *data;
    size_t size;
} Buffer;

Buffer* read_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    rewind(file);

    uint8_t *data = malloc(size);
    if (!data) return NULL;

    fread(data, 1, size, file);
    fclose(file);

    return &(Buffer){data, size};
}

void write_file(const char *filename, const Buffer *buffer) {
    FILE *file = fopen(filename, "wb");
    if (!file) return;

    fwrite(buffer->data, 1, buffer->size, file);
    fclose(file);
}

Buffer* get_lsb(const Buffer *buffer) {
    size_t size = buffer->size / 8;
    uint8_t *data = malloc(size);
    if (!data) return NULL;

    for (size_t i = 0; i < size; i++) {
        data[i] = 0;
        for (size_t j = 0; j < 8; j++) {
            data[i] |= (buffer->data[i * 8 + j] & 1) << j;
        }
    }

    return &(Buffer){data, size};
}

Buffer* set_lsb(const Buffer *buffer, const Buffer *lsb) {
    size_t size = buffer->size / 8;
    uint8_t *data = malloc(size);
    if (!data) return NULL;

    for (size_t i = 0; i < size; i++) {
        data[i] = buffer->data[i * 8];
        for (size_t j = 0; j < 8; j++) {
            data[i * 8 + j] |= (lsb->data[i] & (1 << j)) >> j;
        }
    }

    return &(Buffer){data, size};
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <image.bmp> <message.txt> <output.bmp>\n", argv[0]);
        return 1;
    }

    Buffer *image = read_file(argv[1]);
    if (!image) {
        printf("Error reading image file.\n");
        return 1;
    }

    Buffer *message = read_file(argv[2]);
    if (!message) {
        printf("Error reading message file.\n");
        return 1;
    }

    Buffer *lsb = get_lsb(image);
    if (!lsb) {
        printf("Error getting LSBs from image.\n");
        return 1;
    }

    if (message->size > lsb->size) {
        printf("Message is too large for image.\n");
        return 1;
    }

    Buffer *stego = set_lsb(image, message);
    if (!stego) {
        printf("Error setting LSBs in image.\n");
        return 1;
    }

    write_file(argv[3], stego);
    printf("Message hidden in image.\n");

    return 0;
}