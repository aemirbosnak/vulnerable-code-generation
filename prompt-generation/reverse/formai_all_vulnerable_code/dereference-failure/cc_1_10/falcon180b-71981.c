//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMAGE_SIZE 512
#define MAX_INT 1000000000

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int *data;
    int width;
    int height;
} Image;

void read_image(char *filename, Image *image) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Cannot open image file!\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    image->data = (int *) malloc(sizeof(int) * filesize);
    if (image->data == NULL) {
        printf("Cannot allocate memory!\n");
        exit(1);
    }

    int count = fread(image->data, sizeof(int), filesize, fp);
    if (count!= filesize) {
        printf("Cannot read image file!\n");
        exit(1);
    }

    fclose(fp);

    image->width = IMAGE_SIZE;
    image->height = IMAGE_SIZE;
}

void display_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int value = image->data[(i * image->width) + j];
            printf("%d ", value);
        }
        printf("\n");
    }
}

void add_watermark(Image *image, char *watermark) {
    int watermark_value = 0;
    for (int i = 0; i < strlen(watermark); i++) {
        if (watermark[i] == '1') {
            watermark_value += MAX_INT;
        }
    }

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int value = image->data[(i * image->width) + j];
            value += watermark_value;
            if (value > MAX_INT) {
                value = MAX_INT;
            }
            image->data[(i * image->width) + j] = value;
        }
    }
}

int main() {
    Image image;
    read_image("input.bmp", &image);

    char watermark[] = "This image is copyrighted by John Doe";
    add_watermark(&image, watermark);

    display_image(&image);

    return 0;
}