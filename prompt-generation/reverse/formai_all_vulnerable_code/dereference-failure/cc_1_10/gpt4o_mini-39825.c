//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 255
#define MAX_WATERMARK_LENGTH 50

// Function to read PGM image
unsigned char* read_pgm(const char* filename, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format); // Read the format
    if (format[0] != 'P' || format[1] != '5') {
        fprintf(stderr, "Unsupported PGM format.\n");
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d %d", width, height);
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file); // consume the newline

    unsigned char* image = (unsigned char*)malloc(*width * *height);
    fread(image, 1, (*width) * (*height), file);
    fclose(file);
    return image;
}

// Function to write PGM image
void write_pgm(const char* filename, unsigned char* image, int width, int height) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    fprintf(file, "P5\n%d %d\n%d\n", width, height, MAX_VALUE);
    fwrite(image, 1, width * height, file);
    fclose(file);
}

// Function to embed watermark into the image
void embed_watermark(unsigned char* image, int width, int height, const char* watermark) {
    int watermarkLength = 0;
    while (watermark[watermarkLength] != '\0' && watermarkLength < MAX_WATERMARK_LENGTH) {
        watermarkLength++;
    }
    
    for (int i = 0; i < watermarkLength; i++) {
        // Modify the pixel values to embed the watermark
        int pixelIndex = (i * (width * height / watermarkLength)) % (width * height);
        image[pixelIndex] = (image[pixelIndex] & 0xFE) | ((watermark[i] >> 7) & 0x01); // LSB modification
    }
}

// Function to extract watermark from the image
void extract_watermark(unsigned char* image, int width, int height, char* watermark, int maxLength) {
    for (int i = 0; i < maxLength; i++) {
        int pixelIndex = (i * (width * height / maxLength)) % (width * height);
        watermark[i] = (image[pixelIndex] & 0x01) << 7; // Grab the LSB
    }
    watermark[maxLength] = '\0'; // Null-terminate the string
}

int main() {
    int width, height;
    unsigned char* image = read_pgm("input.pgm", &width, &height);
    if (!image) {
        return EXIT_FAILURE;
    }

    const char* watermark = "WMARK";
    char extractedWatermark[MAX_WATERMARK_LENGTH + 1];

    // Embed the watermark
    embed_watermark(image, width, height, watermark);
    write_pgm("watermarked.pgm", image, width, height);

    // Clear the image buffer for extraction demonstration
    unsigned char* imageToExtract = read_pgm("watermarked.pgm", &width, &height);
    if (!imageToExtract) {
        free(image);
        return EXIT_FAILURE;
    }

    // Extract the watermark
    extract_watermark(imageToExtract, width, height, extractedWatermark, MAX_WATERMARK_LENGTH);
    
    printf("Extracted Watermark: %s\n", extractedWatermark);

    // Cleanup
    free(image);
    free(imageToExtract);

    return EXIT_SUCCESS;
}