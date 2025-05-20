//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Image {
    int width, height;
    int *data;
};

struct Watermark {
    int width, height;
    int *data;
};

void readImage(struct Image *image, char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fscanf(file, "%d %d\n", &image->width, &image->height);

    image->data = malloc(image->width * image->height * sizeof(int));
    if (image->data == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    for (int i = 0; i < image->width * image->height; i++) {
        fscanf(file, "%d ", &image->data[i]);
    }

    fclose(file);
}

void writeImage(struct Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fprintf(file, "%d %d\n", image->width, image->height);

    for (int i = 0; i < image->width * image->height; i++) {
        fprintf(file, "%d ", image->data[i]);
    }

    fclose(file);
}

void readWatermark(struct Watermark *watermark, char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fscanf(file, "%d %d\n", &watermark->width, &watermark->height);

    watermark->data = malloc(watermark->width * watermark->height * sizeof(int));
    if (watermark->data == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    for (int i = 0; i < watermark->width * watermark->height; i++) {
        fscanf(file, "%d ", &watermark->data[i]);
    }

    fclose(file);
}

void writeWatermark(struct Watermark *watermark, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fprintf(file, "%d %d\n", watermark->width, watermark->height);

    for (int i = 0; i < watermark->width * watermark->height; i++) {
        fprintf(file, "%d ", watermark->data[i]);
    }

    fclose(file);
}

void embedWatermark(struct Image *image, struct Watermark *watermark) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = (image->data[i] & 0xffffff00) | (watermark->data[i] & 0x000000ff);
    }
}

void extractWatermark(struct Image *image, struct Watermark *watermark) {
    for (int i = 0; i < image->width * image->height; i++) {
        watermark->data[i] = image->data[i] & 0x000000ff;
    }
}

int main(int argc, char **argv) {
    if (argc != 5) {
        printf("Usage: %s <image file> <watermark file> <watermarked image file> <extracted watermark file>\n", argv[0]);
        return 1;
    }

    struct Image image;
    struct Watermark watermark;

    readImage(&image, argv[1]);
    readWatermark(&watermark, argv[2]);

    embedWatermark(&image, &watermark);
    writeImage(&image, argv[3]);

    extractWatermark(&image, &watermark);
    writeWatermark(&watermark, argv[4]);

    return 0;
}