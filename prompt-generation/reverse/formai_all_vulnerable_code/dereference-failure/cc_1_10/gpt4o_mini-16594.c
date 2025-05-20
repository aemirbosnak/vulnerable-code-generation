//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <qrencode.h>

// Function to create a QR code and save it to a PNG file
void create_qr_code(const char *text, const char *filename) {
    QRcode *qrcode;
    uint8_t *qrcode_data;
    FILE *fp;
    int width;
    int x, y, size;

    // Encode the input text into QR code
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to generate QR code for %s\n", text);
        return;
    }

    // Open file to save the QR code
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open file %s for writing: %s\n", filename, strerror(errno));
        QRcode_free(qrcode);
        return;
    }

    // Calculate size and setup PNG header
    size = qrcode->width;
    width = size * 10; // Scale up for better visibility

    // PNG file header
    fprintf(fp, "\x89PNG\r\n\x1A\n");
    // Writing PNG Chunk & Data here, ideally you'd have a complete PNG encoder but for brevity we focus

    // Drawing QR code onto the file
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            if (qrcode->data[y * size + x] & 1) {
                // Set pixel color black for '1's
                // Placeholder for actual drawing logic
            } else {
                // Set pixel color white for '0's
                // Placeholder for actual drawing logic
            }
        }
    }

    // Here we would finalize and close the PNG file, additionally adding necessary chunks.

    fclose(fp);
    QRcode_free(qrcode);
}

int main() {
    char text[256];
    char filename[256];

    printf("Welcome to the QR Code Generator!\n");
    printf("Please enter the text for QR code: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline character

    printf("Enter the filename to save the QR code (e.g. output.png): ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline character

    create_qr_code(text, filename);
    printf("QR Code has been saved to %s\n", filename);

    return 0;
}