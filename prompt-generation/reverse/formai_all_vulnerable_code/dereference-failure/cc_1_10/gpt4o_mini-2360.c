//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

void generateQRCode(const char *text, const char *filename) {
    QRcode *qrcode;
    FILE *fp;
    
    // Generate the QR code
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to generate QR code\n");
        return;
    }

    // Open file to save the QR code image
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file %s for writing\n", filename);
        QRcode_free(qrcode);
        return;
    }

    // Write PGM header
    fprintf(fp, "P2\n");
    fprintf(fp, "%d %d\n", qrcode->width, qrcode->width);
    fprintf(fp, "255\n");

    // Output the QR code matrix
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            fputc((qrcode->data[y * qrcode->width + x] & 1) ? '0' : ' ', fp);
            fputc(' ', fp); // space between pixels
        }
        fputc('\n', fp); // new line after each row
    }

    fclose(fp);
    QRcode_free(qrcode);
    printf("QR code generated and saved to %s\n", filename);
}

int main() {
    char text[256];
    char filename[256];

    printf("Welcome to the QR Code Generator!\n");
    printf("Please enter the text you want to encode: ");
    fgets(text, sizeof(text), stdin);
    
    // Remove newline character from the input string
    text[strcspn(text, "\n")] = 0;

    printf("Now enter the filename to save your QR code image (example: qr_image.pgm): ");
    fgets(filename, sizeof(filename), stdin);
    
    // Remove newline character from the filename
    filename[strcspn(filename, "\n")] = 0;

    generateQRCode(text, filename);

    printf("Thank you for using the QR Code Generator! Have a great day!\n");
    return 0;
}