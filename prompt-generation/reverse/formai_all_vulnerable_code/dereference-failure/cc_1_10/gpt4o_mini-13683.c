//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generate_qr_code(const char *text, const char *filename) {
    QRcode *qr;
    
    // Generate QR Code
    qr = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qr == NULL) {
        fprintf(stderr, "Failed to generate QR Code\n");
        return;
    }

    // Open file for writing the QR Code as a PPM image
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Failed to open file for writing: %s\n", filename);
        QRcode_free(qr);
        return;
    }

    // Write PPM header
    fprintf(fp, "P6\n%d %d\n255\n", qr->width, qr->width);
    
    // Write pixel data
    for (int y = 0; y < qr->width; y++) {
        for (int x = 0; x < qr->width; x++) {
            fputc((qr->data[y * qr->width + x] & 1) ? 0 : 255, fp); // R
            fputc((qr->data[y * qr->width + x] & 1) ? 0 : 255, fp); // G
            fputc((qr->data[y * qr->width + x] & 1) ? 0 : 255, fp); // B
        }
    }

    // Clean up
    fclose(fp);
    QRcode_free(qr);
    printf("QR Code generated and saved to %s\n", filename);
}

int main() {
    char input[256];
    char filename[256];

    printf("Welcome to the QR Code Generator!\n");
    printf("Please enter the text to encode: ");
    
    // Read input from the user
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Failed to read input\n");
        return 1;
    }
    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    printf("Please enter the filename to save the QR Code (e.g., qr_code.ppm): ");
    
    // Read filename from the user
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        fprintf(stderr, "Failed to read filename\n");
        return 1;
    }
    // Remove newline character if present
    filename[strcspn(filename, "\n")] = 0;

    // Generate QR Code
    generate_qr_code(input, filename);

    return 0;
}