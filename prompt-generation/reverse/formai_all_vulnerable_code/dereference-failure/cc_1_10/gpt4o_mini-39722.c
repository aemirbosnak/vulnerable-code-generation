//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generate_qr_code(const char *text) {
    QRcode *qrcode;

    // Generate QR code
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to generate QR Code.\n");
        return;
    }

    // Print the QR code to console as ASCII art
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            if (qrcode->data[y * qrcode->width + x] & 1) {
                printf("██");  // Black block for the QR code
            } else {
                printf("  ");  // White space for the QR code
            }
        }
        printf("\n");
    }

    // Free memory allocated by QRcode
    QRcode_free(qrcode);
}

int main() {
    char input[256];

    printf("Welcome to the QR Code Generator!\n");
    printf("Please enter the text you want to encode in a QR code: ");

    // Get user input
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove the newline character, if present
        size_t length = strlen(input);
        if (length > 0 && input[length - 1] == '\n') {
            input[length - 1] = '\0';
        }

        printf("Generating QR Code for: \"%s\"\n", input);
        generate_qr_code(input);
    } else {
        fprintf(stderr, "Error reading input.\n");
    }

    return 0;
}