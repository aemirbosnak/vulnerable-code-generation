//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define QR_SIZE 10  // Size of each QR module
#define QR_VERSION 1 // QR code version (1: 21x21 matrix)

void generate_and_save_qr(const char *text, const char *filename) {
    QRcode *qrcode;
    unsigned char *img;
    FILE *fp;
    
    // Generate QR code
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to generate QR code\n");
        return;
    }

    // Allocate memory for the image representation
    img = (unsigned char *)malloc(QR_SIZE * (qrcode->width + 2) * QR_SIZE * (qrcode->width + 2));
    if (img == NULL) {
        fprintf(stderr, "Memory allocation failed for image\n");
        QRcode_free(qrcode);
        return;
    }

    // Create a PGM file header and write it to the specified file
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file for writing\n");
        QRcode_free(qrcode);
        free(img);
        return;
    }
    
    fprintf(fp, "P5\n%d %d\n255\n", QR_SIZE * (qrcode->width + 2), QR_SIZE * (qrcode->width + 2));

    // Create QR code in PGM format
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            for (int dy = 0; dy < QR_SIZE; dy++) {
                for (int dx = 0; dx < QR_SIZE; dx++) {
                    img[((y * QR_SIZE + dy) * (qrcode->width * QR_SIZE)) + (x * QR_SIZE + dx)] = 
                        (qrcode->data[y * qrcode->width + x] & 0x01) ? 0 : 255;
                }
            }
        }
    }
    
    // Write the image to file
    fwrite(img, 1, QR_SIZE * (qrcode->width + 2) * QR_SIZE * (qrcode->width + 2), fp);
    
    // Close the file and free memory
    fclose(fp);
    free(img);
    QRcode_free(qrcode);
    printf("QR code generated and saved to %s\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <text> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    generate_and_save_qr(argv[1], argv[2]);
    
    return EXIT_SUCCESS;
}