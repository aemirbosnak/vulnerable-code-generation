//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

void generate_qr_code(const char *text, int version, int level);
void print_qr_code(QRcode *qrcode);
void free_qr_code(QRcode *qrcode);
void recursive_qr_generation(const char *text, int version, int level);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text_to_encode>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *text = argv[1];
    recursive_qr_generation(text, 0, 1);
    return EXIT_SUCCESS;
}

void recursive_qr_generation(const char *text, int version, int level) {
    if (level > 10) return; // Limit the maximum levels of recursion

    printf("Generating QR Code for: %s at level %d\n", text, level);
    generate_qr_code(text, version, level);
    
    // Generate a new string for demonstration purposes
    char new_text[256];
    snprintf(new_text, sizeof(new_text), "%s - level %d", text, level);
    recursive_qr_generation(new_text, version, level + 1);
}

void generate_qr_code(const char *text, int version, int level) {
    QRcode *qrcode;
    int qr_version = version + 1; // Increase version on each call
    int error_correction_level = QR_ECLEVEL_L; // Low error correction level for simplicity

    qrcode = QRcode_encodeString(text, qr_version, error_correction_level, QR_MODE_8, 1);
    
    if (qrcode) {
        print_qr_code(qrcode);
        free_qr_code(qrcode);
    } else {
        fprintf(stderr, "Failed to generate QR Code for: %s\n", text);
    }
}

void print_qr_code(QRcode *qrcode) {
    int width = qrcode->width;
    for (int y = 0; y < width; y++) {
        for (int x = 0; x < width; x++) {
            putchar((qrcode->data[y * width + x] & 1) ? '#' : ' ');
        }
        putchar('\n');
    }
    printf("\n");
}

void free_qr_code(QRcode *qrcode) {
    QRcode_free(qrcode);
}