//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert an RGB value to grayscale
int rgb_to_gray(int red, int green, int blue) {
    return (0.2989 * red + 0.5870 * green + 0.1140 * blue);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide the image file name.\n");
        return 1;
    }

    FILE *file_in = fopen(argv[1], "rb");
    if (file_in == NULL) {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    char *filename_out = (char *) malloc(strlen(argv[1]) + 5);
    sprintf(filename_out, "%s.txt", argv[1]);
    FILE *file_out = fopen(filename_out, "w");
    free(filename_out);

    // Read the header of the BMP file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file_in);

    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int row_size = width * 3;

    // Size of the row with padding
    int row_size_padded = (row_size + 3) & (~3);
    unsigned char padding[3] = {0, 0, 0};

    // Allocate memory for the input image and grayscale image
    unsigned char *img = (unsigned char *) malloc(row_size * height);
    unsigned char *gray = (unsigned char *) malloc(row_size * height);

    // Read the image
    for (int i = 0; i < height; i++) {
        int row_offset = i * row_size_padded;
        if (fread(&img[row_offset], sizeof(unsigned char), row_size, file_in) != row_size) {
            printf("Could not read file %s\n", argv[1]);
            free(img);
            free(gray);
            return 1;
        }
        fread(padding, sizeof(unsigned char), row_size_padded - row_size, file_in);
    }

    // Convert the image to grayscale
    for (int i = 0; i < height; i++) {
        int row_offset = i * row_size;
        for (int j = 0; j < width; j++) {
            int pixel_offset = row_offset + j * 3;
            int red = img[pixel_offset + 2];
            int green = img[pixel_offset + 1];
            int blue = img[pixel_offset];
            gray[pixel_offset + 2] = gray[pixel_offset + 1] = gray[pixel_offset] = rgb_to_gray(red, green, blue);
        }
    }

    // Scale the value of the pixels to the range of ASCII characters
    char grayscale_map[] = " .:-=+*#%@";
    int grayscale_map_len = strlen(grayscale_map);
    int max_gray_value = 255;
    float scaling_factor = (float)grayscale_map_len / (float)max_gray_value;

    // Output the ASCII image to file
    for (int i = 0; i < height; i++) {
        int row_offset = i * row_size;
        for (int j = 0; j < width; j++) {
            int pixel_offset = row_offset + j * 3;
            int gray_value = gray[pixel_offset];
            int char_index = (int)(gray_value * scaling_factor);
            fprintf(file_out, "%c", grayscale_map[char_index]);
        }
        fprintf(file_out, "\n");
    }

    // Free the memory
    free(img);
    free(gray);

    // Close the files
    fclose(file_in);
    fclose(file_out);

    return 0;
}