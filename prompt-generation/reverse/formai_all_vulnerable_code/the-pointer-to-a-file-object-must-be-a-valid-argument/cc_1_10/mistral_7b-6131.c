//MISTRAL-7B DATASET v1.0 Category: Digital Watermarking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 256
#define HEIGHT 256
#define BPP 3
#define MESSAGE_LENGTH 5
#define MASK_VALUE 128
#define BLOCK_SIZE 8
#define WATERMARK "HelloWorld"

typedef struct Image {
    unsigned char *data;
    int width;
    int height;
} Image;

void load_pgm(const char *filename, Image *image) {
    FILE *file = fopen(filename, "rb");
    char magic_number[3];
    int width, height, max_value;

    fgets(magic_number, 3, file);
    sscanf(magic_number, "P5%n", &width);
    fgets(magic_number, 3, file);
    sscanf(magic_number, "%d%n%d%n", &height, &width, &max_value);

    image->width = width;
    image->height = height;
    image->data = (unsigned char *) malloc(width * height * BPP);

    fread(image->data, width * BPP, height, file);
    fclose(file);
}

void save_pgm(const char *filename, const Image image) {
    FILE *file = fopen(filename, "wb");
    int max_value = 255;

    fprintf(file, "P5\n%d %d\n255\n", image.width, image.height);
    fwrite(image.data, image.width * image.height * BPP, 1, file);
    fclose(file);
}

void watermark_image(Image *cover, const char *watermark) {
    int i, j, pos, msg_index;
    unsigned char *data = cover->data;

    for (i = 0; i < cover->height; i += BLOCK_SIZE) {
        for (j = 0; j < cover->width; j += BLOCK_SIZE) {
            pos = i * cover->width + j;
            msg_index = 0;

            for (int b = 0; b < BLOCK_SIZE / 2 && pos + BLOCK_SIZE / 2 < cover->height * cover->width; b++) {
                if (data[pos + b] > MASK_VALUE) {
                    data[pos + b] -= MASK_VALUE;
                    data[pos + pos + b] += (watermark[msg_index++] & 0xFF);
                } else {
                    data[pos + b] += MASK_VALUE;
                    data[pos + pos + b] -= (watermark[msg_index++] & 0xFF);
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    Image cover;
    load_pgm("cover.pgm", &cover);

    watermark_image(&cover, WATERMARK);

    save_pgm("watermarked.pgm", cover);

    free(cover.data);

    return 0;
}