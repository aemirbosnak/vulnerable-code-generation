//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 100
#define MAX_IMAGE_SIZE 1024

void applyWatermark(unsigned char *image, const char *watermark, int imageSize, int watermarkSize);
void printUsage(const char *programName);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    FILE *imageFile = fopen(argv[1], "rb");
    if (!imageFile) {
        perror("Unable to open image file");
        return EXIT_FAILURE;
    }

    FILE *outputFile = fopen(argv[2], "wb");
    if (!outputFile) {
        fclose(imageFile);
        perror("Unable to open output file");
        return EXIT_FAILURE;
    }

    const char *watermark = argv[3];
    int watermarkSize = strlen(watermark);

    unsigned char image[MAX_IMAGE_SIZE];
    size_t readSize = fread(image, 1, MAX_IMAGE_SIZE, imageFile);
    if (readSize <= 0) {
        fclose(imageFile);
        fclose(outputFile);
        perror("Failed to read image file");
        return EXIT_FAILURE;
    }

    // Apply the watermark
    applyWatermark(image, watermark, readSize, watermarkSize);
    
    // Write the modified image to the output file
    fwrite(image, 1, readSize, outputFile);

    fclose(imageFile);
    fclose(outputFile);

    printf("Watermark applied successfully!\n");
    return EXIT_SUCCESS;
}

void applyWatermark(unsigned char *image, const char *watermark, int imageSize, int watermarkSize) {
    // Insert the watermark in a unique manner
    for (int i = 0; i < imageSize && i < watermarkSize; i++) {
        if (i % 2 == 0) {
            // Modify every even index with watermark bytes
            image[i] = (image[i] & 0xFE) | (watermark[i] & 0x01);
        }
        // Otherwise leave the pixel unchanged on odd indices
    }
}

void printUsage(const char *programName) {
    printf("Usage: %s <input_image> <output_image> <watermark>\n", programName);
    printf("Example:\n");
    printf("  %s input.ppm output.ppm 'MyWatermark'\n", programName);
}