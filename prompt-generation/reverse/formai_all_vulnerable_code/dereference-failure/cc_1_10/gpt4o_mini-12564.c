//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

void generate_qr_code(const char *text, const char *filename) {
    QRcode *qr;
    FILE *fp;

    // Generate the QR Code
    qr = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qr == NULL) {
        fprintf(stderr, "Failed to generate QR Code!\n");
        exit(EXIT_FAILURE);
    }

    // Open the file to output the QR Code as a PNG
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file for writing: %s\n", filename);
        QRcode_free(qr);
        exit(EXIT_FAILURE);
    }

    // Write the PNG header
    fprintf(fp, "IHDR");
    // - PNG dimensions
    fwrite(&qr->width, 1, sizeof(qr->width), fp); // width
    fwrite(&qr->width, 1, sizeof(qr->width), fp); // height
    // - Color type and bit depth
    fputc(8, fp); // Bit depth
    fputc(2, fp); // Color type (RGB)
    // - Other attributes like compression, filter, interlace
    fputc(0, fp);
    fputc(0, fp);
    fputc(0, fp);

    // Write the actual QR data
    for (int y = 0; y < qr->width; y++) {
        for (int x = 0; x < qr->width; x++) {
            fputc((qr->data[y * qr->width + x] & 1) ? 0 : 255, fp); // white or black
            fputc((qr->data[y * qr->width + x] & 1) ? 0 : 255, fp);
            fputc((qr->data[y * qr->width + x] & 1) ? 0 : 255, fp);
        }
    }

    // Close the file
    fclose(fp);
    QRcode_free(qr);
    printf("QR Code generated successfully in file: %s\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <text_to_encode> <output_filename.png>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *text = argv[1];
    const char *filename = argv[2];

    printf("Generating QR Code for text: \"%s\"\n", text);
    generate_qr_code(text, filename);

    return EXIT_SUCCESS;
}