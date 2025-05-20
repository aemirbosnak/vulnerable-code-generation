//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define QR_VERSION 4
#define QR_ERROR_CORRECTION QR_ECLEVEL_L
#define QR_SIZE 25

void generate_qr_code(const char *data, const char *filename) {
    QRcode *qrcode;
    unsigned char *image;
    FILE *fp;

    // Generate QR code
    qrcode = QRcode_encodeString(data, QR_VERSION, QR_ERROR_CORRECTION, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to generate QR code for data: %s\n", data);
        return;
    }

    // Open file for writing
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        QRcode_free(qrcode);
        return;
    }

    // Create a simple PPM image representation of the QR code
    fprintf(fp, "P6\n%d %d\n255\n", qrcode->width, qrcode->width);
    image = (unsigned char *)malloc(qrcode->width * qrcode->width * 3);
    if (image == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        QRcode_free(qrcode);
        fclose(fp);
        return;
    }

    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            int index = y * qrcode->width + x;
            if (qrcode->data[index] & 1) {
                // Black part
                image[(y * qrcode->width + x) * 3 + 0] = 0;   // Red
                image[(y * qrcode->width + x) * 3 + 1] = 0;   // Green
                image[(y * qrcode->width + x) * 3 + 2] = 0;   // Blue
            } else {
                // White part
                image[(y * qrcode->width + x) * 3 + 0] = 255; // Red
                image[(y * qrcode->width + x) * 3 + 1] = 255; // Green
                image[(y * qrcode->width + x) * 3 + 2] = 255; // Blue
            }
        }
    }

    // Write the image data to file
    fwrite(image, 1, qrcode->width * qrcode->width * 3, fp);

    // Cleanup
    free(image);
    fclose(fp);
    QRcode_free(qrcode);

    printf("QR code generated successfully and saved to %s\n", filename);
}

void display_usage(const char *program_name) {
    printf("Usage: %s <data> [<output_filename>]\n", program_name);
    printf("Generates a QR code for the given data and saves it as a PPM image.\n");
    printf("If no output filename is provided, default is 'qrcode.ppm'.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *data = argv[1];
    const char *output_filename = (argc == 3) ? argv[2] : "qrcode.ppm";

    generate_qr_code(data, output_filename);

    return EXIT_SUCCESS;
}