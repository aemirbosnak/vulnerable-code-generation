//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char *data;
    int width;
    int height;
} Image;

void loadImage(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    img->data = malloc(filesize + 1);
    if (img->data == NULL) {
        printf("Error: could not allocate memory for image data\n");
        exit(EXIT_FAILURE);
    }

    fread(img->data, filesize, 1, fp);
    fclose(fp);

    img->width = atoi(strtok(filename, "."));
    img->height = atoi(strtok(NULL, "."));
}

void freeImage(Image *img) {
    free(img->data);
}

void printAsciiArt(Image *img) {
    int x, y;
    for (y = 0; y < img->height; ++y) {
        for (x = 0; x < img->width; ++x) {
            char c = img->data[y * img->width + x];
            if (c == 0) {
                printf(" ");
            } else {
                printf("%c", c);
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    Image img;
    loadImage(&img, argv[1]);

    FILE *fp = fopen(argv[2], "w");
    if (fp == NULL) {
        printf("Error: could not open file '%s' for writing\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    printAsciiArt(&img);

    fclose(fp);

    freeImage(&img);

    return 0;
}