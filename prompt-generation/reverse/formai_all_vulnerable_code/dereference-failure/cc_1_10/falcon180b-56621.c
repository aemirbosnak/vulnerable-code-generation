//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define IMAGE_WIDTH 256
#define IMAGE_HEIGHT 256
#define IMAGE_SIZE (IMAGE_WIDTH * IMAGE_HEIGHT)
#define WATERMARK_SIZE 64
#define WATERMARK_VALUE 42

// Read image from file
unsigned char* read_image(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char* image = (unsigned char*)malloc(filesize);
    fread(image, 1, filesize, fp);
    fclose(fp);

    return image;
}

// Write image to file
void write_image(const char* filename, unsigned char* image) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    fwrite(image, 1, IMAGE_SIZE, fp);
    fclose(fp);
}

// Apply watermark
void apply_watermark(unsigned char* image, int watermark_value) {
    int i, j;
    for (i = 0; i < IMAGE_WIDTH; i++) {
        for (j = 0; j < IMAGE_HEIGHT; j++) {
            int index = j * IMAGE_WIDTH + i;
            if (image[index] > 128) {
                image[index] += watermark_value;
            } else {
                image[index] -= watermark_value;
            }
        }
    }
}

// Extract watermark
int extract_watermark(unsigned char* image, int watermark_value) {
    int i, j;
    int sum = 0;

    for (i = 0; i < IMAGE_WIDTH; i++) {
        for (j = 0; j < IMAGE_HEIGHT; j++) {
            int index = j * IMAGE_WIDTH + i;
            if (image[index] > 128) {
                sum += image[index] - watermark_value;
            } else {
                sum += image[index] + watermark_value;
            }
        }
    }

    return sum;
}

int main() {
    // Read image from file
    unsigned char* image = read_image("image.bmp");

    // Apply watermark
    apply_watermark(image, WATERMARK_VALUE);

    // Write watermarked image to file
    write_image("watermarked_image.bmp", image);

    // Extract watermark
    int extracted_watermark = extract_watermark(image, WATERMARK_VALUE);

    printf("Watermark extracted: %d\n", extracted_watermark);

    return 0;
}