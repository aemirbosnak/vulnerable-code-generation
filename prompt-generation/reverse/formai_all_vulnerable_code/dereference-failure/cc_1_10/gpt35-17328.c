//FormAI DATASET v1.0 Category: QR code generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Welcome message to the user
    printf("Welcome to the Cheerful QR Code Generator in C!\n");

    // Get user input for the information to encode in the QR code
    char info[100];
    printf("What would you like to encode in your QR code? (Max. 100 characters)\n");
    scanf("%s", info);

    // Generate the QR code using C QR Code library
    // First, we need to install the qrencode library: sudo apt-get install libqrencode-dev
    // Then, we can include it and start generating the QR code
    #include <qrencode.h>

    QRcode *qr = QRcode_encodeString(info, 0, QR_ECLEVEL_M, QR_MODE_8, 1);

    // Check if the QR code was generated successfully
    if (qr == NULL) {
        printf("Couldn't generate QR code!\n");
        return 1;
    }

    // Output the QR code to the console
    for (int i = 0; i < qr->width + 2; i++) {
        printf("*");
    }
    printf("\n");

    for (int i = 0; i < qr->width; i++) {
        printf("*");
        for (int j = 0; j < qr->width; j++) {
            if (qr->data[i * qr->width + j] & 1) {
                printf("  ");
            } else {
                printf("* ");
            }
        }
        printf("*\n");
    }

    for (int i = 0; i < qr->width + 2; i++) {
        printf("*");
    }
    printf("\n");

    // Free the memory used by the QR code
    QRcode_free(qr);

    // Goodbye message to the user
    printf("Your cheerful QR code has been generated successfully! Goodbye!\n");

    return 0;
}