//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_WIDTH 1000
#define MAX_IMAGE_HEIGHT 1000
#define MAX_IMAGE_SIZE (MAX_IMAGE_WIDTH * MAX_IMAGE_HEIGHT)
#define ASCII_ART_WIDTH 80

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

void loadImage(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error loading image file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    if (fileSize == 0) {
        printf("Image file is empty.\n");
        exit(1);
    }

    rewind(fp);
    img->data = (unsigned char *) malloc(fileSize);
    fread(img->data, 1, fileSize, fp);

    fclose(fp);

    int headerSize = 0;
    while (headerSize < fileSize && img->data[headerSize]!= 0xff) {
        headerSize++;
    }

    if (headerSize + 2 >= fileSize) {
        printf("Invalid image file format.\n");
        exit(1);
    }

    int width = *(int *) &img->data[headerSize + 1];
    int height = *(int *) &img->data[headerSize + 5];

    if (width > MAX_IMAGE_WIDTH || height > MAX_IMAGE_HEIGHT) {
        printf("Image dimensions are too large.\n");
        exit(1);
    }

    img->width = width;
    img->height = height;
}

void freeImage(Image *img) {
    free(img->data);
}

void printASCIIArt(Image *img) {
    int x, y;
    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            int value = img->data[y * img->width + x];
            if (value < 128) {
                printf(" ");
            } else {
                printf("%c", value + 33);
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_image output_ascii_art\n", argv[0]);
        return 1;
    }

    Image img;
    loadImage(&img, argv[1]);

    char outputFilename[strlen(argv[2]) + 5];
    strcpy(outputFilename, argv[2]);
    strcat(outputFilename, ".txt");

    FILE *fp = fopen(outputFilename, "w");
    if (fp == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }

    printASCIIArt(&img);

    fclose(fp);

    freeImage(&img);

    printf("Conversion completed successfully.\n");

    return 0;
}