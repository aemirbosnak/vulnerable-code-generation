//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

// Function prototypes
void generate_qr_code(const char *data, const char *filename);
void save_qr_code_to_file(const char *filename, QRcode *qrcode);
void create_qr_code_image(QRcode *qrcode);
void cleanup(QRcode *qrcode);

int main() {
    char data[1024];
    char filename[256];

    printf("Enter the data to encode in QR code (max 1023 characters): ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0';  // Remove newline character

    printf("Enter a filename for the QR code image (without extension): ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';  // Remove newline character

    generate_qr_code(data, filename);

    return 0;
}

void generate_qr_code(const char *data, const char *filename) {
    QRcode *qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        fprintf(stderr, "Error generating QR code.\n");
        exit(EXIT_FAILURE);
    }
    
    // Save the QR code as a PPM file
    save_qr_code_to_file(filename, qrcode);

    // Cleanup allocated QR code
    cleanup(qrcode);

    printf("QR code generated and saved as %s.ppm\n", filename);
}

void save_qr_code_to_file(const char *filename, QRcode *qrcode) {
    FILE *fp;
    char filepath[300];

    snprintf(filepath, sizeof(filepath), "%s.ppm", filename);
    fp = fopen(filepath, "wb");
    if (!fp) {
        fprintf(stderr, "Could not open file %s for writing.\n", filepath);
        exit(EXIT_FAILURE);
    }

    // PPM header
    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n", qrcode->width, qrcode->width);
    fprintf(fp, "255\n");

    // Save QR code data to PPM file
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            if (qrcode->data[y * qrcode->width + x] & 1) {
                fprintf(fp, "0 0 0 ");  // Black pixel
            } else {
                fprintf(fp, "255 255 255 ");  // White pixel
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void cleanup(QRcode *qrcode) {
    QRcode_free(qrcode);
}