//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define BITS_PER_PIXEL 8

typedef struct {
    uint8_t *data;
    int width, height;
} Image;

Image *load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    image->data = malloc(WIDTH * HEIGHT * BITS_PER_PIXEL / 8);
    fread(image->data, 1, WIDTH * HEIGHT * BITS_PER_PIXEL / 8, fp);
    fclose(fp);

    image->width = WIDTH;
    image->height = HEIGHT;

    return image;
}

void save_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    fwrite(image->data, 1, WIDTH * HEIGHT * BITS_PER_PIXEL / 8, fp);
    fclose(fp);
}

void embed_watermark(Image *image, char *watermark) {
    int i, j, k;
    int watermark_length = strlen(watermark);
    int watermark_index = 0;

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            for (k = 0; k < BITS_PER_PIXEL; k++) {
                int bit = (image->data[i * image->width + j] >> k) & 1;
                int watermark_bit = (watermark[watermark_index >> 3] >> (watermark_index & 7)) & 1;
                image->data[i * image->width + j] = (image->data[i * image->width + j] & ~(1 << k)) | ((bit ^ watermark_bit) << k);
                watermark_index++;
                if (watermark_index >= watermark_length * BITS_PER_PIXEL) {
                    return;
                }
            }
        }
    }
}

char *extract_watermark(Image *image) {
    int i, j, k;
    int watermark_length = 0;
    int watermark_index = 0;
    char *watermark = malloc(100);

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            for (k = 0; k < BITS_PER_PIXEL; k++) {
                int bit = (image->data[i * image->width + j] >> k) & 1;
                watermark[watermark_index >> 3] |= (bit << (watermark_index & 7));
                watermark_index++;
                if (watermark_index >= watermark_length * BITS_PER_PIXEL) {
                    watermark_length++;
                    watermark = realloc(watermark, watermark_length + 1);
                    watermark[watermark_length] = '\0';
                }
            }
        }
    }

    return watermark;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <input image> <watermark> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    embed_watermark(image, argv[2]);
    save_image(image, argv[3]);

    char *watermark = extract_watermark(image);
    printf("Extracted watermark: %s\n", watermark);

    free(image->data);
    free(image);
    free(watermark);

    return 0;
}