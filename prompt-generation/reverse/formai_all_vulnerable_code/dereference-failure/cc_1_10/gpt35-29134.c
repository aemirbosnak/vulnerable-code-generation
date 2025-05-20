//FormAI DATASET v1.0 Category: QR code generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    if(argc != 2) { // Check if correct number of arguments have been passed
        printf("Usage: ./qr_gen <text to encode>\n");
        return 1;
    }

    QRcode *qrcode; // QRcode struct pointer to hold generated QR code
    const char *text = argv[1]; // Text to be encoded

    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1); // Generate QR code

    if(qrcode == NULL) { // Check if QR code generation failed
        printf("Unable to generate QR code. Please try again with different text.\n");
        return 1;
    }

    int dimension = qrcode->width; // Get dimensions of QR code

    for(int i = 0; i < dimension; i++) { // Print top border of QR code
        printf("█");
    }

    printf("\n");

    for(int i = 0; i < dimension; i++) { // Print each row of QR code
        printf("█");

        for(int j = 0; j < dimension; j++) { // Print either full block or empty block depending on QR code data
            if(qrcode->data[i*qrcode->width + j] & 1) {
                printf(" ");
            } else {
                printf("█");
            }
        }

        printf("█\n");
    }

    for(int i = 0; i < dimension; i++) { // Print bottom border of QR code
        printf("█");
    }

    printf("\n");

    QRcode_free(qrcode); // Free QR code struct
    return 0;
}