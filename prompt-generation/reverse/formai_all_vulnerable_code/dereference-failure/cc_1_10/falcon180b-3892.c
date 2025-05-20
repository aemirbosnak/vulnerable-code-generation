//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 45

typedef struct {
    char *data;
    int width;
    int height;
} Image;

void loadImage(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Failed to open image file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    image->data = (char *)malloc(size);
    fread(image->data, size, 1, fp);
    fclose(fp);

    image->width = atoi(strtok(filename, "."));
    image->height = atoi(strtok(NULL, "."));
}

void printASCII(Image *image, int x, int y) {
    int i, j;
    char c;

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            c = image->data[i * image->width + j] / 16;

            if (c == 0) {
                printf(" ");
            } else {
                printf("%c", c + 33);
            }
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <image_file> <output_file>\n", argv[0]);
        exit(1);
    }

    Image image;
    loadImage(argv[1], &image);

    FILE *fp = fopen(argv[2], "w");
    if (fp == NULL) {
        printf("Error: Failed to open output file.\n");
        exit(1);
    }

    printASCII(&image, 0, 0);

    fclose(fp);

    return 0;
}