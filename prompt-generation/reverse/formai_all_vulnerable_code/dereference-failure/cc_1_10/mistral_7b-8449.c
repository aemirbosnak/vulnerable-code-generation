//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_SIZE 1024

typedef struct {
    double a;
    double b;
    double sum;
} Data;

int main() {
    FILE *inputFile, *outputFile;
    Data data;

    // Open input file in binary mode
    inputFile = fopen("input.bin", "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Allocate memory for reading data
    Data *dataSet = (Data *) malloc(FILE_SIZE * sizeof(Data));

    // Read data from file into memory
    fread(dataSet, sizeof(Data), FILE_SIZE, inputFile);
    fclose(inputFile);

    // Process data in memory
    for (int i = 0; i < FILE_SIZE; i++) {
        data = dataSet[i];
        data.sum = data.a + data.b;
    }

    // Open output file in binary mode
    outputFile = fopen("output.bin", "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        free(dataSet);
        return 1;
    }

    // Write processed data to file
    fwrite(dataSet, sizeof(Data), FILE_SIZE, outputFile);
    fclose(outputFile);

    // Free memory
    free(dataSet);

    printf("Data processed successfully.\n");
    return 0;
}