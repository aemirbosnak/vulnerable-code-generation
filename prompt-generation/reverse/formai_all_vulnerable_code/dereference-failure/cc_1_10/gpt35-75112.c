//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the dimensions of the image
#define WIDTH 100
#define HEIGHT 50

// Define the maximum size of the ASCII art buffer
#define MAX_BUFFER_SIZE 10000

// Function to convert the intensity of a pixel to a character
char intensityToChar(int intensity) {
    const char *chars = " .`^\",:;Il!i><~+_-?][}{1)(\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
    int chars_len = strlen(chars);

    // Calculate the index in the chars string based on the intensity
    int index = (intensity * chars_len) / 255;

    return chars[index];
}

// Function to convert a C image to ASCII art
char* convertImageToAscii(char* image) {
    // Allocate memory for the ASCII art buffer
    char* ascii = malloc(MAX_BUFFER_SIZE);

    // Calculate the size of each cell in the image (assuming 24-bit RGB)
    int cell_size = (3 * WIDTH * HEIGHT) / (WIDTH * HEIGHT * 8);

    // Loop through each pixel in the image
    int y, x, i = 0;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            // Calculate the index of the current pixel in the image buffer
            int index = (y * WIDTH + x) * cell_size;

            // Get the intensity of the current pixel
            int intensity = (unsigned char) (0.21 * image[index] + 0.72 * image[index + 1] + 0.07 * image[index + 2]);

            // Convert the intensity to a character and add it to the ASCII art buffer
            ascii[i++] = intensityToChar(intensity);
        }

        // Add a newline character after each row of the ASCII art
        ascii[i++] = '\n';
    }

    // Add a null terminator to the end of the ASCII art buffer
    ascii[i] = '\0';

    return ascii;
}

int main() {
    // Open the image file
    FILE* file = fopen("image.bmp", "rb");

    if (!file) {
        printf("Failed to open image file\n");
        return 1;
    }

    // Read the image header (we only care about the width and height)
    fseek(file, 18, SEEK_SET);
    int image_width = 0, image_height = 0;
    fread(&image_width, 4, 1, file);
    fread(&image_height, 4, 1, file);
    fseek(file, 0, SEEK_SET);
    printf("Image dimensions: %dx%d\n", image_width, image_height);

    // Allocate memory for the image buffer
    char* image = malloc(3 * image_width * image_height);

    // Read the image into the buffer
    int image_size = fread(image, 1, 3 * image_width * image_height, file);

    printf("Read %d bytes from image file\n", image_size);

    // Convert the image to ASCII art
    char* ascii = convertImageToAscii(image);

    // Print the ASCII art
    printf("%s", ascii);

    // Free the memory used by the image and ASCII art buffers
    free(image);
    free(ascii);

    // Close the file
    fclose(file);

    return 0;
}