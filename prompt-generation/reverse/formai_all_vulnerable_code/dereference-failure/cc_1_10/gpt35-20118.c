//FormAI DATASET v1.0 Category: Data recovery tool ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define the structure for file header
typedef struct {
    char fileType[8];
    int fileSize;
    int fileOffset;
} __attribute__((packed)) FileHeader;

// Define the structure for image header
typedef struct {
    int width;
    int height;
    int bitsPerPixel;
} __attribute__((packed)) ImageHeader;

// Define the structure for pixel data
typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} __attribute__((packed)) PixelData;

// Function to read bytes from file
void readFileBytes(FILE* fp, void* buffer, size_t numBytes) {
    size_t bytesRead = fread(buffer, 1, numBytes, fp);
    if (bytesRead != numBytes) {
        printf("Error reading file.");
        exit(1);
    }
}

int main() {
    char fileName[256];
    printf("Enter the filename: ");
    scanf("%s", fileName);

    // Open the file
    FILE* fp = fopen(fileName, "rb");
    if (fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    // Read the file header
    FileHeader fileHeader;
    readFileBytes(fp, &fileHeader, sizeof(FileHeader));

    // Verify the file magic number
    if (strncmp(fileHeader.fileType, "BM", 2) != 0) {
        printf("Invalid file format. Expected BM.");
        exit(1);
    }

    // Read the image header
    ImageHeader imageHeader;
    readFileBytes(fp, &imageHeader, sizeof(ImageHeader));

    // Verify the image is in 24-bit color format
    if (imageHeader.bitsPerPixel != 24) {
        printf("Invalid image format. Expected 24-bit color.");
        exit(1);
    }

    // Allocate memory for the pixel data
    PixelData* pixelData = malloc(imageHeader.width * imageHeader.height * sizeof(PixelData));
    if (pixelData == NULL) {
        printf("Failed to allocate memory for pixel data.");
        exit(1);
    }

    // Read the pixel data
    unsigned char padding[3] = {0};
    for (int i = 0; i < imageHeader.height; i++) {
        for (int j = 0; j < imageHeader.width; j++) {
            readFileBytes(fp, &pixelData[i * imageHeader.width + j], sizeof(PixelData));
        }
        // Skip any padding bytes at end of row
        readFileBytes(fp, padding, (4 - (imageHeader.width * sizeof(PixelData)) % 4) % 4);
    }

    // Write the pixel data to a new file
    char outputFileName[256];
    printf("Enter the output filename: ");
    scanf("%s", outputFileName);
    FILE* outFp = fopen(outputFileName, "wb");
    if (outFp == NULL) {
        printf("Error writing output file.");
        exit(1);
    }

    // Write the file header and image header
    fwrite(&fileHeader, sizeof(FileHeader), 1, outFp);
    fwrite(&imageHeader, sizeof(ImageHeader), 1, outFp);

    // Write the pixel data
    for (int i = 0; i < imageHeader.height; i++) {
        for (int j = 0; j < imageHeader.width; j++) {
            fwrite(&pixelData[i * imageHeader.width + j], sizeof(PixelData), 1, outFp);
        }
        // Write any padding bytes at end of row
        fwrite(padding, (4 - (imageHeader.width * sizeof(PixelData)) % 4) % 4, 1, outFp);
    }

    // Clean up
    fclose(fp);
    fclose(outFp);
    free(pixelData);

    printf("File recovery successful. Output file: %s\n", outputFileName);

    return 0;
}