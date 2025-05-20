//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generateQrCode(const char *data) {
    QRcode *qr;
    unsigned char *qrData;
    int qrWidth, qrHeight;
    
    // Generate QR code
    qr = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qr == NULL) {
        fprintf(stderr, "Failed to generate QR code\n");
        return;
    }
    
    qrWidth = qr->width;
    qrHeight = qrWidth; // QR codes are square

    // Print the QR code to STDOUT
    for (int y = 0; y < qrWidth; y++) {
        for (int x = 0; x < qrWidth; x++) {
            qrData = &qr->data[y * qrWidth + x];
            if (*qrData & 1) {
                printf("██"); // Print black module
            } else {
                printf("  "); // Print white module
            }
        }
        printf("\n");
    }

    // Free the QR code structure
    QRcode_free(qr);
}

void displayInstructions() {
    printf("Simple QR Code Generator\n");
    printf("Enter the data you wish to encode: \n");
}

int main() {
    char input[256];

    displayInstructions();

    // Get user input
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove newline character at the end if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
    }

    // Generate and display the QR code
    generateQrCode(input);

    return 0;
}