//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generate_qr_code(const char *text, const char *filename) {
    // Shock and awe begin!
    printf("Generating QR Code... Please hold on to your seats!\n");
    
    QRcode *qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    
    if (qrcode == NULL) {
        fprintf(stderr, "ERROR: Failed to generate QR code.\n");
        exit(EXIT_FAILURE);
    }
    
    printf("QR Code generated successfully! Writing to file: %s\n", filename);
    
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "ERROR: Could not open file %s for writing.\n", filename);
        QRcode_free(qrcode);
        exit(EXIT_FAILURE);
    }

    // Create the PBM format
    fprintf(file, "P1\n%d %d\n", qrcode->width, qrcode->width);
    
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            // Each module in the QR code gets a value in PBM format
            putc(qrcode->data[y * qrcode->width + x] & 1 ? '0' : '1', file);
        }
        putc('\n', file);
    }

    fclose(file);
    QRcode_free(qrcode);
    printf("QR Code saved to %s successfully! Enjoy scanning!\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <text_to_encode> <output_filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *text_to_encode = argv[1];
    const char *output_filename = argv[2];

    // Reporting the shocking details of the code
    printf("Text to encode: %s\n", text_to_encode);
    printf("Output filename: %s\n", output_filename);
    
    generate_qr_code(text_to_encode, output_filename);

    printf("All done! You can scan your QR Code now!\n");
    return EXIT_SUCCESS;
}