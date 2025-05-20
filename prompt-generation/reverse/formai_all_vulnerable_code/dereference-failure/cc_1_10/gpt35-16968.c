//FormAI DATASET v1.0 Category: Data recovery tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to Custom Data Recovery Tool!\n");

    FILE *inputFile, *outputFile;
    char inputFileName[50], outputFileName[50];
    int fileSize, i;

    // Take user input for input file name
    printf("Enter the name of the file you want to recover: ");
    scanf("%s", inputFileName);

    // Open input file
    inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL)
    {
        printf("Error: Unable to open input file\n");
        exit(1);
    }

    // Get file size
    fseek(inputFile, 0, SEEK_END);
    fileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    // Allocate memory for input data
    char *inputData = malloc(fileSize * sizeof(char));
    if (inputData == NULL)
    {
        printf("Error: Unable to allocate memory for input data\n");
        exit(1);
    }

    // Read input data
    fread(inputData, fileSize, 1, inputFile);

    // Close input file
    fclose(inputFile);

    // Take user input for output file name
    printf("\nEnter the name of the file you want to save the recovered data to: ");
    scanf("%s", outputFileName);

    // Open output file
    outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL)
    {
        printf("Error: Unable to create output file\n");
        exit(1);
    }

    // Write recovered data to output file
    for (i = 0; i < fileSize; i++)
    {
        if (inputData[i] != '\0')
        {
            fwrite(&inputData[i], sizeof(char), 1, outputFile);
        }
    }

    printf("\nData recovery successful! Check '%s' for your recovered data.\n", outputFileName);

    // Close output file
    fclose(outputFile);

    // Free memory allocated for input data
    free(inputData);

    return 0;
}