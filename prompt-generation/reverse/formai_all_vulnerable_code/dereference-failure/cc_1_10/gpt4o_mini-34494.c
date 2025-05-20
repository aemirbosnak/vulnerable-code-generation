//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SECRET_CODE "THIS_IS_A_SECRET"
#define MAX_FILENAME_LEN 256
#define MAX_WATERMARK_LEN 256
#define IMAGE_HEADER_SIZE 54

void paranoia_check(const char *filename) {
    // A paranoid check to ensure no one's tampering with our data
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file for paranoia check");
        exit(EXIT_FAILURE);
    }

    // Read the beginning of the file
    unsigned char header[IMAGE_HEADER_SIZE];
    fread(header, sizeof(unsigned char), IMAGE_HEADER_SIZE, file);
    
    // Check for specific file signature
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "The file is not a valid BMP file! Paranoia Check Failed!\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

void generate_watermark(char *watermark) {
    strcpy(watermark, SECRET_CODE);
    // Intentionally obfuscate the watermark to prevent easy extraction
    for (int i = 0; watermark[i] != '\0'; i++) {
        watermark[i] += 1; // Simple obfuscation
    }
}

void embed_watermark(const char *image_path, const char *output_path, const char *watermark) {
    paranoia_check(image_path);
    
    FILE *image_file = fopen(image_path, "rb");
    FILE *output_file = fopen(output_path, "wb");
    
    if (!image_file || !output_file) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    // Copy header
    unsigned char header[IMAGE_HEADER_SIZE];
    fread(header, sizeof(unsigned char), IMAGE_HEADER_SIZE, image_file);
    fwrite(header, sizeof(unsigned char), IMAGE_HEADER_SIZE, output_file);
    
    // Embed watermark into the pixel data
    unsigned char pixel;
    size_t watermark_length = strlen(watermark);
    size_t watermark_index = 0;
    while (fread(&pixel, sizeof(unsigned char), 1, image_file)) {
        // Embed bits of the watermark into the least significant bit of the pixel
        pixel = (pixel & ~1) | (watermark[watermark_index % watermark_length] & 1);
        fwrite(&pixel, sizeof(unsigned char), 1, output_file);
        watermark_index++;
    }

    fclose(image_file);
    fclose(output_file);
}

void extract_watermark(const char *image_path, char *watermark) {
    paranoia_check(image_path);
    
    FILE *image_file = fopen(image_path, "rb");
    if (!image_file) {
        perror("Error opening image file for extraction");
        exit(EXIT_FAILURE);
    }

    // Skip header
    fseek(image_file, IMAGE_HEADER_SIZE, SEEK_SET);
    
    unsigned char pixel;
    size_t index = 0;
    while (fread(&pixel, sizeof(unsigned char), 1, image_file)) {
        // Extract the watermark from the least significant bit of the pixel
        watermark[index++] = (pixel & 1) ? '1' : '0';
        // Add a stopping condition if we detect that change in the watermark
        if (index >= MAX_WATERMARK_LEN - 1) {
            break;
        }
    }
    watermark[index] = '\0'; // Null-terminate the extracted watermark

    fclose(image_file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <operation> <image_path> <output_path>\n", argv[0]);
        fprintf(stderr, "Operations: embed | extract\n");
        return EXIT_FAILURE;
    }

    const char *operation = argv[1];
    const char *image_path = argv[2];
    const char *output_path = argv[3];

    if (strcmp(operation, "embed") == 0) {
        char watermark[MAX_WATERMARK_LEN];
        generate_watermark(watermark);
        embed_watermark(image_path, output_path, watermark);
        printf("Watermark embedded successfully.\n");
    } else if (strcmp(operation, "extract") == 0) {
        char watermark[MAX_WATERMARK_LEN];
        extract_watermark(image_path, watermark);
        printf("Extracted watermark: %s\n", watermark);
    } else {
        fprintf(stderr, "Invalid operation. Use 'embed' or 'extract'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}