//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image loadImage(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    char *data = malloc(size);
    if (fread(data, size, 1, fp)!= 1) {
        printf("Error: could not read file %s\n", filename);
        exit(1);
    }

    fclose(fp);

    return (Image) {
       .width = 0,
       .height = 0,
       .data = data
    };
}

void freeImage(Image img) {
    free(img.data);
}

void printChar(char c, int x, int y) {
    printf("%c", c);
}

void printRow(const char *row, int x, int y) {
    for (int i = 0; i < strlen(row); i++) {
        printChar(row[i], x + i * 8, y);
    }
}

void printImage(const Image img) {
    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            int index = (y * img.width + x) * 3;
            int r = img.data[index] / 8;
            int g = img.data[index + 1] / 8;
            int b = img.data[index + 2] / 8;

            if (r == 0 && g == 0 && b == 0) {
                printChar(' ', x * 8, y * 8);
            } else {
                printChar('#', x * 8, y * 8);
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input image> <output ascii art>\n", argv[0]);
        return 1;
    }

    Image img = loadImage(argv[1]);

    FILE *fp = fopen(argv[2], "w");
    if (fp == NULL) {
        printf("Error: could not open file %s for writing\n", argv[2]);
        exit(1);
    }

    printImage(img);

    fclose(fp);

    freeImage(img);

    return 0;
}