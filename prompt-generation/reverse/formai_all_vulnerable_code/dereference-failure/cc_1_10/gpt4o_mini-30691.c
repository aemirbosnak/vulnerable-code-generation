//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)

// Define BMP header structures
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BMPFileHeader;

typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BMPInfoHeader;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGB;

void embedMessage(const char *inputFile, const char *outputFile, const char *message) {
    FILE *in = fopen(inputFile, "rb");
    if (!in) {
        printf("Could not open input file.\n");
        return;
    }

    FILE *out = fopen(outputFile, "wb");
    if (!out) {
        printf("Could not open output file.\n");
        fclose(in);
        return;
    }

    // Read BMP headers
    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;
    fread(&fileHeader, sizeof(BMPFileHeader), 1, in);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, in);

    // Write headers to the output file
    fwrite(&fileHeader, sizeof(BMPFileHeader), 1, out);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, out);

    int messageLength = strlen(message);
    int totalBytes = messageLength * 8 + 1; // Extra bit for the null terminator
    int index = 0;
    
    RGB pixel;

    while (fread(&pixel, sizeof(RGB), 1, in) == 1) {
        if (index < totalBytes) {
            // Extract the next bit of the message
            unsigned char bit = (message[index / 8] >> (7 - (index % 8))) & 1;

            // Embed the message bit into the least significant bit of the pixel
            pixel.red = (pixel.red & ~1) | bit;
            index++;
        }
        // Write out the modified pixel to the output file
        fwrite(&pixel, sizeof(RGB), 1, out);
    }

    // Close the files
    fclose(in);
    fclose(out);
}

void extractMessage(const char *inputFile) {
    FILE *in = fopen(inputFile, "rb");
    if(!in) {
        printf("Could not open input file.\n");
        return;
    }
    
    // Read BMP headers
    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;
    fread(&fileHeader, sizeof(BMPFileHeader), 1, in);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, in);

    RGB pixel;
    char message[1024] = {0};
    int index = 0;
    int messageLength = 0;

    while (fread(&pixel, sizeof(RGB), 1, in) == 1) {
        unsigned char bit = pixel.red & 1; // Extract LSB
        message[index / 8] |= (bit << (7 - (index % 8)));
        
        if (message[index / 8] == '\0') {
            messageLength = index / 8;
            break;
        }
        index++;
    }

    printf("Extracted Message: %s\n", message);
    
    // Close the file
    fclose(in);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <embed/extract> <input_file> <output_file/message>\n", argv[0]);
        return 1;
    }

    // Split behavior based on the first argument
    if (strcmp(argv[1], "embed") == 0) {
        embedMessage(argv[2], argv[3], argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessage(argv[2]);
    } else {
        printf("Invalid command. Use 'embed' or 'extract'.\n");
        return 1;
    }

    return 0;
}