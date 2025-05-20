//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define QR_VERSION  5
#define QR_ECLEVEL  QR_ECLEVEL_L
#define QR_SIZE     25

void generate_qr_code(const char *text, const char *filename) {
    QRcode *qrcode = QRcode_encodeString(text, QR_VERSION, QR_ECLEVEL, QR_MODE_8, 1);
    if (!qrcode) {
        fprintf(stderr, "Error generating QR Code\n");
        return;
    }

    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error opening file for writing: %s\n", filename);
        QRcode_free(qrcode);
        return;
    }

    // Write the PPM file header
    fprintf(fp, "P3\n%d %d\n255\n", qrcode->width, qrcode->width);
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            int pixel = qrcode->data[y * qrcode->width + x] & 1;
            fprintf(fp, "%d %d %d ", pixel ? 0 : 255, pixel ? 0 : 255, pixel ? 0 : 255);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    QRcode_free(qrcode);
    printf("QR Code generated and saved to: %s\n", filename);
}

void display_usage(const char *program_name) {
    printf("Usage: %s <text-to-encode> <output-filename.ppm>\n", program_name);
    printf("Example: %s 'Hello, World!' qr_code.ppm\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *text = argv[1];
    const char *filename = argv[2];

    // Input validation for text length
    if (strlen(text) > 255) {
        fprintf(stderr, "Error: Input text exceeds the maximum length of 255 characters.\n");
        return EXIT_FAILURE;
    }

    generate_qr_code(text, filename);
    return EXIT_SUCCESS;
}