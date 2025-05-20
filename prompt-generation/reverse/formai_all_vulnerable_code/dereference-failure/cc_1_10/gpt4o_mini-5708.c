//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256
#define WATERMARK "Watermark!"
#define WATERMARK_SIZE strlen(WATERMARK)

void embedWatermark(const char *inputFile, const char *outputFile) {
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");
    if (!inFile || !outFile) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read file data
    fseek(inFile, 0, SEEK_END);
    long fileSize = ftell(inFile);
    fseek(inFile, 0, SEEK_SET);

    char *buffer = (char *)malloc(fileSize);
    fread(buffer, 1, fileSize, inFile);

    // Embed watermark
    for (int i = 0; i < WATERMARK_SIZE && i < fileSize; i++) {
        buffer[i] ^= WATERMARK[i]; // Simple XOR operation to embed watermark
    }

    // Write to output file
    fwrite(buffer, 1, fileSize, outFile);

    // Clean up
    free(buffer);
    fclose(inFile);
    fclose(outFile);
    printf("Watermark embedded successfully!\n");
}

void extractWatermark(const char *inputFile) {
    FILE *inFile = fopen(inputFile, "rb");
    if (!inFile) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read file data
    fseek(inFile, 0, SEEK_END);
    long fileSize = ftell(inFile);
    fseek(inFile, 0, SEEK_SET);

    char *buffer = (char *)malloc(fileSize);
    fread(buffer, 1, fileSize, inFile);

    // Extract watermark
    char extractedWatermark[WATERMARK_SIZE + 1];
    for (int i = 0; i < WATERMARK_SIZE && i < fileSize; i++) {
        extractedWatermark[i] = buffer[i] ^ WATERMARK[i]; // Reverse XOR operation
    }
    extractedWatermark[WATERMARK_SIZE] = '\0'; // Null-terminate the string

    printf("Extracted Watermark: %s\n", extractedWatermark);

    // Clean up
    free(buffer);
    fclose(inFile);
}

void displayMenu() {
    printf("Digital Watermarking Application\n");
    printf("1. Embed Watermark\n");
    printf("2. Extract Watermark\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    char inputFile[MAX_SIZE];
    char outputFile[MAX_SIZE];

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter input file name: ");
                fgets(inputFile, sizeof(inputFile), stdin);
                inputFile[strcspn(inputFile, "\n")] = 0; // Remove newline
                printf("Enter output file name: ");
                fgets(outputFile, sizeof(outputFile), stdin);
                outputFile[strcspn(outputFile, "\n")] = 0; // Remove newline
                embedWatermark(inputFile, outputFile);
                break;

            case 2:
                printf("Enter input file name to extract watermark: ");
                fgets(inputFile, sizeof(inputFile), stdin);
                inputFile[strcspn(inputFile, "\n")] = 0; // Remove newline
                extractWatermark(inputFile);
                break;

            case 3:
                printf("Exiting the application...\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);

    return 0;
}