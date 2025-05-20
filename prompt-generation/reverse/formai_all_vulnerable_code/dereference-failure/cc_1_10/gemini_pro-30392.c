//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

typedef struct {
    uint32_t width;
    uint32_t height;
    uint8_t *data;
} Image;

typedef struct {
    char *message;
    uint32_t length;
} Watermark;

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fclose(file);
        return NULL;
    }

    fread(&image->width, sizeof(uint32_t), 1, file);
    fread(&image->height, sizeof(uint32_t), 1, file);
    image->data = malloc(image->width * image->height * 3);
    if (!image->data) {
        fclose(file);
        free(image);
        return NULL;
    }

    fread(image->data, image->width * image->height * 3, 1, file);
    fclose(file);

    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

Watermark *create_watermark(const char *message) {
    Watermark *watermark = malloc(sizeof(Watermark));
    if (!watermark) {
        return NULL;
    }

    watermark->message = strdup(message);
    if (!watermark->message) {
        free(watermark);
        return NULL;
    }

    watermark->length = strlen(watermark->message);

    return watermark;
}

void free_watermark(Watermark *watermark) {
    free(watermark->message);
    free(watermark);
}

void embed_watermark(Image *image, Watermark *watermark) {
    for (uint32_t i = 0; i < watermark->length; i++) {
        uint8_t bit = (watermark->message[i] >> 7) & 1;
        image->data[i * 3] = (image->data[i * 3] & 0xFE) | bit;
    }
}

void extract_watermark(Image *image, Watermark *watermark) {
    for (uint32_t i = 0; i < watermark->length; i++) {
        uint8_t bit = image->data[i * 3] & 1;
        watermark->message[i] |= (bit << 7);
    }
    watermark->message[watermark->length] = '\0';
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image> <message> <output>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        fprintf(stderr, "Error: Failed to load image '%s'\n", argv[1]);
        return 1;
    }

    Watermark *watermark = create_watermark(argv[2]);
    if (!watermark) {
        fprintf(stderr, "Error: Failed to create watermark '%s'\n", argv[2]);
        return 1;
    }

    embed_watermark(image, watermark);

    FILE *file = fopen(argv[3], "wb");
    if (!file) {
        fprintf(stderr, "Error: Failed to open output file '%s'\n", argv[3]);
        return 1;
    }

    fwrite(&image->width, sizeof(uint32_t), 1, file);
    fwrite(&image->height, sizeof(uint32_t), 1, file);
    fwrite(image->data, image->width * image->height * 3, 1, file);
    fclose(file);

    printf("Watermark '%s' embedded in image '%s' and saved to '%s'\n", argv[2], argv[1], argv[3]);

    free_watermark(watermark);
    free_image(image);

    return 0;
}