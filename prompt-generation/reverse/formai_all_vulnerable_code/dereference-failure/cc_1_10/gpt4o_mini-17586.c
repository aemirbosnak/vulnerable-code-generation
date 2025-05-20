//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

// Function to save the QR code as a PBM image
void save_qr_to_pbm(QRcode *qrcode, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: Unable to open file %s for writing\n", filename);
        return;
    }

    // Writing PBM header
    fprintf(fp, "P1\n%d %d\n", qrcode->width, qrcode->width);
    
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            // If the module is dark, write 1, otherwise write 0.
            fputc((qrcode->data[y * qrcode->width + x] & 1) ? '1' : '0', fp);
            fputc(' ', fp);
        }
        fputc('\n', fp);
    }

    fclose(fp);
    printf("QR Code saved to %s\n", filename);
}

// Main function to generate QR Code
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <text> <output_file>\n", argv[0]);
        return 1;
    }

    const char *input_text = argv[1];
    const char *output_file = argv[2];

    // Generate QR code
    QRcode *qrcode = QRcode_encodeString(input_text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        fprintf(stderr, "Error: Failed to generate QR Code\n");
        return 1;
    }

    // Save the QR code as a PBM file
    save_qr_to_pbm(qrcode, output_file);
    
    // Clean up
    QRcode_free(qrcode);
    return 0;
}