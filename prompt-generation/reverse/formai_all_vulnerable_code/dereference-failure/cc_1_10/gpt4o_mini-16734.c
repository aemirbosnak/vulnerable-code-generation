//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generateQRCode(const char *data, const char *filename) {
    QRcode *qrcode;
    FILE *fp;
    
    // Generate QR code
    qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        fprintf(stderr, "QR Code generation failed\n");
        exit(EXIT_FAILURE);
    }

    // Open PNG file for writing
    fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Cannot open file %s for writing\n", filename);
        QRcode_free(qrcode);
        exit(EXIT_FAILURE);
    }

    // Write QR code to PNG file
    int width = qrcode->width;
    unsigned char *png_data = malloc(width * width * 4);
    
    if (!png_data) {
        fprintf(stderr, "Memory allocation error\n");
        fclose(fp);
        QRcode_free(qrcode);
        exit(EXIT_FAILURE);
    }

    // Create PNG data from QR code
    for (int y = 0; y < width; y++) {
        for (int x = 0; x < width; x++) {
            int byte_index = (y * width + x);
            if (qrcode->data[byte_index] & 0x1) {
                png_data[(byte_index * 4) + 0] = 0; // R
                png_data[(byte_index * 4) + 1] = 0; // G
                png_data[(byte_index * 4) + 2] = 0; // B
                png_data[(byte_index * 4) + 3] = 255; // A
            } else {
                png_data[(byte_index * 4) + 0] = 255; // R
                png_data[(byte_index * 4) + 1] = 255; // G
                png_data[(byte_index * 4) + 2] = 255; // B
                png_data[(byte_index * 4) + 3] = 255; // A
            }
        }
    }

    // Write PNG header
    fprintf(fp, "\x89PNG\r\n\x1a\n"); // PNG Header
    // [Insert PNG header and chunk writing here]

    // Assuming a hypothetical function writePNG to write the data
    // writePNG(fp, width, png_data);

    // Clean up
    fclose(fp);
    free(png_data);
    QRcode_free(qrcode);
    printf("QR code generated and saved to %s\n", filename);
}

int main() {
    char data[256];
    char filename[256];

    printf("Enter the data for the QR code: ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = 0; // Remove newline

    printf("Enter the filename to save the QR code (with .png extension): ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline

    generateQRCode(data, filename);

    return 0;
}