//FormAI DATASET v1.0 Category: QR code generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[])
{
    // Declare variables for QR code data
    char *data;
    int version, width;
    QRecLevel level = QR_ECLEVEL_L;
    QRcode *qr;

    // Get user input for QR code data
    printf("Enter data for QR code: ");
    fgets(data, sizeof(data), stdin);

    // Generate QR code with qrencode library
    if ((qr = QRcode_encodeString(data, 0, level, QR_MODE_8, 1)) == NULL) {
        printf("Error: Could not generate QR code.\n");
        return -1;
    }

    // Print QR code to console
    printf("\nQR code:\n\n");
    for (int i = 0; i < qr->width + 4; i++) {
        printf("0");
    }
    printf("\n");

    for (int y = 0; y < qr->width; y++) {
        printf("0");
        for (int x = 0; x < qr->width; x++) {
            if (qr->data[y * qr->width + x] & 1) {
                printf("  ");
            } else {
                printf("11");
            }
        }
        printf("0\n");
    }

    for (int i = 0; i < qr->width + 4; i++) {
        printf("0");
    }
    printf("\n\n");

    // Clean up memory
    QRcode_free(qr);
    return 0;
}