//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: shape shifting
// Wavy welcome to digital watermarking!

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);
    image->data = malloc(image->width * image->height * sizeof(unsigned char));
    if (image->data == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->data, sizeof(unsigned char), image->width * image->height, fp);
    fclose(fp);

    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return;
    }

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);
    fwrite(image->data, sizeof(unsigned char), image->width * image->height, fp);
    fclose(fp);
}

void watermark_image(Image *image, const char *message) {
    int i, j, k;
    int len = strlen(message);

    for (i = 0; i < len; i++) {
        for (j = 0; j < 8; j++) {
            k = i * 8 + j;
            if (k < image->width * image->height) {
                image->data[k] ^= (1 << j) & message[i];
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <message>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    watermark_image(image, argv[3]);

    save_image(argv[2], image);

    free(image->data);
    free(image);

    return 0;
}