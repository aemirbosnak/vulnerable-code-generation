//FormAI DATASET v1.0 Category: Compression algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of characters 
// in the input file
int countChars(FILE *inputFile) 
{
    int count = 0;
    char currentChar = fgetc(inputFile);
    while(currentChar != EOF) 
    {
        count++;
        currentChar = fgetc(inputFile);
    }
    rewind(inputFile);
    return count;
}

// Function that compresses the input file and writes
// the compressed data to the output file
void compress(FILE *inputFile, FILE *outputFile) 
{
    int count = countChars(inputFile);
    char *inputData = (char*) malloc(count * sizeof(char));
    fread(inputData, sizeof(char), count, inputFile);

    int i, j, runLength;
    char currentChar;
    for (i = 0; i < count; i++) 
    {
        currentChar = inputData[i];
        runLength = 1;
        for (j = i + 1; j < count; j++) 
        {
            if (inputData[j] != currentChar) 
            {
                break;
            }
            runLength++;
        }
        fprintf(outputFile, "%d%c", runLength, currentChar);
        i += (runLength - 1);
    }
    free(inputData);
}

// Main function to run the program
int main(int argc, char **argv) 
{
    if (argc != 3) 
    {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }

    // Open the input file
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) 
    {
        printf("Could not open input file %s\n", argv[1]);
        exit(1);
    }

    // Open the output file
    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) 
    {
        printf("Could not open output file %s\n", argv[2]);
        exit(1);
    }

    // Compress the input file and write the compressed data to the output file
    compress(inputFile, outputFile);

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    printf("File compression complete!\n");
    return 0;
}