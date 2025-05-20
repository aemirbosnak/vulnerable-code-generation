//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100

/* Function to insert a watermark message into a binary file */
void insertWatermark(char* inputFile, char* outputFile, char* watermark) {
    FILE *in, *out;
    char message[MAX_MESSAGE_LENGTH];

    // Open input and output files
    if ((in = fopen(inputFile, "rb")) == NULL) {
        printf("Error: Cannot open input file!\n");
        exit(1);
    }
    if ((out = fopen(outputFile, "wb")) == NULL) {
        printf("Error: Cannot open output file!\n");
        exit(1);
    }

    // Read input file and insert watermark
    fread(message, sizeof(char), MAX_MESSAGE_LENGTH, in);
    strncpy(message+strlen(message), watermark, strlen(watermark));
    fwrite(message, sizeof(char), strlen(message), out);

    // Close input and output files
    fclose(in);
    fclose(out);
}

/* Function to extract a watermark message from a binary file */
void extractWatermark(char* inputFile) {
    FILE *in;
    char message[MAX_MESSAGE_LENGTH], watermark[MAX_MESSAGE_LENGTH];

    // Open input file
    if ((in = fopen(inputFile, "rb")) == NULL) {
        printf("Error: Cannot open input file!\n");
        exit(1);
    }

    // Read input file and extract watermark
    fread(message, sizeof(char), MAX_MESSAGE_LENGTH, in);
    strncpy(watermark, message+strlen(message)-strlen("WATERMARK"), strlen("WATERMARK"));

    // Print extracted watermark
    printf("Extracted Watermark: %s\n", watermark);

    // Close input file
    fclose(in);
}

int main() {
    char inputFile[] = "input_file.bin";
    char outputFile[] = "output_file.bin";
    char watermark[] = "WATERMARK";

    // Insert watermark into input file
    insertWatermark(inputFile, outputFile, watermark);

    // Extract watermark from output file
    extractWatermark(outputFile);

    return 0;
}