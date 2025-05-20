//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: excited
#include <stdio.h>
#include <string.h>
#include <qrencode.h>

void print_qr_code(const char *text) {
    QRcode *qrcode;
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    
    if (qrcode == NULL) {
        fprintf(stderr, "Error: Could not generate QR Code!\n");
        return;
    }

    int size = qrcode->width;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            // Print black block for '1' and white space for '0'
            if (qrcode->data[y * size + x] & 0x1) {
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
    char input_text[256];
    
    printf("✨ Welcome to the QR Code Generator! ✨\n");
    printf("🚀 Generate your own QR Code by entering any text below:\n");

    // Taking user input
    printf("Input: ");
    fgets(input_text, sizeof(input_text), stdin);
    
    // Remove newline character if present
    size_t len = strlen(input_text);
    if (len > 0 && input_text[len - 1] == '\n') {
        input_text[len - 1] = '\0';
    }

    printf("🤖 Generating the QR Code for: \"%s\"\n", input_text);
    printf("🎉 Here is your QR Code:\n");

    // Generate and print QR Code
    print_qr_code(input_text);

    printf("\n✨ Thank you for using the QR Code Generator! ✨\n");
    return 0;
}