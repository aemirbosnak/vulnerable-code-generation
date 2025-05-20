//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define QR_VERSION 1
#define QR_MARGIN 4

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <text>\n", program_name);
    fprintf(stderr, "Generates a QR code for the provided text.\n");
    exit(EXIT_FAILURE);
}

void generate_qr_code(const char *text) {
    QRcode *qrcode;

    // Generate QR code
    qrcode = QRcode_encodeString(text, QR_VERSION, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "QR Code generation failed!\n");
        exit(EXIT_FAILURE);
    }
    
    // Output the QR code
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            putchar(qrcode->data[y * qrcode->width + x] & 0x01 ? '#' : ' ');
        }
        putchar('\n');
    }

    QRcode_free(qrcode);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
    }

    // Validate the input text (you can refine this based on your needs)
    if (strlen(argv[1]) == 0) {
        fprintf(stderr, "Input text cannot be empty.\n");
        exit(EXIT_FAILURE);
    }

    printf("Generating QR Code for: %s\n", argv[1]);
    generate_qr_code(argv[1]);

    return EXIT_SUCCESS;
}