//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

void generate_qr_code(const char *text) {
    QRcode *qrcode;
    unsigned char *qrcode_data;
    int size, x, y;
  
    // Generate QR Code
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Error generating QR Code\n");
        exit(1);
    }

    size = qrcode->width;
    qrcode_data = qrcode->data;

    printf("Generated QR Code for: %s\n", text);
    printf("QR Code Size: %dx%d\n", size, size);
    printf("Displaying QR Code:\n\n");

    // Display QR Code in ASCII
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            if (qrcode_data[y * size + x] & 1) {
                printf("██");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    QRcode_free(qrcode);
}

int main() {
    char input[256];
    printf("Welcome to the QR Code Generator!\n");
    printf("Unleash the power of QR codes! Enter text or URL to convert: ");
  
    // Taking user input
    fgets(input, sizeof(input), stdin);
  
    // Remove the newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len-1] == '\n') {
        input[len-1] = '\0';
    }
  
    // Generate the QR Code
    generate_qr_code(input);

    printf("\nQR Code generated successfully! Scan it using any QR code reader.\n");
    return 0;
}