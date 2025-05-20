//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generate_qr_code(const char *input_text) {
    QRcode *qrcode;
    unsigned char *qrcode_image;
    int width, height;

    /* Generate QR code */
    qrcode = QRcode_encodeString(input_text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        fprintf(stderr, "Error generating QR code for \"%s\"\n", input_text);
        exit(EXIT_FAILURE);
    }

    /* Set dimensions for a simple terminal representation */
    width = qrcode->width;
    height = width;
    int i, j;

    /* Output the QR code */
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            /* Check if the module is set */
            if (qrcode->data[i * width + j] & 1) {
                printf("██"); // Print as block for full modules
            } else {
                printf("  "); // Print empty space for un-set modules
            }
        }
        printf("\n"); // Newline after each row
    }

    /* Clean up */
    QRcode_free(qrcode);
}

void print_instructions() {
    printf("Thank you for using QR Code Generator! 🎉\n");
    printf("This program generates a QR code from your input text.\n");
    printf("Please enter the text you would like to encode (up to 255 characters):\n");
}

int main() {
    char input_text[256]; // Buffer for user input

    // Print welcome message and instructions
    print_instructions();

    // Get input from user
    if (fgets(input_text, sizeof(input_text), stdin) != NULL) {
        // Remove newline character if present
        input_text[strcspn(input_text, "\n")] = '\0';
        
        // Note: Ensure to handle empty input gracefully
        if (strlen(input_text) == 0) {
            fprintf(stderr, "Input cannot be empty.\n");
            return EXIT_FAILURE;
        }

        // Generate and show the QR code
        printf("\nGenerating QR Code for \"%s\":\n", input_text);
        generate_qr_code(input_text);
    } else {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    printf("\nThank you for using the QR Code Generator! Enjoy your QR code! 🌟\n");
    return EXIT_SUCCESS;
}