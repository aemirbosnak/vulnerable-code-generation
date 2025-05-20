//MISTRAL-7B DATASET v1.0 Category: Image Steganography ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_IMAGE_SIZE 1024 * 1024
#define MESSAGE_SIZE 50

typedef struct RGB {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} RGB;

void read_image(const char *filename, uint8_t **image_data, size_t *image_size) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 2, SEEK_SET);
    size_t file_size = ftell(fp);
    if (file_size > MAX_IMAGE_SIZE) {
        fprintf(stderr, "Image too large\n");
        exit(EXIT_FAILURE);
    }

    *image_size = file_size;
    *image_data = malloc(*image_size);
    fread(*image_data, 1, *image_size, fp);
    fclose(fp);
}

void write_image(const char *filename, const uint8_t *image_data, size_t image_size) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fwrite(image_data, 1, image_size, fp);
    fclose(fp);
}

void embed_message(const char *message, uint8_t *image_data, size_t image_size) {
    size_t i = 0, j = 0;
    for (; i < image_size && j < MESSAGE_SIZE; i++) {
        RGB *pixel = (RGB *) (image_data + i);

        // XOR message bit with LSB of each RGB channel
        if (i % 3)
            pixel->b ^= (message[j++] >> (7 % 8));
        else if (i % 3 == 0)
            pixel->r ^= (message[j++] >> (7 % 8));
        else
            pixel->g ^= (message[j++] >> (7 % 8));
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_image> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    uint8_t *image_data = NULL;
    size_t image_size = 0;
    read_image(argv[1], &image_data, &image_size);

    char message[MESSAGE_SIZE];
    strcpy(message, argv[2]);

    embed_message(message, image_data, image_size);

    write_image("output.bmp", image_data, image_size);

    free(image_data);
    return EXIT_SUCCESS;
}