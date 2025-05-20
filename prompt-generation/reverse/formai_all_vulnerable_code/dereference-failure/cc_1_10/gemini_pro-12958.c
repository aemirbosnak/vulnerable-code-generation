//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint32_t width;
    uint32_t height;
    uint8_t *data;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(uint32_t), 1, fp);
    fread(&image->height, sizeof(uint32_t), 1, fp);

    image->data = malloc(image->width * image->height * 3);
    if (!image->data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->data, image->width * image->height * 3, 1, fp);
    fclose(fp);

    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return;
    }

    fwrite(&image->width, sizeof(uint32_t), 1, fp);
    fwrite(&image->height, sizeof(uint32_t), 1, fp);
    fwrite(image->data, image->width * image->height * 3, 1, fp);
    fclose(fp);
}

void hide_message(Image *image, const char *message) {
    uint8_t *data = image->data;
    size_t message_len = strlen(message);

    for (size_t i = 0; i < message_len; i++) {
        uint8_t byte = message[i];

        for (size_t j = 0; j < 8; j++) {
            uint8_t bit = (byte >> j) & 1;
            data[i * 8 + j] |= bit;
        }
    }
}

char *extract_message(const Image *image) {
    uint8_t *data = image->data;
    size_t message_len = image->width * image->height * 3 / 8;
    char *message = malloc(message_len + 1);
    if (!message) {
        fprintf(stderr, "Error: could not allocate memory for message\n");
        return NULL;
    }

    for (size_t i = 0; i < message_len; i++) {
        uint8_t byte = 0;

        for (size_t j = 0; j < 8; j++) {
            uint8_t bit = data[i * 8 + j] & 1;
            byte |= (bit << j);
        }

        message[i] = byte;
    }

    message[message_len] = '\0';
    return message;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        return EXIT_FAILURE;
    }

    hide_message(image, argv[3]);
    write_image(image, argv[2]);
    free(image);

    image = read_image(argv[2]);
    if (!image) {
        return EXIT_FAILURE;
    }

    char *message = extract_message(image);
    if (!message) {
        free(image);
        return EXIT_FAILURE;
    }

    printf("Extracted message: %s\n", message);
    free(message);
    free(image);

    return EXIT_SUCCESS;
}