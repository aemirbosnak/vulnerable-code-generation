//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned char *data;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(unsigned int), 1, fp);
    fread(&image->height, sizeof(unsigned int), 1, fp);
    image->data = malloc(image->width * image->height);
    if (image->data == NULL) {
        perror("malloc");
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->data, image->width * image->height, 1, fp);
    fclose(fp);

    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    fwrite(&image->width, sizeof(unsigned int), 1, fp);
    fwrite(&image->height, sizeof(unsigned int), 1, fp);
    fwrite(image->data, image->width * image->height, 1, fp);
    fclose(fp);
}

void embed_watermark(Image *image, const char *watermark) {
    unsigned int i, j;
    unsigned int watermark_length = strlen(watermark);

    for (i = 0; i < watermark_length; i++) {
        for (j = 0; j < 8; j++) {
            unsigned int bit = (watermark[i] >> j) & 1;
            image->data[i * 8 + j] |= bit;
        }
    }
}

char *extract_watermark(const Image *image) {
    unsigned int i, j;
    unsigned int watermark_length = image->width * image->height / 8;
    char *watermark = malloc(watermark_length + 1);
    if (watermark == NULL) {
        perror("malloc");
        return NULL;
    }

    for (i = 0; i < watermark_length; i++) {
        for (j = 0; j < 8; j++) {
            unsigned int bit = image->data[i * 8 + j] & 1;
            watermark[i] |= (bit << j);
        }
    }

    watermark[watermark_length] = '\0';
    return watermark;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_image> <watermark> <output_image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *image = read_image(argv[1]);
    if (image == NULL) {
        return EXIT_FAILURE;
    }

    embed_watermark(image, argv[2]);
    write_image(image, argv[3]);
    free(image);

    image = read_image(argv[3]);
    if (image == NULL) {
        return EXIT_FAILURE;
    }

    char *watermark = extract_watermark(image);
    if (watermark == NULL) {
        free(image);
        return EXIT_FAILURE;
    }

    printf("Watermark: %s\n", watermark);
    free(watermark);
    free(image);

    return EXIT_SUCCESS;
}