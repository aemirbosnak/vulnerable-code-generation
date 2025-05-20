//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the ASCII characters to represent the different grayscale levels
static const char* gradient = " .:-=+*#%@";

// Function to read in an image from a file
unsigned char* read_image(const char* filename, int* width, int* height, int* channels) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Failed to open image file.\n");
        return NULL;
    }

    // Read in the header information
    char header[128];
    fgets(header, 128, file);
    if (strncmp(header, "P5", 2)) {
        fprintf(stderr, "Invalid image file format.\n");
        return NULL;
    }

    // Read in the image dimensions
    char dim_line[128];
    fgets(dim_line, 128, file);
    sscanf(dim_line, "%d %d\n", width, height);

    // Read in the max grayscale value
    char max_line[128];
    fgets(max_line, 128, file);
    int max_val = atoi(max_line);

    if (max_val > 255) {
        fprintf(stderr, "Unsupported image format.\n");
        return NULL;
    }

    // Allocate memory for the image data
    *channels = 1;
    unsigned char* image_data = (unsigned char*)malloc((*width) * (*height) * (*channels));

    // Read in the image data
    size_t bytes_read = fread(image_data, 1, (*width) * (*height) * (*channels), file);
    if (bytes_read != (*width) * (*height) * (*channels)) {
        fprintf(stderr, "Failed to read image data.\n");
        free(image_data);
        return NULL;
    }

    fclose(file);
    return image_data;
}

// Function to convert the grayscale values to ASCII characters
char grayscale_to_ascii(unsigned char val) {
    int gradient_length = strlen(gradient);
    int idx = (int)((float)val / 255.0 * (float)gradient_length);
    return gradient[idx];
}

// Main program function
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    int width, height, channels;
    unsigned char* image_data = read_image(argv[1], &width, &height, &channels);
    if (!image_data) {
        return 1;
    }

    // Loop through the image data, printing out the ASCII characters
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char val = image_data[x + y * width];
            char ascii_val = grayscale_to_ascii(val);
            printf("%c", ascii_val);
        }

        printf("\n");
    }

    free(image_data);
    return 0;
}