//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 50

typedef struct {
    char *data;
    int width;
    int height;
} Image;

void loadImage(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error loading image: %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp);

    img->data = malloc(fileSize);
    fread(img->data, fileSize, 1, fp);
    fclose(fp);

    int headerSize = *(int *)img->data;
    img->width = *(int *)(img->data + 4);
    img->height = *(int *)(img->data + 8);
}

void freeImage(Image *img) {
    free(img->data);
}

void printASCIIArt(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int pixel = *(img->data + y * img->width + x);
            if (pixel == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input.bmp output.txt\n", argv[0]);
        return 1;
    }

    Image img;
    loadImage(&img, argv[1]);
    printASCIIArt(&img);

    FILE *out = fopen(argv[2], "w");
    if (out == NULL) {
        printf("Error writing output file: %s\n", argv[2]);
        return 1;
    }

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            int pixel = *(img.data + y * img.width + x);
            if (pixel == 0) {
                fprintf(out, " ");
            } else {
                fprintf(out, "#");
            }
        }
        fprintf(out, "\n");
    }

    fclose(out);

    freeImage(&img);

    return 0;
}