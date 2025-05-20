//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BMP_HEADER_SIZE 54 // Skip the first 54 bytes for BMP
#define WATERMARK "WATERMARK"

// Function to read a BMP file and return its pixel data
unsigned char *read_bmp(const char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return NULL;
    }
    
    fseek(file, 18, SEEK_SET);
    fread(width, sizeof(int), 1, file);
    fread(height, sizeof(int), 1, file);

    int size = (*width) * (*height) * 3; // Assuming 24-bit BMP
    unsigned char *data = (unsigned char *)malloc(size);
    
    fseek(file, BMP_HEADER_SIZE, SEEK_SET);
    fread(data, sizeof(unsigned char), size, file);
    fclose(file);
    return data;
}

// Function to write the modified pixel data back to a BMP file
void write_bmp(const char *filename, unsigned char *data, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }
    
    // Write BMP header (54 bytes)
    unsigned char header[BMP_HEADER_SIZE] = {
        'B', 'M',  // Signature
        0, 0, 0, 0, // File size (to be filled)
        0, 0, // Reserved
        0, 0, // Reserved
        BMP_HEADER_SIZE, 0, 0, 0, // Offset to pixel data
        40, 0, 0, 0, // Info header size
        0, 0, 0, 0, // Width (to be filled)
        0, 0, 0, 0, // Height (to be filled)
        1, 0, // Color planes
        24, 0, // Bits per pixel
        0, 0, 0, 0, // Compression
        0, 0, 0, 0, // Image size (to be filled)
        0, 0, 0, 0, // Pixels per meter (not used)
        0, 0, 0, 0, // Colors in color table (not used)
        0, 0, 0, 0  // Important color count (not used)
    };

    int file_size = BMP_HEADER_SIZE + width * height * 3;
    header[2] = (unsigned char)(file_size);
    header[3] = (unsigned char)(file_size >> 8);
    header[4] = (unsigned char)(file_size >> 16);
    header[5] = (unsigned char)(file_size >> 24);

    header[18] = (unsigned char)(width);
    header[19] = (unsigned char)(width >> 8);
    header[20] = (unsigned char)(width >> 16);
    header[21] = (unsigned char)(width >> 24);

    header[22] = (unsigned char)(height);
    header[23] = (unsigned char)(height >> 8);
    header[24] = (unsigned char)(height >> 16);
    header[25] = (unsigned char)(height >> 24);

    fwrite(header, sizeof(unsigned char), BMP_HEADER_SIZE, file);
    fwrite(data, sizeof(unsigned char), width * height * 3, file);
    fclose(file);
}

// Function to embed watermark into the pixel data
void embed_watermark(unsigned char *data, int width, int height, const char *watermark) {
    int len = strlen(watermark);
    int index = 0;
    for (int i = 0; i < height && index < len; i++) {
        for (int j = 0; j < width && index < len; j++) {
            int pixelIndex = (i * width + j) * 3;
            // Modifying the blue channel slightly to embed the watermark
            data[pixelIndex] = (data[pixelIndex] & 0xFE) | ((watermark[index] >> (j % 8)) & 0x01);
            index++;
        }
    }
}

// Main function to drive the watermarking process
int main() {
    int width, height;
    
    unsigned char *image_data = read_bmp("input.bmp", &width, &height);
    if (image_data == NULL) {
        return EXIT_FAILURE;
    }

    embed_watermark(image_data, width, height, WATERMARK);
    write_bmp("output.bmp", image_data, width, height);

    free(image_data);
    printf("Watermarking completed successfully! Check output.bmp\n");
    return EXIT_SUCCESS;
}