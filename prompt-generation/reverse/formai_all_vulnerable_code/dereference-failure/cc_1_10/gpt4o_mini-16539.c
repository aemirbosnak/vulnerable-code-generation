//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK "WATERMARKED"
#define MAX_SIZE 1024

void embedWatermark(const char *inputImageFile, const char *outputImageFile);
void extractWatermark(const char *inputImageFile);
void printUsage();

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printUsage();
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedWatermark(argv[2], argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractWatermark(argv[2]);
    } else {
        printUsage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void printUsage() {
    printf("Usage:\n");
    printf("  To embed watermark: ./watermark embed <input_image.ppm> <output_image.ppm>\n");
    printf("  To extract watermark: ./watermark extract <input_image.ppm>\n");
}

void embedWatermark(const char *inputImageFile, const char *outputImageFile) {
    FILE *inputFile = fopen(inputImageFile, "rb");
    FILE *outputFile = fopen(outputImageFile, "wb");

    if (!inputFile || !outputFile) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    // Read PPM header
    char header[100];
    fgets(header, sizeof(header), inputFile); // Read PPM type
    fprintf(outputFile, "%s", header);
    fgets(header, sizeof(header), inputFile); // Read image dimensions
    fprintf(outputFile, "%s", header);
    fgets(header, sizeof(header), inputFile); // Read max color value
    fprintf(outputFile, "%s", header);

    unsigned char buffer[MAX_SIZE];
    size_t bytesRead, totalBytes = 0;

    // Embed watermark
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)) > 0) {
        for (size_t i = 0; i < bytesRead && i < strlen(WATERMARK); ++i) {
            buffer[i] ^= WATERMARK[i];  // Simple XOR to embed watermark
        }
        totalBytes += bytesRead;
        fwrite(buffer, 1, bytesRead, outputFile);
    }

    printf("Watermark embedded in %zu bytes.\n", totalBytes);

    fclose(inputFile);
    fclose(outputFile);
}

void extractWatermark(const char *inputImageFile) {
    FILE *inputFile = fopen(inputImageFile, "rb");
    if (!inputFile) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read PPM header
    char header[100];
    fgets(header, sizeof(header), inputFile); // Read PPM type
    fgets(header, sizeof(header), inputFile); // Read image dimensions
    fgets(header, sizeof(header), inputFile); // Read max color value

    unsigned char buffer[MAX_SIZE];
    size_t bytesRead, totalBytes = 0;
    
    printf("Extracting watermark:\n");
    
    // Extract watermark
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)) > 0) {
        for (size_t i = 0; i < bytesRead && i < strlen(WATERMARK); ++i) {
            buffer[i] ^= WATERMARK[i];  // Simple XOR to extract watermark
        }
        totalBytes += bytesRead;
        printf("%.*s", (int)bytesRead, buffer);  // Print as string (for small data)
    }
    
    printf("\nTotal bytes read: %zu\n", totalBytes);

    fclose(inputFile);
}