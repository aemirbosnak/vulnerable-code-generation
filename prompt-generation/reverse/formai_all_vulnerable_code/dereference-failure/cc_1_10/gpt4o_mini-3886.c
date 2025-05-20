//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generate_qr_code(const char *data) {
    QRcode *qrcode;
    int size;
    
    // Generate QR code
    qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to generate QR code!\n");
        exit(1);
    }

    // Get the size of the QR code
    size = qrcode->width;

    // Print the QR code to the console
    printf("Here's your QR Code:\n");
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            // Module is set to 1 for black and 0 for white
            putchar((qrcode->data[y * size + x] & 0x01) ? '#' : ' ');
        }
        putchar('\n');
    }

    // Free the memory allocated for the QR code
    QRcode_free(qrcode);
}

int main() {
    char input[256];

    // Welcome message
    printf("************************************************\n");
    printf("*                                              *\n");
    printf("*          WELCOME TO THE QR CODE GENERATOR!  *\n");
    printf("*                                              *\n");
    printf("************************************************\n");
    printf("Enter the data to encode into a QR code: ");
    
    // Get user input
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input!\n");
        return 1;
    }

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0; 

    // Generate the QR Code
    generate_qr_code(input);

    // Goodbye message
    printf("************************************************\n");
    printf("*  Thank you for using the QR Code Generator! *\n");
    printf("*  Have a fantastic day ahead!                 *\n");
    printf("************************************************\n");

    return 0;
}