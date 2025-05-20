//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned char *data;
} Image;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(unsigned int), 1, fp);
    fread(&image->height, sizeof(unsigned int), 1, fp);
    image->data = malloc(image->width * image->height);
    if (!image->data) {
        free(image);
        fclose(fp);
        return NULL;
    }

    fread(image->data, image->width * image->height, 1, fp);
    fclose(fp);

    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

int embed_watermark(Image *image, const char *watermark) {
    unsigned int i, j;
    unsigned int watermark_length = strlen(watermark);
    unsigned int watermark_index = 0;

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            if (watermark_index < watermark_length) {
                image->data[i * image->width + j] &= 0xFE;
                image->data[i * image->width + j] |= (watermark[watermark_index] & 1);
                watermark_index++;
            }
        }
    }

    return 0;
}

char *extract_watermark(Image *image) {
    unsigned int i, j;
    unsigned int watermark_length = 0;
    unsigned char *watermark = NULL;

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            watermark_length += (image->data[i * image->width + j] & 1);
        }
    }

    watermark = malloc(watermark_length + 1);
    if (!watermark) {
        return NULL;
    }

    unsigned int watermark_index = 0;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            if (watermark_index < watermark_length) {
                watermark[watermark_index] = (image->data[i * image->width + j] & 1);
                watermark_index++;
            }
        }
    }

    watermark[watermark_length] = '\0';

    return watermark;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <image> <watermark>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        printf("Error: Could not load image %s\n", argv[1]);
        return 1;
    }

    int result = embed_watermark(image, argv[2]);
    if (result != 0) {
        printf("Error: Could not embed watermark\n");
        free_image(image);
        return 1;
    }

    char *watermark = extract_watermark(image);
    if (!watermark) {
        printf("Error: Could not extract watermark\n");
        free_image(image);
        return 1;
    }

    printf("Extracted watermark: %s\n", watermark);
    free(watermark);
    free_image(image);

    return 0;
}