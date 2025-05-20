//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

// Function to generate QR Code
void generateQRCode(const char *textToEncode) {
    QRcode *qrCode;
    int size, i, j;

    // Create the QRCode from the input text
    qrCode = QRcode_encodeString(textToEncode, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    if (!qrCode) {
        fprintf(stderr, "Failed to generate QR Code\n");
        return;
    }

    size = qrCode->width;

    // Print the QR Code in a simple ASCII representation
    printf("\nGenerated QR Code:\n");
    for (i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            // Each module is represented as a block
            putchar((qrCode->data[i * size + j] & 1) ? '#' : ' ');
        }
        putchar('\n'); // New line for the next row
    }

    QRcode_free(qrCode); // Free the memory allocated for the QR Code
}

// Main function to interact with users
int main() {
    char inputText[256];

    // Introduction to the program
    printf("Welcome to the QR Code Generator!\n");
    printf("Please enter the text you want to encode (max 255 characters):\n");

    // Read user input
    if (fgets(inputText, sizeof(inputText), stdin) != NULL) {
        size_t len = strlen(inputText);
        if (len > 0 && inputText[len - 1] == '\n') {
            inputText[len - 1] = '\0'; // Remove the newline character
        }

        // Generate the QR Code
        generateQRCode(inputText);
    } else {
        fprintf(stderr, "Input error\n");
        return 1; // Error occurred
    }

    // Thank you message
    printf("Thank you for using the QR Code Generator!\n");

    return 0; // Exit successfully
}