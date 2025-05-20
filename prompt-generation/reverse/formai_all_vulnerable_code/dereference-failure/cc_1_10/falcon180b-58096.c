//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to recover data from a corrupted file
void recoverData(FILE *file, char *output) {
    char ch;
    int count = 0;

    // Read the file until end of file is reached
    while ((ch = fgetc(file))!= EOF) {
        // Check if the character is a valid ASCII character
        if (ch >= 32 && ch <= 126) {
            // Write the character to the output file
            fprintf(output, "%c", ch);
            count++;
        } else {
            // Replace invalid characters with a space
            fprintf(output, " ");
        }
    }

    // Print the number of valid characters recovered
    printf("Recovered %d valid characters.\n", count);
}

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];

    // Get the names of the input and output files from the user
    printf("Enter the name of the corrupted file: ");
    scanf("%s", inputFileName);
    printf("Enter the name of the recovered file: ");
    scanf("%s", outputFileName);

    // Open the input file for reading
    inputFile = fopen(inputFileName, "rb");

    // Check if the input file was opened successfully
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Create the output file for writing
    outputFile = fopen(outputFileName, "w");

    // Check if the output file was created successfully
    if (outputFile == NULL) {
        printf("Error: Could not create output file.\n");
        exit(1);
    }

    // Recover data from the corrupted file
    recoverData(inputFile, outputFile);

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}