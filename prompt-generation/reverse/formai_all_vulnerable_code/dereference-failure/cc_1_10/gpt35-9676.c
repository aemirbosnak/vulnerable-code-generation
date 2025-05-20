//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Set up global variables for image size
int width = 0;
int height = 0;

// Function to load image from file
void load_image(char *file_name, char **image_data) {
    FILE *fp;
    fp = fopen(file_name, "rb");

    // Get image size
    fseek(fp, 0x0012, SEEK_SET);
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);

    // Allocate memory for image data
    *image_data = (char*) malloc(width * height * 3);

    // Read image data
    fseek(fp, 54, SEEK_SET);
    fread(*image_data, 1, width * height * 3, fp);

    fclose(fp);
}

// Function to convert RGB pixel to grayscale
int pixel_to_gray(int r, int g, int b) {
    return (int) (0.21 * r + 0.72 * g + 0.07 * b);
}

// Function to convert pixel to ASCII character
char pixel_to_ascii(int gray) {
    char ascii[] = " .,:;ox%#@";
    int num_chars = strlen(ascii);

    int index = (int) ((gray / 255.0) * (num_chars - 1));
    return ascii[index];
}

int main(int argc, char *argv[]) {
    char *file_name = argv[1];
    char *image_data;

    // Load image from file
    load_image(file_name, &image_data);

    // Print ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = (i * width + j) * 3;
            int r = image_data[index];
            int g = image_data[index + 1];
            int b = image_data[index + 2];

            int gray = pixel_to_gray(r, g, b);
            char ascii = pixel_to_ascii(gray);
            printf("%c", ascii);
        }
        printf("\n");
    }

    free(image_data);
    return 0;
}