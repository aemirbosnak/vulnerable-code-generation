//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

typedef struct {
    char *data;
    int width;
    int height;
} Image;

Image loadImage(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *data = malloc(size);
    if (data == NULL) {
        printf("Error: out of memory\n");
        exit(1);
    }

    fread(data, 1, size, fp);
    fclose(fp);

    Image image = {data, WIDTH, HEIGHT};
    return image;
}

void saveAsciiArt(Image image, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: could not open file '%s' for writing\n", filename);
        exit(1);
    }

    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            int value = image.data[y * image.width + x] / 16;
            fprintf(fp, "%c", value < 10? '0' + value : 'A' + value - 10);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s input.bmp output.txt\n", argv[0]);
        return 1;
    }

    Image image = loadImage(argv[1]);
    saveAsciiArt(image, argv[2]);

    printf("Conversion completed.\n");
    return 0;
}