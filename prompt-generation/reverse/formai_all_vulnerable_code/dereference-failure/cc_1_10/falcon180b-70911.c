//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256
#define MAX_VALUE 255
#define IMAGE_SIZE WIDTH * HEIGHT
#define BIT_MASK 0x80

typedef struct {
    char* filename;
    int* data;
} Image;

Image* loadImage(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Cannot open image file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    Image* image = malloc(sizeof(Image));
    image->filename = filename;
    image->data = malloc(size * sizeof(int));

    int count = fread(image->data, sizeof(int), size, fp);
    if (count!= size) {
        printf("Error: Cannot read image data.\n");
        exit(1);
    }

    fclose(fp);
    return image;
}

void saveImage(Image* image) {
    FILE* fp = fopen(image->filename, "wb");
    if (fp == NULL) {
        printf("Error: Cannot write image file.\n");
        exit(1);
    }

    fwrite(image->data, sizeof(int), image->data[0], fp);
    fclose(fp);
}

void printImage(Image* image) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int value = image->data[(y * WIDTH) + x];
            printf("%d ", value);
        }
        printf("\n");
    }
}

void addWatermark(Image* image) {
    int watermark = rand() % MAX_VALUE;
    int bit = rand() % 8;
    int mask = BIT_MASK >> bit;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int value = image->data[(y * WIDTH) + x];

            if ((value & mask) == 0) {
                value |= mask;
            }

            image->data[(y * WIDTH) + x] = value;
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    char* input_file = argv[1];
    char* output_file = argv[2];

    Image* input_image = loadImage(input_file);
    Image* output_image = malloc(sizeof(Image));

    output_image->filename = output_file;
    output_image->data = calloc(IMAGE_SIZE, sizeof(int));

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int value = input_image->data[(y * WIDTH) + x];
            output_image->data[(y * WIDTH) + x] = value;
        }
    }

    addWatermark(output_image);

    saveImage(output_image);
    printf("Watermark added successfully.\n");

    return 0;
}