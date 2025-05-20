//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function takes in a pixel's brightness value and returns
// the corresponding ASCII character based on a pre-defined mapping
char brightness_to_char(int brightness) {
    const char *MAPPING = "@#8&o*:. ";
    const int NUM_CHARS = strlen(MAPPING);
    int index = (brightness * NUM_CHARS) / 255;
    index = (index < 0) ? 0 : ((index >= NUM_CHARS) ? NUM_CHARS - 1 : index);
    return MAPPING[index];
}

// This function takes in an image represented as a 2D array of brightness
// values and converts it to ASCII art. It returns the result as a string.
char *convert_to_ascii(int **brightness, int width, int height) {
    const int MAX_LINE_LENGTH = 2 * width + 1;
    char *result = (char *) malloc((height + 1) * MAX_LINE_LENGTH * sizeof(char));
    char *current_line = result;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            *current_line++ = brightness_to_char(brightness[i][j]);
            *current_line++ = brightness_to_char(brightness[i][j]);
        }
        *current_line++ = '\n';
    }
    *current_line = '\0';
    return result;
}

// This function reads in an image from a file and returns it as a 2D array
// of brightness values. The image format should be PGM.
int **read_image(char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Failed to open file '%s'\n", filename);
        exit(1);
    }
    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P5") != 0) {
        fprintf(stderr, "Image file '%s' is not in PGM format\n", filename);
        exit(1);
    }
    // Read width and height
    fscanf(file, "%d %d", width, height);
    // Read max brightness (not used)
    int max_brightness;
    fscanf(file, "%d", &max_brightness);
    // Allocate 2D array for brightness values
    int **brightness = (int **) malloc(*height * sizeof(int *));
    for (int i = 0; i < *height; i++) {
        brightness[i] = (int *) malloc(*width * sizeof(int));
    }
    // Read brightness values
    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            brightness[i][j] = fgetc(file);
        }
    }
    fclose(file);
    return brightness;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        exit(1);
    }
    int width, height;
    int **brightness = read_image(argv[1], &width, &height);
    char *ascii_art = convert_to_ascii(brightness, width, height);
    printf("%s\n", ascii_art);
    // Free allocated memory
    for (int i = 0; i < height; i++) {
        free(brightness[i]);
    }
    free(brightness);
    free(ascii_art);
    return 0;
}