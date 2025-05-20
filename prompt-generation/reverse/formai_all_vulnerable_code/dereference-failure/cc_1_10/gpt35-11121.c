//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_ASCII 70

char ascii[MAX_HEIGHT][MAX_WIDTH];

void convertToASCII(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./converter [input file] [output file]\n");
        return 1;
    }

    char *in_file = argv[1];
    char *out_file = argv[2];

    FILE *fin = fopen(in_file, "rb");
    if (fin == NULL) {
        printf("Failed to open input file: %s\n", in_file);
        return 1;
    }

    FILE *fout = fopen(out_file, "w+");
    if (fout == NULL) {
        printf("Failed to open output file: %s\n", out_file);
        return 1;
    }

    int width, height;
    char format[5];
    unsigned char image[MAX_HEIGHT][MAX_WIDTH];

    fscanf(fin, "%s\n%d %d\n", format, &width, &height);
    fread(image, sizeof(unsigned char), width * height, fin);

    convertToASCII(image, width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(fout, "%c", ascii[i][j]);
        }
        fprintf(fout, "\n");
    }

    return 0;
}

void convertToASCII(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    double scale = (double)MAX_ASCII / 255;
    char *ascii_chars = "@#*+=-:. ";

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int c = (int)(image[i][j] * scale);
            ascii[i][j] = ascii_chars[c];
        }
    }
}