//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_CHARS ".:*+=-0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

typedef struct {
    int width;
    int height;
    char *data;
} image_t;

void load_image(image_t *img, char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    img->data = malloc(filesize);
    if (img->data == NULL) {
        printf("Error: cannot allocate memory for image data\n");
        exit(1);
    }

    fread(img->data, filesize, 1, fp);
    fclose(fp);

    img->width = atoi(strtok(filename, "."));
    img->height = atoi(strtok(NULL, "."));
}

void save_ascii(image_t *img, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: cannot open file %s for writing\n", filename);
        exit(1);
    }

    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            int value = (int)img->data[i * img->width + j];
            fprintf(fp, "%c", ASCII_CHARS[value % 64]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_image.bmp output_ascii.txt\n", argv[0]);
        exit(1);
    }

    image_t img;
    load_image(&img, argv[1]);
    save_ascii(&img, argv[2]);

    printf("Conversion completed.\n");

    return 0;
}