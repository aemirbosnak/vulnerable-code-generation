//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK "EXAMPLE_WATERMARK"

void embedWatermark(FILE* input, FILE* output);
int detectWatermark(FILE* input);
void printUsage();

int main(int argc, char** argv) {
    if (argc < 4) {
        printUsage();
        return 1;
    }

    char* mode = argv[1];
    char* inputFilename = argv[2];
    char* outputFilename = argv[3];

    FILE* inputFile = fopen(inputFilename, "rb");
    if (inputFile == NULL) {
        printf("Error: could not open input file \"%s\"\n", inputFilename);
        return 1;
    }

    FILE* outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL) {
        printf("Error: could not open output file \"%s\"\n", outputFilename);
        fclose(inputFile);
        return 1;
    }

    if (strcmp(mode, "embed") == 0) {
        printf("Embedding watermark...\n");
        embedWatermark(inputFile, outputFile);
    }
    else if (strcmp(mode, "detect") == 0) {
        printf("Detecting watermark...\n");
        int result = detectWatermark(inputFile);
        if (result == 1) {
            printf("Watermark detected!\n");
        }
        else if (result == 0) {
            printf("No watermark detected.\n");
        }
        else {
            printf("An error occurred while detecting watermark.\n");
        }
    }
    else {
        printf("Error: unrecognized mode \"%s\"\n", mode);
        printUsage();
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}

void embedWatermark(FILE* input, FILE* output) {
    char buffer[256];
    int bufferLength = 0;
    int readBytes;
    while ((readBytes = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        int position = -1;
        for (int i = 0; i < readBytes; i++) {
            if (buffer[i] == '\n') {
                position = i;
                break;
            }
        }
        if (position != -1) {
            buffer[position] = '\0';
            bufferLength += position + 1;
            fwrite(buffer, 1, position + 1, output);
            fseek(input, -(readBytes - position - 1), SEEK_CUR);
            break;
        }
        fwrite(buffer, 1, readBytes, output);
        bufferLength += readBytes;
    }

    if (bufferLength > 0) {
        fwrite(WATERMARK, 1, strlen(WATERMARK), output);
    }

    while ((readBytes = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        fwrite(buffer, 1, readBytes, output);
    }
}

int detectWatermark(FILE* input) {
    char buffer[strlen(WATERMARK)];
    int readBytes;
    while ((readBytes = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        if (strncmp(buffer, WATERMARK, strlen(WATERMARK)) == 0) {
            return 1;
        }
        fseek(input, 1 - (int)strlen(WATERMARK), SEEK_CUR);
    }
    return 0;
}

void printUsage() {
    printf("Usage: watermark [embed|detect] input_file output_file\n");
}