//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

void create_qr_code(const char *text) {
    QRcode *qrcode;
    int width = 0;
    
    // Generate the QR code
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_H, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to generate QR code!\n");
        return;
    }

    width = qrcode->width;
    printf("Generated QR Code for: %s\n", text);
    
    // Print the QR code as ASCII art
    for (int y = 0; y < width; y++) {
        for (int x = 0; x < width; x++) {
            putchar((qrcode->data[y * width + x] & 1) ? '#' : ' ');
        }
        putchar('\n');
    }

    QRcode_free(qrcode);
}

void print_instructions() {
    printf("Welcome to the QR Code Generator!\n");
    printf("Enter a piece of text to generate its QR code.\n");
    printf("When you're done, type 'exit' to quit.\n");
}

int main() {
    char input[256];

    print_instructions();

    while (1) {
        printf("Enter your text: ");
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Exiting the QR Code Generator. Goodbye!\n");
            break;
        }

        create_qr_code(input);
    }

    return 0;
}