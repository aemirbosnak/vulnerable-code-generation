//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

void generate_qr_code(const char *data) {
    QRcode *qrcode;
    unsigned char *p;
    int size, version;

    // Create the QR code
    qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Error generating QR code\n");
        return;
    }

    // Get the version information for sizing
    version = qrcode->version;
    size = qrcode->width; // width = height for QR code

    // Print QR code
    for (int y = 0; y < size; y++) {
        p = &qrcode->data[y * size]; // pointer to row
        for (int x = 0; x < size; x++) {
            if (p[x] & 1) // dark module
                printf("████"); // use block character for dark modules
            else // light module
                printf("  "); // spaces for light modules
        }
        printf("\n");
    }

    // Cleanup
    QRcode_free(qrcode);
}

void display_menu() {
    printf("=================================\n");
    printf("       QR Code Generator        \n");
    printf("=================================\n");
    printf("Enter text to generate QR code:\n");
    printf("(Type 'exit' to quit)\n");
}

int main() {
    char input[256];

    while (1) {
        display_menu();
        printf("Input: ");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline from input
        input[strcspn(input, "\n")] = 0; 

        if (strcmp(input, "exit") == 0) {
            break; // Exit the loop if the user types 'exit'
        }

        // Generate the QR code for the given input
        generate_qr_code(input);
        printf("\n");
    }

    printf("Thank you for using the QR code generator!\n");
    return 0;
}