//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generate_qr_code(const char *text) {
    QRcode *qrcode;
    unsigned char *png_data;
    int size;
    
    // Create the QR code
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to generate the QR Code\n");
        return;
    }

    size = qrcode->width;
    int png_size = size * size + 12; // Simple size calculation for png
    png_data = (unsigned char *)malloc(png_size);
    if (png_data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        QRcode_free(qrcode);
        return;
    }

    // Write PNG header
    snprintf((char *)png_data, png_size, "P6\n%d %d\n255\n", size, size);
    int offset = strlen((char *)png_data);

    // Write pixel data
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (qrcode->data[y * size + x] & 0x1) {
                // Black pixel
                png_data[offset++] = 0;
                png_data[offset++] = 0;
                png_data[offset++] = 0;
            } else {
                // White pixel
                png_data[offset++] = 255;
                png_data[offset++] = 255;
                png_data[offset++] = 255;
            }
        }
    }

    // Save to file
    FILE *fp = fopen("qrcode.png", "wb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file for writing\n");
        free(png_data);
        QRcode_free(qrcode);
        return;
    }

    fwrite(png_data, 1, png_size, fp);
    fclose(fp);
    printf("QR Code saved to qrcode.png\n");

    // Cleanup
    free(png_data);
    QRcode_free(qrcode);
}

int main() {
    char input[256];

    printf("Enter text to generate QR Code: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove the newline character
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        generate_qr_code(input);
    } else {
        fprintf(stderr, "Failed to read input\n");
        return 1;
    }

    return 0;
}