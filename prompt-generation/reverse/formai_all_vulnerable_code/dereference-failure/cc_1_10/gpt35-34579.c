//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define variables for watermarking
#define MAX_LEN 1000 // maximum length of the watermark
#define MAX_SIZE 4096 // maximum size of the image file

// function prototypes
void writeWatermark(const char* inputFile, const char* outputFile, const char* watermarkString);
void readWatermark(const char* outputFile);

// main function
int main()
{
    // declare variables
    char inputFile[MAX_LEN], outputFile[MAX_LEN], watermarkString[MAX_LEN];
    
    // get input file name from user
    printf("Enter input file name: ");
    scanf("%s", inputFile);
    
    // get output file name from user
    printf("Enter output file name: ");
    scanf("%s", outputFile);

    // get watermark string from user
    printf("Enter watermark string: ");
    scanf("%s", watermarkString);
    
    // call function to write watermark
    writeWatermark(inputFile, outputFile, watermarkString);

    // call function to read watermark
    printf("Watermark read from output file: ");
    readWatermark(outputFile);

    return 0;
}

// function to write watermark to image file
void writeWatermark(const char* inputFile, const char* outputFile, const char* watermarkString)
{
    // declare variables
    FILE *inFile, *outFile;
    char buffer[MAX_SIZE];

    // open input file for reading
    inFile = fopen(inputFile, "rb");
    if (inFile == NULL)
    {
        printf("Error: Unable to open input file %s\n", inputFile);
        exit(-1);
    }

    // open output file for writing
    outFile = fopen(outputFile, "wb");
    if (outFile == NULL)
    {
        printf("Error: Unable to open output file %s\n", outputFile);
        exit(-1);
    }

    // read input file into buffer
    int bytesRead = fread(buffer, sizeof(char), MAX_SIZE, inFile);

    // generate random key
    srand(time(NULL)); // seed random number generator
    int key = rand() % 255; // generate random key between 0 and 255
    
    // write key to output file
    fwrite(&key, sizeof(char), 1, outFile);

    // write watermark string to output file
    int watermarkLength = strlen(watermarkString);
    fwrite(&watermarkLength, sizeof(int), 1, outFile);
    for (int i = 0; i < watermarkLength; i++)
    {
        buffer[i] ^= key; // apply XOR encryption
        buffer[i] += watermarkString[i];
    }
    fwrite(buffer, sizeof(char), bytesRead, outFile);

    // close files
    fclose(inFile);
    fclose(outFile);
}

// function to read watermark from image file
void readWatermark(const char* outputFile)
{
    // declare variables
    FILE *file;
    char buffer[MAX_SIZE];

    // open output file for reading
    file = fopen(outputFile, "rb");
    if (file == NULL)
    {
        printf("Error: Unable to open output file %s\n", outputFile);
        exit(-1);
    }

    // read key from output file
    int key;
    fread(&key, sizeof(char), 1, file);

    // read watermark string from output file
    int watermarkLength;
    fread(&watermarkLength, sizeof(int), 1, file);
    int bytesRead = fread(buffer, sizeof(char), MAX_SIZE, file);
    for (int i = 0; i < watermarkLength; i++)
    {
        buffer[i] -= key; // reverse XOR encryption
        printf("%c", buffer[i]);
    }
    printf("\n");

    // close file
    fclose(file);
}