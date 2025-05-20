//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void grayscale(int *r, int *g, int *b) {
    int avg = (*r + *g + *b) / 3;
    *r = *g = *b = avg;
}

char get_ascii_char(int intensity) {
    char ascii_chars[] = " .,-:;i1tfLCG08@";
    int num_chars = strlen(ascii_chars);
    int step = ceil(255.0 / num_chars);
    int index = intensity / step;
    return ascii_chars[index];
}

void print_ascii_art(char *ascii_art[], int height) {
    for (int i = 0; i < height; i++) {
        printf("%s\n", ascii_art[i]);
    }
}

void convert_to_ascii(char *filename, char *ascii_art[], int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file.\n");
        exit(1);
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];

    int row_padding = (4 - (*width * 3) % 4) % 4;
    int total_bytes = (*width * 3 + row_padding) * (*height);
    unsigned char *img_data = (unsigned char*) malloc(total_bytes);
    fread(img_data, sizeof(unsigned char), total_bytes, file);
    fclose(file);

    for (int i = 0; i < *height; i++) {
        ascii_art[i] = (char*) malloc((*width + 1) * sizeof(char));
        for (int j = 0; j < *width; j++) {
            int index = i * (*width * 3 + row_padding) + j * 3;
            int r = (int)img_data[index + 2];
            int g = (int)img_data[index + 1];
            int b = (int)img_data[index];
            grayscale(&r, &g, &b);
            int intensity = 255 - ((r + g + b) / 3);
            ascii_art[i][j] = get_ascii_char(intensity);
        }
        ascii_art[i][*width] = '\0';
    }

    free(img_data);
}

int main() {
    char *filename = "medieval.jpg";
    char *ascii_art[2000];
    int width, height;
    convert_to_ascii(filename, ascii_art, &width, &height);
    print_ascii_art(ascii_art, height);
    return 0;
}