//FormAI DATASET v1.0 Category: QR code generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {

    QRcode *qr;             // Store QR code data
    unsigned char *data;    // Store data to be encoded
    int size;               // Size of QR code
 
    // Check if input is provided
    if (argc < 2) {
        printf("Usage: %s <data to encode> \n", argv[0]);
        return 1;
    }

    // Encode input data into QR code
    qr = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    if (qr == NULL) {
        printf("Error: Failed to generate QR code\n");
        return 1;
    }

    // Get size of QR code
    size = qr->width;

    // Allocate memory for storing QR code data
    data = (unsigned char*)malloc(sizeof(unsigned char) * size * size);

    if (data == NULL) {
        printf("Error: Failed to allocate memory\n");
        return 1;
    }

    // Copy QR code data into allocated memory
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(data + i * size + j) = *(qr->data + i * size + j) & 1;
        }
    }

    // Print QR code data
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (*(data + i * size + j) == 1) printf("■ ");
            else printf("□ ");
        }
        printf("\n");
    }

    // Free allocated memory
    QRcode_free(qr);
    free(data);

    return 0;
}