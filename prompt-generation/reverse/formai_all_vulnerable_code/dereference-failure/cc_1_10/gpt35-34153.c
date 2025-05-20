//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Define maximum message length
#define MAX_MSG_LEN 100

// Define a secret key for the watermarking system
#define SECRET_KEY 42

// Function to embed watermark in message
void embedWatermark(char *message, int key) {
    int len = strlen(message);
    int i;
    for (i = 0; i < len; i++) {
        message[i] = message[i] ^ key;
    }
}

// Function to extract watermark from message
void extractWatermark(char *message, int key) {
    int len = strlen(message);
    int i;
    for (i = 0; i < len; i++) {
        message[i] = message[i] ^ key;
    }
}

int main() {
    char message[MAX_MSG_LEN];
    char inputFile[MAX_SIZE], outputFile[MAX_SIZE];
    char ch;
    int choice, i;

    // Get input message from user
    printf("Enter the message: ");
    fgets(message, MAX_MSG_LEN, stdin);

    // Embed the watermark in the message
    embedWatermark(message, SECRET_KEY);

    // Ask user for input and output files
    printf("Enter the name of the input file: ");
    fgets(inputFile, MAX_SIZE, stdin);

    printf("Enter the name of the output file: ");
    fgets(outputFile, MAX_SIZE, stdin);

    // Open the input file
    FILE *input = fopen(inputFile, "rb");

    // Create the output file
    FILE *output = fopen(outputFile, "wb");

    // Check if files were opened successfully
    if (input == NULL || output == NULL) {
        printf("Error opening files!");
        exit(1);
    }

    // Read data from input file and write to output file
    while ((ch = fgetc(input)) != EOF) {
        // Embed watermark in the current byte
        ch = ch ^ SECRET_KEY;
        fputc(ch, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);

    // Extract the watermark from the message
    extractWatermark(message, SECRET_KEY);

    // Display the original message and the watermarked message
    printf("Original message: %s", message);
    printf("Watermarked message: %s", message);

    return 0;
}