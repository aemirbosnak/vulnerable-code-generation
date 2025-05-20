//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_SIZE 1000
#define WATERMARK_SIZE 16

void embedWatermark(char *inputFile, char *outputFile, char *watermark);

int main() {
    char inputFile[MAX_SIZE], outputFile[MAX_SIZE], watermark[WATERMARK_SIZE];
    printf("Enter the name of input file: ");
    fgets(inputFile, MAX_SIZE, stdin);
    inputFile[strcspn(inputFile, "\n")] = 0;    // Removing newline character from input
    
    printf("Enter the name of output file: ");
    fgets(outputFile, MAX_SIZE, stdin);
    outputFile[strcspn(outputFile, "\n")] = 0;   // Removing newline character from output
    
    printf("Enter the watermark (max length 16 characters): ");
    fgets(watermark, WATERMARK_SIZE, stdin);
    watermark[strcspn(watermark, "\n")] = 0;    // Removing newline character from watermark
    
    embedWatermark(inputFile, outputFile, watermark);

    return 0;
}

// Function to embed the watermark in the input file and save the new file with the given output name
void embedWatermark(char *inputFile, char *outputFile, char *watermark) {
    FILE *input, *output;
    input = fopen(inputFile, "rb");   // Opening input file in binary read mode
    output = fopen(outputFile, "wb"); // Opening output file in binary write mode
    
    if(input == NULL || output == NULL) {  // Check if files are successfully opened
        printf("Unable to open files!");
        exit(1);
    }
    
    char watermarkByte, inputByte, outputByte;
    int watermarkBit, inputBit;

    srand(time(0)); // Setting seed for random number generation
    
    while(fread(&inputByte, sizeof(inputByte), 1, input)) {
        outputByte = inputByte;
        for(int i=0; i<8; i++) {
            if(i < 2) { // Embedding the watermark in the first 2 bits of each byte
                watermarkByte = watermark[i];
                watermarkBit = (watermarkByte >> 6) & 1;
            } else {    // Randomly flipping a bit to hide the watermark
                watermarkBit = rand() % 2;
            }
            inputBit = (inputByte >> i) & 1;
            if(inputBit != watermarkBit) {
                outputByte ^= (1 << i);
            }
        }
        fwrite(&outputByte, sizeof(outputByte), 1, output);
    }
    
    printf("Watermark Embedded successfully!\n");
    
    fclose(input);  // Closing input file
    fclose(output); // Closing output file
}