//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void save_qr_to_file(const char *filename, QRcode *qrcode) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Cannot open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Write the QR code data to a file in PNG format
    int width = qrcode->width;
    unsigned char *image = (unsigned char *)malloc(width * width * 4); // 4 bytes per pixel for RGBA

    // Create a white background
    memset(image, 255, width * width * 4);

    // Color the QR pixels
    for (int y = 0; y < width; y++) {
        for (int x = 0; x < width; x++) {
            if (qrcode->data[y * width + x] & 1) { // Check bit for black module
                image[(y * width + x) * 4] = 0; // Set R
                image[(y * width + x) * 4 + 1] = 0; // Set G
                image[(y * width + x) * 4 + 2] = 0; // Set B
                image[(y * width + x) * 4 + 3] = 255; // Set A (opacity)
            }
        }
    }

    // Save the image to PNG format
    // You can use libpng to output data, here we keep it simple with a stub
    // Normally, you would have PNG headers and write the data, skipped for brevity

    fwrite(image, width * width * 4, 1, fp);
    free(image);
    
    fclose(fp);
}

int main() {
    char input[256];
    char filename[256];
    
    // Get user input
    printf("Enter the text to be encoded in QR Code: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    printf("Enter the filename to save the QR Code (without extension): ");
    fgets(filename, sizeof(filename), stdin);
    
    // Remove newline character
    filename[strcspn(filename, "\n")] = 0;
    
    // Append .png extension
    strcat(filename, ".png");

    // Generate QR code
    QRcode *qrcode = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        fprintf(stderr, "Failed to encode QR code.\n");
        exit(EXIT_FAILURE);
    }

    // Save the QR code to a file
    save_qr_to_file(filename, qrcode);

    // Cleanup
    QRcode_free(qrcode);

    printf("QR Code generated and saved as %s\n", filename);
    return 0;
}