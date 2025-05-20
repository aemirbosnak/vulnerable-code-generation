//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80

void convert_to_ascii(char ascii[MAX_HEIGHT][MAX_WIDTH], unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height);
int get_average_color(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int x, int y, int kernel_size);
char get_ascii_char(int color);

int main(void) {
    unsigned char image[MAX_HEIGHT][MAX_WIDTH]; // input image
    char ascii[MAX_HEIGHT][MAX_WIDTH]; // output ascii art image
    FILE *fp;
    int width, height;

    // open image file
    fp = fopen("image.pgm", "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open image file.\n");
        return 1;
    }

    // read image header
    char header[256];
    fgets(header, sizeof(header), fp);
    if (strcmp(header, "P5\n") != 0) {
        fprintf(stderr, "Error: invalid image format (must be PGM).\n");
        return 1;
    }
    fscanf(fp, "%d %d\n", &width, &height);
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Error: image too large (max %dx%d).\n", MAX_WIDTH, MAX_HEIGHT);
        return 1;
    }
    fgets(header, sizeof(header), fp); // skip max value
    if (strcmp(header, "255\n") != 0) {
        fprintf(stderr, "Error: invalid image format (max value must be 255).\n");
        return 1;
    }

    // read image data
    fread(image, sizeof(unsigned char), width * height, fp);
    if (ferror(fp)) {
        fprintf(stderr, "Error: could not read image data.\n");
        return 1;
    }
    fclose(fp);

    // perform ascii conversion of image
    convert_to_ascii(ascii, image, width, height);

    // print ascii art image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            putchar(ascii[y][x]);
        }
        putchar('\n');
    }

    return 0;
}

void convert_to_ascii(char ascii[MAX_HEIGHT][MAX_WIDTH], unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    const char *ascii_chars = " .-:=+*#%@";
    const int kernel_size = 3;
    const int threshold = 60;
    const int char_to_color_scale = 255 / (strlen(ascii_chars) - 1);

    // convert image to ascii art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int color = get_average_color(image, x, y, kernel_size);
            char ascii_char = get_ascii_char(color);
            ascii[y][x] = ascii_char;
        }
    }
}

int get_average_color(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int x, int y, int kernel_size) {
    int sum = 0;
    int count = 0;

    // calculate average color in kernel
    for (int ky = -kernel_size/2; ky <= kernel_size/2; ky++) {
        for (int kx = -kernel_size/2; kx <= kernel_size/2; kx++) {
            int px = x + kx;
            int py = y + ky;
            if (px >= 0 && py >= 0 && px < MAX_WIDTH && py < MAX_HEIGHT) {
                sum += image[py][px];
                count++;
            }
        }
    }
    int average_color = count > 0 ? sum / count : 0;

    return average_color;
}

char get_ascii_char(int color) {
    const char *ascii_chars = " .-:=+*#%@";
    char ascii_char;
    int char_index = (int)(color / (255.0f / (strlen(ascii_chars) - 1)));
    ascii_char = ascii_chars[char_index];

    return ascii_char;
}