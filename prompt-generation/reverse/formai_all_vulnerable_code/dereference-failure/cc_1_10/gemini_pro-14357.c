//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE 1024
#define IMAGE_SIZE 1024*1024*3

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

int main() {
    // Open the image file
    char* filename = "image.bmp";
    FILE* image_file = fopen(filename, "rb");
    if (image_file == NULL) {
        printf("Error opening file %s\n", filename);
        return EXIT_FAILURE;
    }

    // Read the image data
    pixel* image_data = malloc(IMAGE_SIZE * sizeof(pixel));
    fread(image_data, IMAGE_SIZE, sizeof(pixel), image_file);
    fclose(image_file);

    // Extract the data from the image
    unsigned char data[DATA_SIZE];
    int data_size = DATA_SIZE;
    int bit_offset = 0;

    for (int i = 0; i < IMAGE_SIZE; i++) {
        // Extract the least significant bit of each color component
        unsigned char red = image_data[i].red;
        unsigned char green = image_data[i].green;
        unsigned char blue = image_data[i].blue;

        data[bit_offset / 8] |= (red & 1) << (bit_offset % 8);
        data[bit_offset / 8] |= (green & 1) << (bit_offset % 8);
        data[bit_offset / 8] |= (blue & 1) << (bit_offset % 8);
        bit_offset += 3;

        // Stop when the data size has been reached
        if (bit_offset >= data_size * 8) {
            break;
        }
    }

    // Print the extracted data
    printf("Extracted data: %s\n", data);

    // Free the memory
    free(image_data);

    return EXIT_SUCCESS;
}