//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: creative
#include <stdio.h>
#include <stdlib.h>

void embedWatermark(char* inputFilename, char* outputFilename, char* watermarkText);
void extractWatermark(char* inputFilename);

struct WatermarkHeader {
    char signature[4];
    int watermarkSize;
};

int main() {
    char inputFilename[] = "input_file.txt";
    char outputFilename[] = "output_file.txt";
    char watermarkText[] = "Watermark Text";

    printf("Embedding watermark...\n");
    embedWatermark(inputFilename, outputFilename, watermarkText);
    printf("Watermark embedded successfully!\n\n");

    printf("Extracting watermark...\n");
    extractWatermark(outputFilename);

    return 0;
}

void embedWatermark(char* inputFilename, char* outputFilename, char* watermarkText) {
    FILE* inputFile = fopen(inputFilename, "rb");
    if(inputFile == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }

    FILE* outputFile = fopen(outputFilename, "wb");
    if(outputFile == NULL) {
        printf("Error opening output file!\n");
        exit(1);
    }

    // Write header to output file
    struct WatermarkHeader header;
    header.signature[0] = 'W';
    header.signature[1] = 'M';
    header.signature[2] = 'K';
    header.signature[3] = '\0';
    header.watermarkSize = strlen(watermarkText);

    fwrite(&header, sizeof(header), 1, outputFile);

    // Write input file to output file
    char byte;
    while(fread(&byte, sizeof(byte), 1, inputFile) == 1) {
        fwrite(&byte, sizeof(byte), 1, outputFile);
    }

    // Write watermark to output file
    fwrite(watermarkText, sizeof(char), header.watermarkSize, outputFile);

    fclose(inputFile);
    fclose(outputFile);
}

void extractWatermark(char* inputFilename) {
    FILE* inputFile = fopen(inputFilename, "rb");
    if(inputFile == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }

    // Read header from input file
    struct WatermarkHeader header;
    fread(&header, sizeof(header), 1, inputFile);

    // Seek to the start of the watermark
    fseek(inputFile, -(header.watermarkSize), SEEK_END);

    // Read the watermark from the file
    char* watermarkText = (char*) malloc(sizeof(char) * header.watermarkSize);
    fread(watermarkText, sizeof(char), header.watermarkSize, inputFile);

    printf("Extracted Watermark: %s\n", watermarkText);

    fclose(inputFile);
}