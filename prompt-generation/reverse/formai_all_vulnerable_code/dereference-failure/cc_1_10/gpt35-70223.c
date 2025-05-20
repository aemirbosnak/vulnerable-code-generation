//FormAI DATASET v1.0 Category: QR code generator ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

// This function generates a QR code in C using the qrencode library
bool generateQRCode(char* data, char* filename) {
    QRcode *qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_H, QR_MODE_8, 1);

    if(qrcode == NULL){
        return false;
    }

    // Open the file for writing
    FILE* fp = fopen(filename, "wb");

    // Write the QR code to the file
    for(unsigned int i = 0; i < qrcode->width; i++) {
        for(unsigned int j = 0; j < qrcode->width; j++) {
            if(qrcode->data[i*qrcode->width + j] & 1) {
                fputc('1', fp);
            } else {
                fputc('0', fp);
            }
        }
        fputc('\n', fp);
    }

    // Close the file
    fclose(fp);

    // Free the QR code data
    QRcode_free(qrcode);

    return true;
}

// Main function to generate the QR code
int main() {
    // The data to be encoded in the QR code
    char data[] = "Hello, world! This is my QR code.";

    // The filename for the QR code image
    char filename[] = "my_qrcode.txt";

    // Generate the QR code and check if it was successful
    if(!generateQRCode(data, filename)) {
        printf("Failed to generate QR code.\n");
        return EXIT_FAILURE;
    }

    printf("QR code generated successfully.\n");

    return EXIT_SUCCESS;
}