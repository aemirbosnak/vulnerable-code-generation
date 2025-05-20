//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define WATERMARK "WATERMARK"
#define MARKING_BITS 4  // Number of bits to insert watermarking

void insert_watermark(unsigned char *image_data, int width, int height);
void save_image(const char *filename, unsigned char *image_data, int size);
void load_image(const char *filename, unsigned char **image_data, int *size);
void print_usage(const char *prog_name);
void error_exit(const char *message);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];

    unsigned char *image_data = NULL;
    int size = 0;

    load_image(input_file, &image_data, &size);
    if (image_data == NULL) {
        error_exit("Failed to load image");
    }

    int width = 256; // Hardcoded for simplicity; should be determined dynamically
    int height = 256; // Hardcoded for simplicity; should be determined dynamically

    insert_watermark(image_data, width, height);
    
    save_image(output_file, image_data, size);

    free(image_data);
    return EXIT_SUCCESS;
}

void insert_watermark(unsigned char *image_data, int width, int height) {
    int mark_length = strlen(WATERMARK);
    for (int i = 0; i < mark_length && i < MARKING_BITS; i++) {
        unsigned char mark_char = WATERMARK[i];
        // Insert watermark bits into image data
        for (int bit = 0; bit < 8; bit++) {
            int pixel_index = (i * 8 + bit) % (width * height); // Prevent overflow
            if (mark_char & (1 << (7 - bit))) {
                image_data[pixel_index] |= 1; // Set the least significant bit
            } else {
                image_data[pixel_index] &= 0xFE; // Clear the least significant bit
            }
        }
    }
}

void save_image(const char *filename, unsigned char *image_data, int size) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        error_exit("Could not open file for writing");
    }
    fwrite(image_data, sizeof(unsigned char), size, file);
    fclose(file);
}

void load_image(const char *filename, unsigned char **image_data, int *size) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        error_exit("Could not open file for reading");
    }

    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    rewind(file);

    *image_data = (unsigned char *)malloc(*size);
    if (*image_data == NULL) {
        error_exit("Memory allocation failed");
    }

    fread(*image_data, sizeof(unsigned char), *size, file);
    fclose(file);
}

void print_usage(const char *prog_name) {
    printf("Usage: %s <input_image> <output_image>\n", prog_name);
}

void error_exit(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}