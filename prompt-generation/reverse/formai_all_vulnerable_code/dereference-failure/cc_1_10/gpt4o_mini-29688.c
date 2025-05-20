//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// QR Code library includes
#include <qrencode.h>

#define VERSION 1
#define LEVEL QR_ECLEVEL_L
#define SIZE 4
#define MARGIN 4

void generate_qr_code(const char* text, const char* filename) {
    QRcode* qrcode = QRcode_encodeString(text, VERSION, LEVEL, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to encode QR Code\n");
        return;
    }

    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file for writing\n");
        QRcode_free(qrcode);
        return;
    }

    // Create a simple BMP file header
    unsigned int width = qrcode->width;
    unsigned int size = width * width;
    unsigned char* bmp = (unsigned char*)malloc(size * 3 + sizeof(unsigned char) * 54);

    memset(bmp, 0, size * 3 + sizeof(unsigned char) * 54); // Clear the entire BMP buffer

    // BMP Header
    bmp[0] = 'B'; bmp[1] = 'M'; // Header
    *((int*)&bmp[2]) = size * 3 + 54; // Size of file
    *((int*)&bmp[6]) = 0;             // Reserved1
    *((int*)&bmp[10]) = 54;           // Offset to pixel data
    *((int*)&bmp[14]) = 40;           // Info header size
    *((int*)&bmp[18]) = width;        // Width
    *((int*)&bmp[22]) = width;        // Height
    bmp[26] = 1; bmp[27] = 0;         // Planes
    bmp[28] = 24;                      // Bits per pixel
    *((int*)&bmp[30]) = 0;             // Compression
    *((int*)&bmp[34]) = size * 3;     // Size of bitmap data
    *((int*)&bmp[38]) = 2835;          // Horizontal resolution
    *((int*)&bmp[42]) = 2835;          // Vertical resolution
    *((int*)&bmp[46]) = 0;             // Number of colors in palette
    *((int*)&bmp[50]) = 0;             // Important color count

    // Fill the pixels
    int offset = 54; // Pixel data starts after header (54 bytes)
    for (int y = 0; y < width; y++) {
        for (int x = 0; x < width; x++) {
            if (qrcode->data[y * width + x] & 1) {
                // Black pixel
                bmp[offset++] = 0;   // Blue
                bmp[offset++] = 0;   // Green
                bmp[offset++] = 0;   // Red
            } else {
                // White pixel
                bmp[offset++] = 255; // Blue
                bmp[offset++] = 255; // Green
                bmp[offset++] = 255; // Red
            }
        }
        // Add padding for BMP format (each row must be a multiple of 4 bytes)
        while (offset % 4 != 0) {
            bmp[offset++] = 0;
        }
    }

    // Write the BMP to file
    fwrite(bmp, size * 3 + sizeof(unsigned char) * 54, 1, fp);

    // Cleanup
    fclose(fp);
    QRcode_free(qrcode);
    free(bmp);
}

void read_input(char* input_buffer, size_t buffer_size) {
    printf("Enter text to encode in QR code: ");
    if (fgets(input_buffer, buffer_size, stdin) != NULL) {
        input_buffer[strcspn(input_buffer, "\n")] = 0; // Remove newline character
    }
}

int main() {
    const size_t BUFFER_SIZE = 256;
    char input_text[BUFFER_SIZE];
    char filename[] = "qrcode.bmp";

    // Read user input
    read_input(input_text, BUFFER_SIZE);

    // Generate QR Code
    generate_qr_code(input_text, filename);

    // Notify the user
    printf("QR Code generated and saved as '%s'\n", filename);
    return 0;
}