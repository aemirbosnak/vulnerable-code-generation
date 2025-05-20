//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>  // Include the QRencode header

void generateQRCode(const char* inputString, const char* outputFileName) {
    QRcode *qrcode;
    
    // Generate the QR code
    qrcode = QRcode_encodeString(inputString, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        fprintf(stderr, "Failed to create QR code.\n");
        exit(EXIT_FAILURE);
    }

    // PNG output
    FILE *fp = fopen(outputFileName, "wb");
    if (!fp) {
        fprintf(stderr, "Could not open file %s for writing.\n", outputFileName);
        QRcode_free(qrcode);
        exit(EXIT_FAILURE);
    }

    // Write PNG header
    fprintf(fp, "\x89PNG\r\n\x1a\n");
    fprintf(fp, "IHDR");
    fprintf(fp, "%c%c%c%c", (qrcode->width + 1) >> 24, (qrcode->width + 1) >> 16,
                            (qrcode->width + 1) >> 8, (qrcode->width + 1) & 0xff);
    fprintf(fp, "%c%c%c%c", (qrcode->width + 1) >> 24, (qrcode->width + 1) >> 16,
                            (qrcode->width + 1) >> 8, (qrcode->width + 1) & 0xff);
    fprintf(fp, "\x08\x02\x00\x00\x00");

    // Add more PNG structure to write QR code data as binary
    // For simplicity, we'll convert directly
    unsigned char *data = malloc(qrcode->width * qrcode->width);
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        QRcode_free(qrcode);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // Populate the data array with QR code pixels
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            data[y * qrcode->width + x] = (qrcode->data[y * qrcode->width + x] & 0x1) ? 0 : 255;
        }
    }

    // Example of writing data to PNG
    fwrite(data, 1, qrcode->width * qrcode->width, fp);

    // Clean up
    free(data);
    fclose(fp);
    QRcode_free(qrcode);
    printf("QR code generated successfully and saved to %s\n", outputFileName);
}

int main() {
    char inputString[256];
    char outputFileName[256];

    // User input for the QR code content
    printf("Enter text to encode in QR Code: ");
    fgets(inputString, sizeof(inputString), stdin);
    inputString[strcspn(inputString, "\n")] = 0;  // Remove the newline character

    // User input for the output filename
    printf("Enter output filename (with .png extension): ");
    fgets(outputFileName, sizeof(outputFileName), stdin);
    outputFileName[strcspn(outputFileName, "\n")] = 0;  // Remove the newline character

    // Generate the QR code
    generateQRCode(inputString, outputFileName);
    return 0;
}