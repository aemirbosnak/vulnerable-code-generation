//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80

struct pixel {
    int x, y;
    int r, g, b;
};

void ascii_art(char *filename, char *output_filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open input file\n");
        exit(1);
    }

    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    struct pixel *pixels = (struct pixel *) malloc(width * height * sizeof(struct pixel));
    if (pixels == NULL) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }

    fread(pixels, sizeof(struct pixel), width * height, fp);
    fclose(fp);

    FILE *ofp = fopen(output_filename, "w");
    if (ofp == NULL) {
        printf("Error: could not open output file\n");
        exit(1);
    }

    int max_val = 0;
    for (int i = 0; i < width * height; i++) {
        if (pixels[i].r > max_val) {
            max_val = pixels[i].r;
        }
        if (pixels[i].g > max_val) {
            max_val = pixels[i].g;
        }
        if (pixels[i].b > max_val) {
            max_val = pixels[i].b;
        }
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;

            int r = pixels[index].r;
            int g = pixels[index].g;
            int b = pixels[index].b;

            int gray = (r + g + b) / 3;

            if (gray > max_val) {
                gray = max_val;
            }

            if (gray < 0) {
                gray = 0;
            }

            fprintf(ofp, "%c", '@' + gray % 64);
        }
        fprintf(ofp, "\n");
    }

    fclose(ofp);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    ascii_art(argv[1], argv[2]);

    return 0;
}