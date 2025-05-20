//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

char image[HEIGHT][WIDTH];

void load_image(char *filename) {
    FILE *fp;
    int x, y;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open image file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (size!= HEIGHT * WIDTH) {
        printf("Error: image is not the correct size.\n");
        exit(1);
    }

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            char c = fgetc(fp);
            image[y][x] = c;
        }
    }

    fclose(fp);
}

void print_ascii_art(void) {
    int x, y;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            printf("%c", image[y][x]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_image.bmp output_ascii_art.txt\n", argv[0]);
        exit(1);
    }

    load_image(argv[1]);
    print_ascii_art();

    char *output_filename = argv[2];
    FILE *fp = fopen(output_filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fprintf(fp, "%c", image[y][x]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    printf("ASCII art saved to %s.\n", output_filename);

    return 0;
}