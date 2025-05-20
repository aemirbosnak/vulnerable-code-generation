//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Set the seed for the random number generator
    srand(time(NULL));

    // Generate a random string of characters
    char* watermark = (char*)malloc(100);
    for (int i = 0; i < 100; i++) {
        watermark[i] = 'A' + rand() % 26;
    }

    // Find the length of the watermark string
    int watermarkLength = strlen(watermark);

    // Read the input file
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read the contents of the input file
    char* inputData = (char*)malloc(100000);
    fread(inputData, sizeof(char), 100000, inputFile);
    fclose(inputFile);

    // Find the length of the input data
    int inputDataLength = strlen(inputData);

    // Calculate the number of chunks to split the input data into
    int chunks = (inputDataLength + watermarkLength - 1) / watermarkLength;

    // Initialize the watermark array
    int watermarkArray[chunks];
    for (int i = 0; i < chunks; i++) {
        watermarkArray[i] = 0;
    }

    // Calculate the starting position for each chunk
    for (int i = 0; i < chunks; i++) {
        watermarkArray[i] = i * watermarkLength;
    }

    // Modify the input data by embedding the watermark
    for (int i = 0; i < chunks; i++) {
        for (int j = 0; j < watermarkLength; j++) {
            inputData[watermarkArray[i] + j] = watermark[j];
        }
    }

    // Write the modified input data to an output file
    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fwrite(inputData, sizeof(char), inputDataLength, outputFile);
    fclose(outputFile);

    // Free the memory allocated for the watermark and input data
    free(watermark);
    free(inputData);

    return 0;
}