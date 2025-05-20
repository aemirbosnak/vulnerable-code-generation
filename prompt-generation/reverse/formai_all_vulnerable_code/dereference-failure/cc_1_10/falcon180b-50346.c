//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define CHARACTER_SET "@%#*+=-:. "

void print_image(int *image, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", CHARACTER_SET[image[i * width + j] / 16]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    int width, height, depth;
    int *image;
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fseek(fp, 18, SEEK_SET);
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);
    fread(&depth, 4, 1, fp);
    if (depth!= 24) {
        printf("Unsupported image depth\n");
        exit(1);
    }
    image = (int *)malloc(width * height * sizeof(int));
    fseek(fp, 54, SEEK_SET);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(&image[i * width + j], 3, 1, fp);
            int r = image[i * width + j] / 8;
            int g = (image[i * width + j] % 8) / 4;
            int b = image[i * width + j] % 4;
            int index = (r * 36 + g * 6 + b) / 2;
            image[i * width + j] = index;
        }
    }
    fclose(fp);
    print_image(image, width, height);
    free(image);
    return 0;
}