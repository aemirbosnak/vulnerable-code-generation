//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

// Function to save QR code to a PPM file
void save_to_ppm(const char *filename, QRcode *qrcode) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        fprintf(stderr, "Could not open file for writing: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int size = qrcode->width;

    // PPM header
    fprintf(fp, "P3\n%d %d\n255\n", size, size);

    // Coloring the QR Code
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (qrcode->data[y * size + x] & 1) {
                fprintf(fp, "0 0 0 "); // Black color for modules
            } else {
                fprintf(fp, "255 255 255 "); // White color for background
            }
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <data> <output.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *data = argv[1];
    const char *filename = argv[2];

    // Generate a QR Code
    QRcode *qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        fprintf(stderr, "Could not generate QR Code for %s\n", data);
        return EXIT_FAILURE;
    }

    // Save QR code to PPM file
    save_to_ppm(filename, qrcode);

    // Clean up
    QRcode_free(qrcode);
    printf("QR Code generated and saved to %s successfully!\n", filename);
    return EXIT_SUCCESS;
}