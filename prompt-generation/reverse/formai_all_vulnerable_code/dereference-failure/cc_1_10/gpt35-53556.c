//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200
#define MAX_ASCII 70

// Function to get the grayscale value of a pixel
int get_grayscale(unsigned char *image, int x, int y, int width)
{
    int offset = y * width + x;
    return image[offset];
}

// Function to map the grayscale value to an ASCII character
char map_ascii(int grayscale)
{
    int index = grayscale * MAX_ASCII / 256;
    const char *ascii_chars = "$@B%8&WM#*oahkbdpwmZO0QEPz?xyov=+-~,:;. ";
    return ascii_chars[index];
}

int main()
{
    // Read the image file
    FILE *file = fopen("image.pgm", "rb");
    if (!file) {
        printf("Error opening image file\n");
        return 1;
    }
    char magic_number[3];
    if (!fgets(magic_number, 3, file)) {
        printf("Error reading magic number from image file\n");
        fclose(file);
        return 1;
    }
    if (strcmp(magic_number, "P5")) {
        printf("Image file is not in PGM format\n");
        fclose(file);
        return 1;
    }
    int width, height;
    if (!fscanf(file, "%d", &width)) {
        printf("Error reading width from image file\n");
        fclose(file);
        return 1;
    }
    if (!fscanf(file, "%d", &height)) {
        printf("Error reading height from image file\n");
        fclose(file);
        return 1;
    }
    int maxval;
    if (!fscanf(file, "%d", &maxval)) {
        printf("Error reading maxval from image file\n");
        fclose(file);
        return 1;
    }
    if (maxval != 255) {
        printf("Image file is not 8-bit grayscale\n");
        fclose(file);
        return 1;
    }
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Image is too large\n");
        fclose(file);
        return 1;
    }
    unsigned char image[MAX_HEIGHT][MAX_WIDTH];
    fread(image, 1, width*height, file);
    fclose(file);

    // Convert the image to ASCII art
    char ascii[MAX_HEIGHT][MAX_WIDTH + 1];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int grayscale = get_grayscale((unsigned char *) image, x, y, width);
            ascii[y][x] = map_ascii(grayscale);
        }
        ascii[y][width] = '\0';
    }

    // Print the ASCII art to the console
    for (int y = 0; y < height; y++) {
        printf("%s\n", ascii[y]);
    }

    return 0;
}