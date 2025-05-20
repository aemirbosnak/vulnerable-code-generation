//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct {
    unsigned char *data;
    int size;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fclose(fp);
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    image->size = ftell(fp);
    rewind(fp);

    image->data = malloc(image->size);
    if (image->data == NULL) {
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->data, 1, image->size, fp);
    fclose(fp);

    return image;
}

void write_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    fwrite(image->data, 1, image->size, fp);
    fclose(fp);
}

void embed_watermark(Image *image, const char *watermark) {
    int i, j, k;
    int watermark_length = strlen(watermark);

    for (i = 0; i < image->size; i += 3) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 8; k++) {
                int bit = (watermark[k >> 3] >> (7 - (k & 7))) & 1;
                image->data[i + j] &= ~(1 << k);
                image->data[i + j] |= bit << k;
            }
        }
    }
}

char *extract_watermark(Image *image) {
    int i, j, k;
    char *watermark = malloc(MAX_SIZE);
    int watermark_length = 0;

    for (i = 0; i < image->size; i += 3) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 8; k++) {
                int bit = image->data[i + j] >> k & 1;
                watermark[watermark_length >> 3] |= bit << (7 - (watermark_length & 7));
                watermark_length++;
                if (watermark_length == MAX_SIZE) {
                    return watermark;
                }
            }
        }
    }

    return watermark;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <image> <watermark> <output>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (image == NULL) {
        printf("Error: could not read image %s\n", argv[1]);
        return 1;
    }

    embed_watermark(image, argv[2]);

    write_image(argv[3], image);

    printf("Watermarked image saved to %s\n", argv[3]);

    return 0;
}