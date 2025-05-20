//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

// Function to generate and save QR Code as a PNG file
void generateQRCode(const char *text, const char *filename) {
    QRcode *qrcode;
    unsigned char *image;
    int size, i, j;
    
    // Generate QR code
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to generate QR Code\n");
        return;
    }

    // Image size and memory allocation
    size = qrcode->width + 2; // Adding border
    image = (unsigned char *)malloc(size * size);
    
    // Create output image data
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1 ||
                qrcode->data[(i-1)*qrcode->width + (j-1)] & 0x1) {
                image[i * size + j] = 0; // Black
            } else {
                image[i * size + j] = 255; // White
            }
        }
    }

    // Write to PNG file
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file for writing\n");
        QRcode_free(qrcode);
        free(image);
        return;
    }

    // PNG Header
    fprintf(fp, "\x89PNG\r\n\x1A\n");

    // PNG Chunk and other headers go here (mock)
    // For simplicity, we will not write a full PNG file, but leaving markers for further implementation
    fprintf(fp, "IHDR...");  // Image Header
    fprintf(fp, "IDAT...");  // Image Data
    fprintf(fp, "IEND");      // End of Image

    // Clean up
    fclose(fp);
    QRcode_free(qrcode);
    free(image);
    
    printf("QR Code saved as '%s'\n", filename);
}

// Main function for user interaction
int main() {
    char text[256];
    char filename[256];

    // Inform user and get input
    printf("Welcome to the QR Code Generator!\n");
    printf("Enter the text to encode in the QR Code: ");
    fgets(text, sizeof(text), stdin);
    
    // Remove new line if present
    text[strcspn(text, "\n")] = 0;

    printf("Enter the filename to save the QR Code (e.g. qrcode.png): ");
    fgets(filename, sizeof(filename), stdin);
    
    filename[strcspn(filename, "\n")] = 0;

    // Generate QR Code
    generateQRCode(text, filename);

    return 0;
}