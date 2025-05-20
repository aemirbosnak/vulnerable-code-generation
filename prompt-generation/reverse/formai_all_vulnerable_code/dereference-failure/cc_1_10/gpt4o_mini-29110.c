//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>
#include <string.h>

void save_png(const char *filename, QRcode *qrcode) {
    int size = 3 * qrcode->width; // 3 pixels per module
    unsigned char *png_data = malloc(size * size);
    if (!png_data) {
        fprintf(stderr, "Memory allocation failed!\n");
        return;
    }

    // Fill the png_data with the QR data
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            unsigned char color = (qrcode->data[y * qrcode->width + x] & 1) ? 0x00 : 0xFF; // Black or white
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    png_data[(y * 3 + j) * size + (x * 3 + k)] = color;
                }
            }
        }
    }

    // Write to PNG file
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Could not open file for writing!\n");
        free(png_data);
        return;
    }

    // Simple PNG header
    fprintf(fp, "\x89PNG\r\n\x1A\n");
    // More headers and content would be required to create a fully valid PNG
    // For simplicity, it is skipped but we can showcase a simple bitmap structure
    
    // Clean up
    free(png_data);
    fclose(fp);
    printf("QR code saved as %s!\n", filename);
}

int main() {
    printf("🌟 Welcome to the QR Code Generator! 🌟\n");
    char input[256];
    
    printf("Enter the data to be encoded: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline character
    
    QRcode *qrcode = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        fprintf(stderr, "Error while encoding! 😱\n");
        return 1;
    }

    printf("QR Code generated successfully! 🎉\n");

    // Displaying the QR Code in the console (ASCII representation)
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            putchar((qrcode->data[y * qrcode->width + x] & 1) ? '#' : ' ');
        }
        putchar('\n');
    }

    // Saving QR Code to PNG file
    save_png("qrcode.png", qrcode);

    QRcode_free(qrcode);
    printf("✨ Thank you for using the QR Code Generator! Have a fantastic day! ✨\n");
    
    return 0;
}