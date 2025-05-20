//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generate_qr_code(const char *data, const char *filename) {
    QRcode *qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        printf("Failed to generate QR code.\n");
        return;
    }

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Could not open file for writing: %s\n", filename);
        QRcode_free(qrcode);
        return;
    }

    // Generate PNG file header
    unsigned char png_header[8] = {
        0x89, 'P', 'N', 'G', '\r', '\n', 0x1A, '\n'
    };
    fwrite(png_header, 1, sizeof(png_header), fp);

    // Simple PNG creation (you may want to replace this with proper PNG encoding)
    unsigned char *png_data = malloc(qrcode->width * qrcode->width);
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            png_data[y * qrcode->width + x] = (qrcode->data[y * qrcode->width + x] & 1) ? 0 : 255;
        }
    }

    // Mock function to convert to PNG format (Placeholder)
    // You can use libraries like libpng to actually create a PNG.
    fwrite(png_data, 1, qrcode->width * qrcode->width, fp);
    
    free(png_data);
    fclose(fp);
    QRcode_free(qrcode);

    printf("QR Code generated and saved to %s\n", filename);
}

int main() {
    char data[256];
    char filename[256];

    printf("Enter the data to encode (e.g. URL): ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = 0;  // Remove newline

    printf("Enter filename to save QR code (without .png): ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;  // Remove newline
    strcat(filename, ".png");

    generate_qr_code(data, filename);

    return 0;
}