//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_IMAGE_SIZE (1024 * 1024)
#define MAX_MESSAGE_SIZE (1024)

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} pixel_t;

typedef struct {
    uint32_t width;
    uint32_t height;
    uint8_t *data;
} image_t;

typedef struct {
    uint8_t *data;
    size_t size;
} message_t;

image_t *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    image_t *image = malloc(sizeof(image_t));
    if (image == NULL) {
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(uint32_t), 1, fp);
    fread(&image->height, sizeof(uint32_t), 1, fp);

    image->data = malloc(image->width * image->height * sizeof(pixel_t));
    if (image->data == NULL) {
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->data, sizeof(pixel_t), image->width * image->height, fp);
    fclose(fp);

    return image;
}

void save_image(const char *filename, image_t *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    fwrite(&image->width, sizeof(uint32_t), 1, fp);
    fwrite(&image->height, sizeof(uint32_t), 1, fp);
    fwrite(image->data, sizeof(pixel_t), image->width * image->height, fp);
    fclose(fp);
}

message_t *load_message(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    message_t *message = malloc(sizeof(message_t));
    if (message == NULL) {
        fclose(fp);
        return NULL;
    }

    message->data = malloc(size);
    if (message->data == NULL) {
        fclose(fp);
        free(message);
        return NULL;
    }

    fread(message->data, size, 1, fp);
    fclose(fp);

    return message;
}

void save_message(const char *filename, message_t *message) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    fwrite(message->data, message->size, 1, fp);
    fclose(fp);
}

void hide_message(image_t *image, message_t *message) {
    if (message->size > image->width * image->height * 3) {
        return;
    }

    uint8_t *data = image->data;
    for (size_t i = 0; i < message->size; i++) {
        uint8_t byte = message->data[i];
        for (int j = 0; j < 8; j++) {
            uint8_t bit = (byte >> j) & 1;
            *data++ = (*data & 0xfe) | bit;
        }
    }
}

message_t *extract_message(image_t *image) {
    uint8_t *data = image->data;
    size_t size = 0;
    for (size_t i = 0; i < image->width * image->height * 3; i++) {
        if (*data++ & 1) {
            size++;
        }
    }

    message_t *message = malloc(sizeof(message_t));
    if (message == NULL) {
        return NULL;
    }

    message->data = malloc(size);
    if (message->data == NULL) {
        free(message);
        return NULL;
    }

    data = image->data;
    uint8_t byte = 0;
    for (size_t i = 0; i < size; i++) {
        for (int j = 0; j < 8; j++) {
            byte |= (*data++ & 1) << j;
        }
        message->data[i] = byte;
        byte = 0;
    }

    return message;
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input image> <output image> <input message> <output message>\n", argv[0]);
        return 1;
    }

    image_t *image = load_image(argv[1]);
    if (image == NULL) {
        fprintf(stderr, "Failed to load image: %s\n", argv[1]);
        return 1;
    }

    message_t *message = load_message(argv[3]);
    if (message == NULL) {
        fprintf(stderr, "Failed to load message: %s\n", argv[3]);
        return 1;
    }

    hide_message(image, message);
    save_image(argv[2], image);

    message_t *extracted_message = extract_message(image);
    if (extracted_message == NULL) {
        fprintf(stderr, "Failed to extract message from image: %s\n", argv[2]);
        return 1;
    }

    save_message(argv[4], extracted_message);

    free(image->data);
    free(image);
    free(message->data);
    free(message);
    free(extracted_message->data);
    free(extracted_message);

    return 0;
}