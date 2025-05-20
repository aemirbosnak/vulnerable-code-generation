//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t r, g, b;
} pixel_t;

typedef struct {
    int width, height;
    pixel_t **pixels;
} image_t;

image_t *image_load(const char *filepath) {
    FILE *fp = fopen(filepath, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file: %s\n", filepath);
        return NULL;
    }

    // Read header
    uint16_t type;
    fread(&type, sizeof(type), 1, fp);
    if (type != 0x4d42) {
        fprintf(stderr, "Error: Invalid file format\n");
        fclose(fp);
        return NULL;
    }

    uint32_t filesize, offset;
    fread(&filesize, sizeof(filesize), 1, fp);
    fread(&offset, sizeof(offset), 1, fp);

    // Read image dimensions
    uint32_t width, height;
    fseek(fp, offset, SEEK_SET);
    fread(&width, sizeof(width), 1, fp);
    fread(&height, sizeof(height), 1, fp);

    // Allocate memory for image data
    image_t *image = malloc(sizeof(image_t));
    image->width = width;
    image->height = height;
    image->pixels = malloc(height * sizeof(pixel_t *));
    for (int i = 0; i < height; i++) {
        image->pixels[i] = malloc(width * sizeof(pixel_t));
    }

    // Read image data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(&image->pixels[i][j], sizeof(pixel_t), 1, fp);
        }
    }

    fclose(fp);

    return image;
}

void image_save(image_t *image, const char *filepath) {
    FILE *fp = fopen(filepath, "wb");
    if (!fp) {
        fprintf(stderr, "Error opening file: %s\n", filepath);
        return;
    }

    // Write header
    uint16_t type = 0x4d42;
    fwrite(&type, sizeof(type), 1, fp);

    uint32_t filesize = image->width * image->height * sizeof(pixel_t) + 54;
    fwrite(&filesize, sizeof(filesize), 1, fp);

    uint32_t offset = 54;
    fwrite(&offset, sizeof(offset), 1, fp);

    // Write image dimensions
    fwrite(&image->width, sizeof(image->width), 1, fp);
    fwrite(&image->height, sizeof(image->height), 1, fp);

    // Write image data
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fwrite(&image->pixels[i][j], sizeof(pixel_t), 1, fp);
        }
    }

    fclose(fp);
}

void image_hide_message(image_t *image, const char *message) {
    int message_length = strlen(message);
    if (message_length > image->width * image->height * 3) {
        fprintf(stderr, "Error: Message too long\n");
        return;
    }

    int message_index = 0;
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            // Hide one bit of the message in each pixel
            if (message_index < message_length) {
                image->pixels[i][j].r &= ~1;
                image->pixels[i][j].r |= (message[message_index++] & 1);
            }
            if (message_index < message_length) {
                image->pixels[i][j].g &= ~1;
                image->pixels[i][j].g |= (message[message_index++] & 1);
            }
            if (message_index < message_length) {
                image->pixels[i][j].b &= ~1;
                image->pixels[i][j].b |= (message[message_index++] & 1);
            }
        }
    }
}

char *image_extract_message(image_t *image) {
    int message_length = 0;
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            message_length += (image->pixels[i][j].r & 1);
            message_length += (image->pixels[i][j].g & 1);
            message_length += (image->pixels[i][j].b & 1);
        }
    }

    char *message = malloc(message_length + 1);
    if (!message) {
        fprintf(stderr, "Error allocating memory for message\n");
        return NULL;
    }

    int message_index = 0;
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            message[message_index++] = (image->pixels[i][j].r & 1) | (image->pixels[i][j].g & 1) << 1 | (image->pixels[i][j].b & 1) << 2;
        }
    }

    message[message_length] = '\0';

    return message;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <message>\n", argv[0]);
        return 1;
    }

    image_t *image = image_load(argv[1]);
    if (!image) {
        fprintf(stderr, "Error loading image: %s\n", argv[1]);
        return 1;
    }

    image_hide_message(image, argv[3]);
    image_save(image, argv[2]);

    free(image->pixels);
    free(image);

    image = image_load(argv[2]);
    if (!image) {
        fprintf(stderr, "Error loading image: %s\n", argv[2]);
        return 1;
    }

    char *message = image_extract_message(image);
    if (!message) {
        fprintf(stderr, "Error extracting message from image\n");
        return 1;
    }

    printf("Extracted message: %s\n", message);

    free(message);
    free(image->pixels);
    free(image);

    return 0;
}