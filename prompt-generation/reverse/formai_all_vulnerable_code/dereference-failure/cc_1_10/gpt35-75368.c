//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX_HEIGHT 1024
#define MAX_WIDTH 1024

char *ASCII_CHARS = "$@B%8&WM#*oahkbdpwmZO0QwcvbnjzuyxtCxrqo\\|/()1{}[]?+~<>i!l-_"
"\"^;:,. ";

int get_brightness(int r, int g, int b) {
    return round(0.2126 * r + 0.7152 * g + 0.0722 * b);
}

char get_ascii_char(int brightness) {
    int len = strlen(ASCII_CHARS);
    int index = round((brightness * (len - 1)) / 255.0);
    return ASCII_CHARS[index];
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        fprintf(stderr, "Could not open file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char magic_number[3];
    int width, height, depth;
    fgets(magic_number, 3, fp);
    fscanf(fp, "%d %d %d", &width, &height, &depth);
    fgetc(fp);

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Image dimensions are too large.\n");
        exit(EXIT_FAILURE);
    }

    int pixels[MAX_HEIGHT][MAX_WIDTH][3];
    char ascii_art[MAX_HEIGHT][MAX_WIDTH];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixels[i][j][0] = fgetc(fp);
            pixels[i][j][1] = fgetc(fp);
            pixels[i][j][2] = fgetc(fp);
        }
        fgetc(fp);
    }
    fclose(fp);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int brightness = get_brightness(pixels[i][j][0], pixels[i][j][1], pixels[i][j][2]);
            ascii_art[i][j] = get_ascii_char(brightness);
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }

    return 0;
}