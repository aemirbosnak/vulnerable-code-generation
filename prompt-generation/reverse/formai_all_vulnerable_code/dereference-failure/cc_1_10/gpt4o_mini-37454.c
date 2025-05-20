//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define MAX_RUN_LENGTH 255

void compress(const char *input, char *output) {
    int count, i = 0, j = 0;
    char currentChar;

    while (input[i] != '\0') {
        currentChar = input[i];
        count = 1;

        while (input[i + 1] == currentChar) {
            count++;
            i++;
            if (count == MAX_RUN_LENGTH) {
                break; // To prevent overflow in case of long runs
            }
        }

        output[j++] = currentChar;
        output[j++] = count;
        i++;
    }
    output[j] = '\0';
}

void decompress(const char *input, char *output) {
    int i = 0, j = 0;
    char currentChar;
    unsigned char count;

    while (input[i] != '\0') {
        currentChar = input[i];
        count = input[i + 1];

        for (int k = 0; k < count; k++) {
            output[j++] = currentChar;
        }
        i += 2; // Move to the next character and its count
    }
    output[j] = '\0';
}

void printUsage() {
    printf("Usage: ./compressor <option> <input_file> <output_file>\n");
    printf("Options:\n");
    printf("  -c : Compress the file\n");
    printf("  -d : Decompress the file\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printUsage();
        return EXIT_FAILURE;
    }

    FILE *inputFile, *outputFile;
    char inputBuffer[MAX_BUFFER];
    char outputBuffer[MAX_BUFFER * 2]; // Output can be larger than input
    const char *option = argv[1];

    inputFile = fopen(argv[2], "rb");
    if (!inputFile) {
        perror("Failed to open input file");
        return EXIT_FAILURE;
    }

    outputFile = fopen(argv[3], "wb");
    if (!outputFile) {
        fclose(inputFile);
        perror("Failed to open output file");
        return EXIT_FAILURE;
    }

    if (strcmp(option, "-c") == 0) {
        // Compress the input file
        while (fgets(inputBuffer, sizeof(inputBuffer), inputFile) != NULL) {
            compress(inputBuffer, outputBuffer);
            fputs(outputBuffer, outputFile);
        }

        printf("File compressed successfully.\n");
    } else if (strcmp(option, "-d") == 0) {
        // Decompress the input file
        while (fgets(inputBuffer, sizeof(inputBuffer), inputFile) != NULL) {
            decompress(inputBuffer, outputBuffer);
            fputs(outputBuffer, outputFile);
        }

        printf("File decompressed successfully.\n");
    } else {
        printUsage();
        fclose(inputFile);
        fclose(outputFile);
        return EXIT_FAILURE;
    }

    fclose(inputFile);
    fclose(outputFile);
    return EXIT_SUCCESS;
}