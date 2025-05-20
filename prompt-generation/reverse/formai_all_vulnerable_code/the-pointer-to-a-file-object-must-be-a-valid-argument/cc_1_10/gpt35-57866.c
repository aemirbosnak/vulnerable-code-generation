//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 60
#define MAX_PIXEL_VALUE 255
#define ASCII_GRADIENT "@#*&%o:-. "

// Function to get the ASCII character for a given pixel value.
char get_ascii_char(int pixel_value) {
    int gradient_size = strlen(ASCII_GRADIENT);
    int step_size = MAX_PIXEL_VALUE / (gradient_size - 1);

    for (int i = 0; i < gradient_size; i++) {
        if (pixel_value <= (i * step_size)) {
            return ASCII_GRADIENT[i];
        }
    }

    return ' ';
}

int main() {
    // Read image file
    FILE *image_file = fopen("example_image.pgm", "r");
    char buffer[100];
    int width, height, pixel_value;
    unsigned char *image_data = malloc(MAX_WIDTH*MAX_HEIGHT*sizeof(unsigned char));

    fgets(buffer, 100, image_file);
    fgets(buffer, 100, image_file);

    sscanf(buffer, "%d %d", &width, &height);

    fgets(buffer, 100, image_file);
    sscanf(buffer, "%d", &pixel_value);

    int index = 0;
    while (fgets(buffer, 100, image_file) != NULL) {
        // Skip comments
        if (buffer[0] != '#') {
            char *token;
            token = strtok(buffer, " ");
            while (token != NULL) {
                image_data[index] = atoi(token);
                token = strtok(NULL, " ");
                index++;
            }
        }
    }

    fclose(image_file);

    // Convert image to ASCII art
    char ascii_art[MAX_HEIGHT][MAX_WIDTH+1];
    memset(ascii_art, ' ', sizeof(ascii_art));

    index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel_value = image_data[index];
            char ascii_char = get_ascii_char(pixel_value);
            ascii_art[i][j] = ascii_char;
            index++;
        }
    }

    // Print ASCII art
    for (int i = 0; i < height; i++) {
        printf("%s\n", ascii_art[i]);
    }

    free(image_data);

    return 0;
}