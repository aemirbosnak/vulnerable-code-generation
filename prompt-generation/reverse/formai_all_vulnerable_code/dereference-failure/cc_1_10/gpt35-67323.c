//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_W 80
#define MAX_H 24
// The ASCII characters used in the converter. 
// The characters are in order of darkness (e.g. ' ' is lighter than '_').
#define ASCII_CHARS " .:-=+*#%@"

// Function to load an image.
int load_image(FILE* f, uint8_t** data, uint32_t* w, uint32_t* h) {
    if (!f) {
        return -1;
    }
    // Load the width and height.
    fread(w, 4, 1, f);
    fread(h, 4, 1, f);
    // Allocate the memory for the image.
    *data = (uint8_t*)malloc((*w) * (*h));
    if (!*data) {
        return -1;
    }
    fread(*data, 1, (*w) * (*h), f);
    // Return 0 if everything is OK.
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return -1;
    }
    // Open the file.
    FILE* f = fopen(argv[1], "rb");
    if (!f) {
        printf("Failed to open file: %s\n", argv[1]);
        return -1;
    }
    // Load the image.
    uint32_t w, h;
    uint8_t* data;
    if (load_image(f, &data, &w, &h) != 0) {
        printf("Failed to load image.\n");
        return -1;
    }
    // Close the file.
    fclose(f);
    // Calculate the aspect ratio of the image.
    float aspect_ratio = (float)w / (float)h;
    // Figure out how wide and tall to make the output.
    uint32_t out_w = MAX_W;
    uint32_t out_h = (uint32_t)((float)out_w / aspect_ratio);
    // Make sure the output height isn't too big.
    if (out_h > MAX_H) {
        out_h = MAX_H;
        out_w = (uint32_t)((float)out_h * aspect_ratio);
    }
    // Calculate how much to scale the image down by.
    float scale_w = (float)w / (float)out_w;
    float scale_h = (float)h / (float)out_h;
    // Create the output image.
    char out_image[MAX_H][MAX_W + 1];
    // Loop through each row in the output image.
    for (int y = 0; y < out_h; y++) {
        // Loop through each column in the output image.
        for (int x = 0; x < out_w; x++) {
            // Calculate the corresponding coordinate in the input image.
            int in_x = (int)(x * scale_w);
            int in_y = (int)(y * scale_h);
            // Get the brightness of the pixel (0-255).
            uint8_t brightness = data[(in_y * w) + in_x];
            // Find the character that matches the brightness.
            int char_index = (int)(((float)brightness / 255.0f) * (sizeof(ASCII_CHARS) - 1));
            // Save the character to the output image.
            out_image[y][x] = ASCII_CHARS[char_index];
        }
        // Null-terminate the string.
        out_image[y][out_w] = 0;
    }
    // Print the output image.
    for (int y = 0; y < out_h; y++) {
        printf("%s\n", out_image[y]);
    }
    // Free the memory.
    free(data);
    // Return 0 to indicate success.
    return 0;
}