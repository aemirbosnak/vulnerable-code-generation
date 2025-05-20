//FormAI DATASET v1.0 Category: QR code generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qrencode.h"

// Generates a QR code based on the provided string
int generateQRCode(char *string, int size, char* fileName) {
    QRcode *code = QRcode_encodeString(string, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // If the code is empty, return an error
    if(code == NULL) {
        printf("Error: No QR code generated.");
        return 1;
    }

    // Create a new output file with the provided file name
    FILE *fp = fopen(fileName, "wb");

    // If the file cannot be opened, return an error
    if(fp == NULL) {
        printf("Error: Failed to open output file.");
        return 1;
    }

    // Loop through each row of the QR code and print it to the output file
    for(int i = 0; i < code->width; i++) {
        for(int j = 0; j < code->width; j++) {
            fprintf(fp, "%c", (code->data[i * code->width + j] & 1) ? '1' : '0');
        }
        fprintf(fp, "\n");
    }

    // Close the output file and free the QR code memory
    fclose(fp);
    QRcode_free(code);

    // Return success
    return 0;
}

// The main function of the program
int main() {
    // Prompt the user for the input string
    printf("Enter a string to generate a QR code: ");
    char input[100];
    fgets(input, 100, stdin);

    // Replace the newline character with a null terminator
    input[strcspn(input, "\n")] = '\0';

    // Prompt the user for the size of the QR code
    printf("Enter the size of the QR code (1-10): ");
    int size;
    scanf("%d", &size);

    // Generate the QR code and output the result
    int result = generateQRCode(input, size, "output.txt");
    if(result == 0) {
        printf("QR code generated successfully.");
    }

    // Return success
    return 0;
}