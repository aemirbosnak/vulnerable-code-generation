//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Change these values to adjust the resolution of the ASCII art
#define WIDTH 80
#define HEIGHT 60

// Greyscale values in ascending order
static const char *grey_chars = " .:-=+*#%@";
#define NUM_GREY_CHARS (sizeof(grey_chars) - 1)

// Function to load image data from a file
static uint8_t *load_image(const char *path, uint32_t *w, uint32_t *h) {
    // Open the file
    FILE *fp = fopen(path, "rb");
    if (!fp) {
        fprintf(stderr, "Failed to open file '%s'\n", path);
        return NULL;
    }

    // Read the header data
    uint32_t width, height;
    fseek(fp, 18, SEEK_SET);
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);
    if (width <= 0 || height <= 0) {
        fclose(fp);
        fprintf(stderr, "Invalid image dimensions: %dx%d\n", width, height);
        return NULL;
    }

    // Allocate memory for the image data
    uint32_t row_size = (3 * width + 3) & (~3);
    uint32_t data_size = row_size * height;
    uint8_t *data = (uint8_t *)malloc(data_size);
    if (!data) {
        fclose(fp);
        return NULL;
    }

    // Read the image data row by row (in reverse order)
    fseek(fp, 54, SEEK_SET);
    for (int32_t y = height - 1; y >= 0; y--) {
        uint8_t *row_data = data + y * row_size;
        fread(row_data, row_size, 1, fp);
    }

    // Return image data and dimensions
    *w = width;
    *h = height;
    return data;
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    // Load the image data
    uint32_t width, height;
    uint8_t *data = load_image(argv[1], &width, &height);
    if (!data) {
        fprintf(stderr, "Failed to load image '%s'\n", argv[1]);
        return 1;
    }

    // Scale image data to fit within the ASCII art resolution
    float scale_x = (float)width / WIDTH;
    float scale_y = (float)height / HEIGHT;
    uint8_t *scaled_data = (uint8_t *)malloc(WIDTH * HEIGHT);
    if (!scaled_data) {
        free(data);
        return 1;
    }
    for (uint32_t y = 0; y < HEIGHT; y++) {
        for (uint32_t x = 0; x < WIDTH; x++) {
            uint32_t sx = (uint32_t)(x * scale_x);
            uint32_t sy = (uint32_t)(y * scale_y);
            uint8_t *pixel = data + (sy * width + sx) * 3;
            uint8_t value = (pixel[0] + pixel[1] + pixel[2]) / 3;
            scaled_data[y * WIDTH + x] = value;
        }
    }

    // Generate ASCII art
    char art[HEIGHT * (WIDTH + 1) + 1];
    memset(art, 0, sizeof(art));
    for (uint32_t y = 0; y < HEIGHT; y++) {
        for (uint32_t x = 0; x < WIDTH; x++) {
            uint8_t value = scaled_data[y * WIDTH + x];
            uint8_t char_idx = (value * NUM_GREY_CHARS) / 256;
            art[y * (WIDTH + 1) + x] = grey_chars[char_idx];
        }
        art[y * (WIDTH + 1) + WIDTH] = '\n';
    }

    // Print the ASCII art
    printf("%s", art);

    // Clean up
    free(data);
    free(scaled_data);
    return 0;
}