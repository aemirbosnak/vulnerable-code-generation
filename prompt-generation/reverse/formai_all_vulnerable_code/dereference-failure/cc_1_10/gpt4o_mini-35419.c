//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

void print_qr_to_console(QRcode *qrcode) {
    int i, j;
    for (i = 0; i < qrcode->width; i++) {
        for (j = 0; j < qrcode->width; j++) {
            if (qrcode->data[i * qrcode->width + j] & 1) {
                printf("██");  // Print a filled block
            } else {
                printf("  ");  // Print an empty space
            }
        }
        printf("\n");
    }
}

void generate_qr_code(const char *text) {
    QRcode *qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode) {
        print_qr_to_console(qrcode);
        QRcode_free(qrcode);
    } else {
        printf("Error generating QR Code\n");
    }
}

int main() {
    char *input_text = NULL;
    size_t len = 0;

    printf("Welcome to the QR Code Generator!\n");
    printf("Please enter the text you want to encode in QR Code: ");

    // Using getline to dynamically allocate memory for input
    if (getline(&input_text, &len, stdin) == -1) {
        perror("Failed to read input");
        free(input_text);
        return EXIT_FAILURE;
    }

    // Remove newline character from input if exists
    size_t input_length = strlen(input_text);
    if (input_length > 0 && input_text[input_length - 1] == '\n') {
        input_text[input_length - 1] = '\0';
    }

    printf("\nGenerating QR Code for: %s\n", input_text);
    generate_qr_code(input_text);

    free(input_text);
    return EXIT_SUCCESS;
}