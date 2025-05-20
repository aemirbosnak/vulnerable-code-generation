//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generate_qr_code(const char *data, const char *filename) {
    QRcode *qrcode;
    int size, i, j;
    
    // Generate QR code
    qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Error creating QR Code.\n");
        exit(1);
    }

    size = qrcode->width;
    
    // Open file to write the QR code in PGM format
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error opening file for writing.\n");
        QRcode_free(qrcode);
        exit(1);
    }

    // Write PGM header
    fprintf(fp, "P2\n%d %d\n255\n", size, size);

    // Iterate through each module in the QR code
    for (j = 0; j < size; j++) {
        for (i = 0; i < size; i++) {
            // Black module
            if (qrcode->data[j * size + i] & 1) {
                fprintf(fp, "0 "); // Black pixel
            } else {
                fprintf(fp, "255 "); // White pixel
            }
        }
        fprintf(fp, "\n");
    }

    // Cleanup
    fclose(fp);
    QRcode_free(qrcode);
    printf("QR code generated successfully! Saved as '%s'\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <data> <output_filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *data = argv[1];
    const char *filename = argv[2];

    generate_qr_code(data, filename);

    return EXIT_SUCCESS;
}