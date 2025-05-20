//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JPEG_HEADER_SIZE 20
#define PNG_CHUNK_SIZE 25

typedef struct {
    char format[4];
    unsigned int width;
    unsigned int height;
    unsigned char bitsPerPixel;
} ImageMetadata;

void extractJpegMetadata(const char *filename, ImageMetadata *metadata);
void extractPngMetadata(const char *filename, ImageMetadata *metadata);
void printMetadata(const ImageMetadata *metadata);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    ImageMetadata metadata;
    memset(&metadata, 0, sizeof(metadata));

    const char *filename = argv[1];
    if (strstr(filename, ".jpg") || strstr(filename, ".jpeg")) {
        extractJpegMetadata(filename, &metadata);
    } else if (strstr(filename, ".png")) {
        extractPngMetadata(filename, &metadata);
    } else {
        printf("Unsupported file format. Only JPEG and PNG files are supported.\n");
        return 1;
    }

    printMetadata(&metadata);
    return 0;
}

void extractJpegMetadata(const char *filename, ImageMetadata *metadata) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Failed to open JPEG file: %s\n", filename);
        return;
    }

    // Read JPG header
    fseek(file, 0, SEEK_SET);
    unsigned char header[JPEG_HEADER_SIZE];
    fread(header, sizeof(unsigned char), JPEG_HEADER_SIZE, file);

    // Sample width and height extraction (naive way)
    metadata->width = (header[18] << 8) | header[19];
    metadata->height = (header[16] << 8) | header[17];
    strcpy(metadata->format, "JPEG");

    fclose(file);
}

void extractPngMetadata(const char *filename, ImageMetadata *metadata) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Failed to open PNG file: %s\n", filename);
        return;
    }

    // Read PNG header and first chunk
    unsigned char header[PNG_CHUNK_SIZE];
    fread(header, sizeof(unsigned char), PNG_CHUNK_SIZE, file);

    // Check PNG signature
    if (header[0] != 0x89 || header[1] != 'P' || header[2] != 'N' || header[3] != 'G') {
        printf("This is not a valid PNG file.\n");
        fclose(file);
        return;
    }

    // Sample width and height extraction from IHDR chunk
    metadata->width = (header[16] << 24) | (header[17] << 16) | (header[18] << 8) | header[19];
    metadata->height = (header[20] << 24) | (header[21] << 16) | (header[22] << 8) | header[23];
    strcpy(metadata->format, "PNG");
    
    fclose(file);
}

void printMetadata(const ImageMetadata *metadata) {
    printf("Image Format: %s\n", metadata->format);
    printf("Width: %u pixels\n", metadata->width);
    printf("Height: %u pixels\n", metadata->height);
    printf("Bits per Pixel: %u\n", metadata->bitsPerPixel);
}