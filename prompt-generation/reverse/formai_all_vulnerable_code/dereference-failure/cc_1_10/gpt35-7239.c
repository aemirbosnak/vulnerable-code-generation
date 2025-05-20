//FormAI DATASET v1.0 Category: Image compression ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BMP_HEADER_SIZE 54
#define COMPRESSION_RATIO 4

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./compress_image <input_image>\n");
        return 1;
    }

    FILE* input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Error opening %s\n", argv[1]);
        return 2;
    }

    // Read BMP header info
    uint8_t bmp_header[BMP_HEADER_SIZE];
    fread(bmp_header, sizeof(uint8_t), BMP_HEADER_SIZE, input_file);

    // Verify file is a BMP image
    if (bmp_header[0] != 'B' || bmp_header[1] != 'M') {
        printf("%s is not a BMP image\n", argv[1]);
        return 3;
    }

    // Read image width and height from BMP header
    uint32_t width = *(uint32_t*)(bmp_header + 18);
    uint32_t height = *(uint32_t*)(bmp_header + 22);

    // Determine padding for each scanline
    uint32_t padding = (4 - (width * 3) % 4) % 4;

    // Allocate memory for uncompressed image data
    uint8_t* image_data = (uint8_t*) calloc((size_t) height * (size_t) (width * 3 + padding), sizeof(uint8_t));
    fread(image_data, sizeof(uint8_t), (size_t) height * (size_t) (width * 3 + padding), input_file);
    fclose(input_file);

    // Allocate memory for compressed image data
    uint8_t* compressed_data = (uint8_t*) calloc((size_t) height * (size_t) (width * 3 / COMPRESSION_RATIO + padding), sizeof(uint8_t));

    // Loop through each pixel in the image and compress the RGB values
    uint32_t compressed_index = 0;
    for (uint32_t y = 0; y < height; y++) {
        for (uint32_t x = 0; x < width; x++) {
            uint32_t index = (y * (width * 3 + padding)) + x * 3;
            compressed_data[compressed_index] = image_data[index];
            compressed_data[compressed_index+1] = image_data[index+1];
            compressed_data[compressed_index+2] = image_data[index+2];
            compressed_index += 3;
            if (x % COMPRESSION_RATIO == 0) {
                compressed_index += padding; // Skip padding for compressed pixels
            }
        }
        compressed_index += padding * COMPRESSION_RATIO; // Add padding for compressed scanline
    }

    // Write compressed image data to a new BMP file
    char output_filename[strlen(argv[1]) + 5];
    strncpy(output_filename, argv[1], strlen(argv[1]) - 4);
    strcat(output_filename, "_c.bmp");
    FILE* output_file = fopen(output_filename, "wb");
    if (!output_file) {
        printf("Error creating %s\n", output_filename);
        return 4;
    }

    // Write BMP header info
    fwrite(bmp_header, sizeof(uint8_t), BMP_HEADER_SIZE, output_file);

    // Write compressed image data
    fwrite(compressed_data, sizeof(uint8_t), (size_t) height * (size_t) (width * 3 / COMPRESSION_RATIO + padding), output_file);
    fclose(output_file);

    // Free memory
    free(image_data);
    free(compressed_data);

    printf("Image compression complete! Compressed image saved as %s\n", output_filename);

    return 0;
}