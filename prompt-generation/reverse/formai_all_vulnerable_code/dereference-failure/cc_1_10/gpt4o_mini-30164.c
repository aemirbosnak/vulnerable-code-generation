//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

void embedWatermark(const char *inputFile, const char *watermark, const char *outputFile) {
    FILE *in = fopen(inputFile, "rb");
    if (!in) {
        perror("Error opening input file");
        return;
    }
    
    FILE *out = fopen(outputFile, "wb");
    if (!out) {
        perror("Error opening output file");
        fclose(in);
        return;
    }

    char header[100];
    fgets(header, sizeof(header), in);
    fprintf(out, "%s", header); // Copy header to output file
    
    // Read image width and height
    int width, height, maxval;
    fscanf(in, "%d %d\n%d", &width, &height, &maxval);
    fprintf(out, "%d %d\n%d\n", width, height, maxval);
    
    unsigned char pixel;
    int watermarkLength = strlen(watermark);
    int watermarkBitIndex = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fread(&pixel, sizeof(unsigned char), 1, in);
            // Embed watermark bits into the pixel's LSB
            if (watermarkBitIndex < watermarkLength * 8) {
                pixel = (pixel & 0xFE) | ((watermark[(watermarkBitIndex / 8)] >> (7 - (watermarkBitIndex % 8))) & 0x01);
                watermarkBitIndex++;
            }
            fwrite(&pixel, sizeof(unsigned char), 1, out);
        }
    }

    fclose(in);
    fclose(out);
    printf("Watermark embedded successfully.\n");
}

void extractWatermark(const char *inputFile, char *watermark, int maxWatermarkLength) {
    FILE *in = fopen(inputFile, "rb");
    if (!in) {
        perror("Error opening input file");
        return;
    }

    char header[100];
    fgets(header, sizeof(header), in);
    fscanf(in, "%*[^\n]"); // Skip width and height
    fscanf(in, "%*[^\n]\n"); // Skip max value

    unsigned char pixel;
    int watermarkBitIndex = 0;
    char extractedWatermark[MAX] = {0};

    for (int i = 0; watermarkBitIndex / 8 < maxWatermarkLength; i++) {
        fread(&pixel, sizeof(unsigned char), 1, in);
        // Extract watermark bits from pixel's LSB
        if (watermarkBitIndex < maxWatermarkLength * 8) {
            extractedWatermark[watermarkBitIndex / 8] <<= 1; // Shift to make space for next bit
            extractedWatermark[watermarkBitIndex / 8] |= (pixel & 0x01);
            watermarkBitIndex++;
        }
    }

    fclose(in);
    strncpy(watermark, extractedWatermark, maxWatermarkLength);
    watermark[maxWatermarkLength - 1] = '\0'; // Null-terminate
    printf("Extracted watermark: %s\n", watermark);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <input.pgm> <watermark> <output.pgm> <max_watermark_len>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[1];
    const char *watermark = argv[2];
    const char *outputFile = argv[3];
    int maxWatermarkLength = atoi(argv[4]);
    
    embedWatermark(inputFile, watermark, outputFile);

    char extractedWatermark[MAX];
    extractWatermark(outputFile, extractedWatermark, maxWatermarkLength);

    return EXIT_SUCCESS;
}