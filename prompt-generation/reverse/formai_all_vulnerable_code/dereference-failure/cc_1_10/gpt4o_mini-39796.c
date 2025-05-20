//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generateQRCode(const char *text) {
    QRcode *qrcode;
    
    // Generate QR code
    qrcode = QRcode_encodeString8bit(text, 0, QR_ECLEVEL_L);
    if (qrcode == NULL) {
        fprintf(stderr, "QR Code generation failed!\n");
        exit(EXIT_FAILURE);
    }

    // Create a PNG output file
    FILE *fp;
    char filename[100];
    snprintf(filename, sizeof(filename), "%s.png", text);
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file for writing.\n");
        QRcode_free(qrcode);
        exit(EXIT_FAILURE);
    }

    // Convert QR Code to PNG format
    unsigned char *png = (unsigned char *)malloc((qrcode->width + 2) * (qrcode->width + 2) * 3);
    if (png == NULL) {
        fprintf(stderr, "Memory allocation for PNG failed.\n");
        QRcode_free(qrcode);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // Fill PNG with white background
    memset(png, 255, (qrcode->width + 2) * (qrcode->width + 2) * 3);

    // Add QR code to PNG
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            if (qrcode->data[y * qrcode->width + x] & 1) {
                // Black pixel
                png[(y + 1) * (qrcode->width + 2) * 3 + (x + 1) * 3] = 0;
                png[(y + 1) * (qrcode->width + 2) * 3 + (x + 1) * 3 + 1] = 0;
                png[(y + 1) * (qrcode->width + 2) * 3 + (x + 1) * 3 + 2] = 0;
            }
        }
    }

    //PNG Header
    fprintf(fp, "\x89PNG\r\n\x1A\n");
    fwrite(png, (qrcode->width + 2) * (qrcode->width + 2) * 3, 1, fp);
    fclose(fp);
    QRcode_free(qrcode);
    free(png);

    printf("QR code generated! Check out the file: %s\n", filename);
}

int main() {
    char input[256];
    printf("Welcome to the QR Code Generator! 🚀\n");
    printf("Enter the data you want to encode: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character
    input[strcspn(input, "\n")] = 0;

    // Generate QR code from user input
    generateQRCode(input);
    
    return 0;
}