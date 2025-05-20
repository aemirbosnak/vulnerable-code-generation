//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

void generateQRCode(const char *data) {
    QRcode *qrcode;
    
    // Generate the QR code from the provided data
    qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    
    // Check if QR code generation was successful
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to generate QR Code for the given data.\n");
        exit(EXIT_FAILURE);
    }

    // Display the QR code to the console
    int size = qrcode->width;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            putchar((qrcode->data[y * size + x] & 1) ? '#' : ' ');
        }
        putchar('\n');
    }
    
    // Free the QR code memory
    QRcode_free(qrcode);
}

void displayInstructions() {
    printf("Welcome to the QR Code Generator - A case for the keen mind!\n");
    printf("Simply type the information you wish to encode: \n");
}

int main() {
    char input[256];

    // Display introductory instructions
    displayInstructions();
    
    // Get input from the user
    printf("Enter the information you wish to encode: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Failed to read input.\n");
        return EXIT_FAILURE;
    }

    // Remove trailing newline character from input, if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Generate QR Code for the entered data
    generateQRCode(input);

    // Make a small deduction about the generated QR code
    printf("The QR Code above has been successfully generated!\n");
    printf("Keep it in mind, for all great cases begin with a single clue.\n");
    
    return EXIT_SUCCESS;
}