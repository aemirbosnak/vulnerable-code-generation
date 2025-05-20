//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

struct pixel {
    int x;
    int y;
    int value;
};

void read_image(const char* filename, struct pixel pixels[MAX_HEIGHT][MAX_WIDTH]) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening image file.\n");
        exit(1);
    }

    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Image dimensions are too large.\n");
        exit(1);
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int value;
            fread(&value, sizeof(int), 1, fp);
            pixels[i][j].x = j;
            pixels[i][j].y = i;
            pixels[i][j].value = value;
        }
    }

    fclose(fp);
}

void write_ascii_art(const struct pixel pixels[MAX_HEIGHT][MAX_WIDTH], const char* filename) {
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening output file.\n");
        exit(1);
    }

    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            if (pixels[i][j].value == 0) {
                fprintf(fp, " ");
            } else {
                fprintf(fp, "*");
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s input_image.bmp output_ascii_art.txt\n", argv[0]);
        exit(1);
    }

    struct pixel pixels[MAX_HEIGHT][MAX_WIDTH];
    read_image(argv[1], pixels);
    write_ascii_art(pixels, argv[2]);

    printf("Conversion completed successfully.\n");
    return 0;
}