//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t *data;
    size_t size;
} buffer;

buffer load_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);
    uint8_t *data = malloc(size);
    if (data == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    fread(data, size, 1, fp);
    fclose(fp);
    return (buffer){data, size};
}

void write_file(const char *filename, buffer data) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fwrite(data.data, data.size, 1, fp);
    fclose(fp);
}

void embed_message(buffer image, buffer message) {
    for (size_t i = 0; i < message.size; i++) {
        for (size_t j = 0; j < 8; j++) {
            image.data[(i * 8) + j] = (image.data[(i * 8) + j] & 0xfe) | ((message.data[i] >> j) & 0x01);
        }
    }
}

buffer extract_message(buffer image) {
    size_t size = image.size / 8;
    uint8_t *data = malloc(size);
    if (data == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < size; i++) {
        data[i] = 0;
        for (size_t j = 0; j < 8; j++) {
            data[i] |= (image.data[(i * 8) + j] & 0x01) << j;
        }
    }
    return (buffer){data, size};
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input image> <output image> <message file> <embed/extract>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    buffer image = load_file(argv[1]);
    buffer message = load_file(argv[3]);
    if (strcmp(argv[4], "embed") == 0) {
        embed_message(image, message);
    } else if (strcmp(argv[4], "extract") == 0) {
        message = extract_message(image);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[4]);
        exit(EXIT_FAILURE);
    }
    write_file(argv[2], image);
    write_file(argv[3], message);
    return EXIT_SUCCESS;
}