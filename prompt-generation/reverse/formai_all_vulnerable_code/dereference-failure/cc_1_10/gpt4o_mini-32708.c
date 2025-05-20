//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define WATERMARK_LEN 20
#define MAX_RAND 255
#define DATA_SIZE (WIDTH * HEIGHT * 3)

void generate_random_payload(uint8_t *data, size_t length) {
    srand(time(NULL));
    for(size_t i = 0; i < length; i++) {
        data[i] = rand() % MAX_RAND;
    }
}

void apply_watermark(uint8_t *image_data, const char *watermark) {
    size_t wm_length = strlen(watermark);
    
    for (size_t i = 0; i < wm_length; i++) {
        size_t x = (i % 100) + 10; // Spread out watermark over the width
        size_t y = (i / 100) + 10;  // Move down vertically
        
        // Calculate the pixel index
        size_t pixel_index = (y * WIDTH + x) * 3; // RGB
        
        if (pixel_index < DATA_SIZE) {
            // Manipulate the pixel colors based on the watermark character
            image_data[pixel_index] = (image_data[pixel_index] + watermark[i]) % 256; // Red
            image_data[pixel_index + 1] = (image_data[pixel_index + 1] + watermark[i]) % 256; // Green
            image_data[pixel_index + 2] = (image_data[pixel_index + 2] + watermark[i]) % 256; // Blue
        }
    }
}

void save_image(const char *filename, uint8_t *data) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s for writing.\n", filename);
        exit(EXIT_FAILURE);
    }
    
    // Create BMP header
    uint32_t file_size = 54 + DATA_SIZE; // 54 bytes of BMP header + pixel data size
    uint16_t bfType = 0x4D42; // "BM"
    uint32_t bfOffBits = 54; // Offset to the pixel data
    uint32_t biSize = 40; // Size of the info header
    uint32_t biWidth = WIDTH;
    uint32_t biHeight = HEIGHT;
    uint16_t biPlanes = 1; // Plane count
    uint16_t biBitCount = 24; // Bits per pixel
    uint32_t biCompression = 0; // No compression
    uint32_t biSizeImage = DATA_SIZE; // Size of the image data
    uint32_t biXPelsPerMeter = 0;
    uint32_t biYPelsPerMeter = 0;
    uint32_t biClrUsed = 0;
    uint32_t biClrImportant = 0;

    // Write BMP header
    fwrite(&bfType, sizeof(bfType), 1, file);
    fwrite(&file_size, sizeof(file_size), 1, file);
    fwrite("\0\0\0\0", 4, 1, file); // Reserved
    fwrite(&bfOffBits, sizeof(bfOffBits), 1, file);
    fwrite(&biSize, sizeof(biSize), 1, file);
    fwrite(&biWidth, sizeof(biWidth), 1, file);
    fwrite(&biHeight, sizeof(biHeight), 1, file);
    fwrite(&biPlanes, sizeof(biPlanes), 1, file);
    fwrite(&biBitCount, sizeof(biBitCount), 1, file);
    fwrite(&biCompression, sizeof(biCompression), 1, file);
    fwrite(&biSizeImage, sizeof(biSizeImage), 1, file);
    fwrite(&biXPelsPerMeter, sizeof(biXPelsPerMeter), 1, file);
    fwrite(&biYPelsPerMeter, sizeof(biYPelsPerMeter), 1, file);
    fwrite(&biClrUsed, sizeof(biClrUsed), 1, file);
    fwrite(&biClrImportant, sizeof(biClrImportant), 1, file);
    
    // Write pixel data
    fwrite(data, sizeof(uint8_t), DATA_SIZE, file);
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <output_image.bmp> <watermark_text>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *output_file = argv[1];
    const char *watermark_text = argv[2];

    if (strlen(watermark_text) > WATERMARK_LEN) {
        fprintf(stderr, "Error: Watermark must be less than %d characters.\n", WATERMARK_LEN);
        return EXIT_FAILURE;
    }

    // Allocate memory for image data
    uint8_t *image_data = (uint8_t *)malloc(DATA_SIZE);
    if (image_data == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Generate random pixel data for the cyberpunk image
    generate_random_payload(image_data, DATA_SIZE);
    
    // Apply watermark
    apply_watermark(image_data, watermark_text);
    
    // Save the watermarked image
    save_image(output_file, image_data);

    free(image_data);
    printf("Watermarked image saved as %s with watermark: %s\n", output_file, watermark_text);

    return EXIT_SUCCESS;
}