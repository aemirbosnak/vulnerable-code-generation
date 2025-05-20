//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generate_qr_code(const char *data, const char *filename) {
    QRcode *qrcode;
    FILE *fp;

    // Generate QR code
    qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to generate QR code\n");
        exit(EXIT_FAILURE);
    }

    // Open file to write the QR code
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file for writing\n");
        QRcode_free(qrcode);
        exit(EXIT_FAILURE);
    }

    // Write the QR code data to the file
    int width = qrcode->width;
    unsigned char *p;
    for (int y = 0; y < width; y++) {
        p = qrcode->data + y * width;
        for (int x = 0; x < width; x++) {
            fputc(p[x] & 1 ? '#' : ' ', fp);
        }
        fputc('\n', fp);
    }

    // Cleanup
    fclose(fp);
    QRcode_free(qrcode);
    printf("QR code generated successfully and saved to %s\n", filename);
}

void display_usage() {
    printf("Usage: qrgen <data> <output_filename>\n");
    printf("Example: qrgen 'Hello, World!' qr_code.txt\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage();
        return EXIT_FAILURE;
    }

    const char *data = argv[1];
    const char *output_filename = argv[2];

    // Check for buffer overflow vulnerability
    size_t data_len = strlen(data);
    if (data_len > 256) {
        fprintf(stderr, "Input data length exceeds 256 characters.\n");
        return EXIT_FAILURE;
    }

    // Generate the QR code with the provided data
    generate_qr_code(data, output_filename);
    return EXIT_SUCCESS;
}