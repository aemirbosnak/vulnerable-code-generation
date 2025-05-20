//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Function to embed a single bit of data in a byte
void embedBitInByte(unsigned char *b, int bit) {
    if (bit) {
        *b |= 0x1; // Set the least significant bit to 1
    } else {
        *b &= ~0x1; // Set the least significant bit to 0
    }
}

// Function to extract a single bit of data from a byte
int extractBitFromByte(unsigned char b) {
    return b & 0x1; // Extract the least significant bit
}

// Function to embed a watermark in an image
// Creates a new file with _marked suffix
void embedWatermark(char *fileIn, char *fileOut, char *watermark) {
    FILE *fIn = fopen(fileIn, "rb");
    FILE *fOut = fopen(fileOut, "wb");
    FILE *wm = fopen(watermark, "rb");
    
    if (!fIn || !fOut || !wm) {
        printf("Error opening files!\n");
        return;
    }
    
    // Write the watermark size (in bits) to the output file
    fseek(wm, 0, SEEK_END);
    int wmSize = ftell(wm) * 8; // Convert bytes to bits
    fwrite(&wmSize, sizeof(int), 1, fOut);
    rewind(wm);
    
    // Embed the watermark in the image
    unsigned char byte;
    int bit;
    while (fread(&byte, sizeof(unsigned char), 1, fIn) == 1) {
        if (fread(&bit, sizeof(int), 1, wm) != 1) {
            rewind(wm); // Loop back to the start of the watermark file
            fread(&bit, sizeof(int), 1, wm);
        }
        
        embedBitInByte(&byte, bit);
        fwrite(&byte, sizeof(unsigned char), 1, fOut);
    }
    
    // Close the files
    fclose(fIn);
    fclose(fOut);
    fclose(wm);
}

// Function to extract a watermark from an image
void extractWatermark(char *fileIn, char *watermark) {
    FILE *fIn = fopen(fileIn, "rb");
    FILE *wm = fopen(watermark, "wb");
    
    if (!fIn || !wm) {
        printf("Error opening files!\n");
        return;
    }
    
    // Read the watermark size (in bits) from the input file
    int wmSize;
    fread(&wmSize, sizeof(int), 1, fIn);
    
    // Extract the watermark from the image
    unsigned char byte;
    int bit;
    for (int i = 0; i < wmSize; i++) {
        if (fread(&byte, sizeof(unsigned char), 1, fIn) != 1) {
            printf("Error: not enough data!\n");
            break;
        }
        
        bit = extractBitFromByte(byte);
        fwrite(&bit, sizeof(int), 1, wm);
    }
    
    // Close the files
    fclose(fIn);
    fclose(wm);
}

int main() {
    char *fileIn = "image.bmp";
    char *fileOut = "image_marked.bmp";
    char *watermark = "watermark.txt";
    
    embedWatermark(fileIn, fileOut, watermark);
    extractWatermark(fileOut, "watermark_extracted.txt");
    
    return 0;
}