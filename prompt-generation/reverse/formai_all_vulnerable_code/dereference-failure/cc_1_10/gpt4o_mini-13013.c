//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

void generate_qr_code(const char *text, const char *filename) {
    QRcode *qrcode;
    unsigned char *image;
    FILE *file;
    
    // Encode the text into a QR code
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to generate QR code.\n");
        exit(1);
    }

    // Create an image buffer for PNG output
    int qrsize = qrcode->width;
    int width = qrsize * 10;  // Scale QR code for better visibility
    int height = qrsize * 10;
    
    image = (unsigned char *)malloc(width * height);
    
    // Draw QR code onto the image buffer
    for (int y = 0; y < qrsize; y++) {
        for (int x = 0; x < qrsize; x++) {
            if (qrcode->data[y * qrcode->width + x] & 1) {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        image[(y * 10 + i) * width + (x * 10 + j)] = 0;  // Black
                    }
                }
            } else {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        image[(y * 10 + i) * width + (x * 10 + j)] = 255;  // White
                    }
                }
            }
        }
    }

    // Save the image to a file
    file = fopen(filename, "wb");
    
    if (file == NULL) {
        fprintf(stderr, "Could not open file for writing.\n");
        QRcode_free(qrcode);
        free(image);
        exit(1);
    }

    // Write PNG header
    fprintf(file, "\x89PNG\r\n\x1A\n");
    // Omitted: Write PNG IHDR, IDAT (compressed QR code data), IEND chunks
    
    fwrite(image, sizeof(unsigned char), width * height, file);  // For simplicity
    fclose(file);

    // Free memory
    QRcode_free(qrcode);
    free(image);

    printf("QR code saved to %s\n", filename);
}

int main() {
    char input_text[256];
    char filename[256];

    printf("Enter the text to encode in QR code: ");
    fgets(input_text, sizeof(input_text), stdin);
    // Remove newline character
    input_text[strcspn(input_text, "\n")] = 0;

    printf("Enter the filename for the output image (e.g., qr.png): ");
    fgets(filename, sizeof(filename), stdin);
    // Remove newline character
    filename[strcspn(filename, "\n")] = 0;

    generate_qr_code(input_text, filename);
    
    return 0;
}