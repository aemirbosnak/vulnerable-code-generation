//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

void printQR(const QRcode *qrcode) {
    int width = qrcode->width;

    for(int y = 0; y < width; y++) {
        for(int x = 0; x < width; x++) {
            // Each module can be either light or dark
            if(qrcode->data[y * width + x] & 1) {
                printf("██"); // Dark module
            } else {
                printf("  "); // Light module
            }
        }
        printf("\n");
    }
}

int main() {
    char input[256];
    printf("Welcome to the ASCII QR Code Generator!\n");
    printf("Please enter the text you want to encode (up to 255 characters):\n");
    
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove newline character if it's there
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        printf("Generating QR Code for: \"%s\"\n", input);

        // Encode the input string into a QR code
        QRcode *qrcode = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
        if (qrcode) {
            printQR(qrcode);
            QRcode_free(qrcode);
        } else {
            printf("Failed to generate QR code. Please try again!\n");
            return EXIT_FAILURE;
        }
    } else {
        printf("Failed to read input. Please try again!\n");
        return EXIT_FAILURE;
    }

    printf("Thanks for using the QR Code generator! Bye!\n");
    return EXIT_SUCCESS;
}