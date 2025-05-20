//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint32_t width;
    uint32_t height;
    uint8_t *data;
} Image;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    Image *image = malloc(sizeof(Image));
    image->data = malloc(size);
    fread(image->data, 1, size, fp);

    fclose(fp);

    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void hide_message(Image *image, const char *message) {
    int message_length = strlen(message);

    for (int i = 0; i < message_length; i++) {
        uint8_t byte = message[i];

        for (int j = 0; j < 8; j++) {
            uint8_t bit = (byte >> j) & 1;
            image->data[i * 8 + j] &= 0xFE;
            image->data[i * 8 + j] |= bit;
        }
    }
}

char *reveal_message(Image *image) {
    int message_length = 0;

    for (int i = 0; i < image->width * image->height; i++) {
        if (image->data[i] & 1) {
            message_length++;
        }
    }

    char *message = malloc(message_length + 1);
    int message_index = 0;

    for (int i = 0; i < image->width * image->height; i++) {
        if (image->data[i] & 1) {
            message[message_index++] = i / 8;
        }
    }

    message[message_length] = '\0';

    return message;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> [message]\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    if (argc == 4) {
        hide_message(image, argv[3]);
    } else {
        char *message = reveal_message(image);
        printf("%s\n", message);
        free(message);
    }

    FILE *fp = fopen(argv[2], "wb");
    fwrite(image->data, 1, image->width * image->height, fp);
    fclose(fp);

    free_image(image);

    return 0;
}