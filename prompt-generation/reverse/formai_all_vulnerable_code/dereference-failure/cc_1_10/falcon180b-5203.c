//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 500
#define MAX_HEIGHT 500
#define ASCII_CHAR_SET ".,-+*0123456789ABCDEF"

typedef struct {
    int width;
    int height;
    int* pixels;
} Image;

void load_image(Image* img, const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: could not open image file %s\n", filename);
        exit(1);
    }

    fseek(fp, 18, SEEK_SET); // skip header
    fread(&img->width, sizeof(int), 1, fp);
    fread(&img->height, sizeof(int), 1, fp);
    img->pixels = (int*)malloc(img->width * img->height * sizeof(int));

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            unsigned char pixel;
            fread(&pixel, sizeof(unsigned char), 1, fp);
            int value = (int)pixel * 255;
            img->pixels[(y * img->width) + x] = value;
        }
    }

    fclose(fp);
}

void save_ascii_art(Image* img, const char* filename) {
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: could not open output file %s\n", filename);
        exit(1);
    }

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int value = img->pixels[(y * img->width) + x];
            int index = value / (MAX_WIDTH / strlen(ASCII_CHAR_SET));
            fprintf(fp, "%c", ASCII_CHAR_SET[index]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_image.bmp output_ascii_art.txt\n", argv[0]);
        return 1;
    }

    Image img;
    load_image(&img, argv[1]);
    save_ascii_art(&img, argv[2]);

    printf("Conversion completed!\n");
    return 0;
}