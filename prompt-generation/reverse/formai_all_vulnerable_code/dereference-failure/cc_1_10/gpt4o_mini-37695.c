//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>
#include <string.h>

void display_usage(const char *prog_name) {
    printf("Utilization: %s <data>\n", prog_name);
    printf("   where <data> is the information to encode into the QR Code.\n");
}

void generate_qr_code(const char *data) {
    QRcode *qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    
    if (!qrcode) {
        fprintf(stderr, "Error: QR Code generation failed. Please ensure the input is valid.\n");
        return;
    }

    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            if (qrcode->data[y * qrcode->width + x] & 1) {
                printf("██"); // A block for black modules
            } else {
                printf("  "); // A space for white modules
            }
        }
        printf("\n");
    }

    QRcode_free(qrcode);
    printf("The QR Code has been generated for the data: \"%s\"\n", data);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_usage(argv[0]);
        return 1;
    }

    const char *data = argv[1];
    size_t data_length = strlen(data);

    if (data_length == 0) {
        fprintf(stderr, "Error: Data cannot be empty. Please provide valid data to encode.\n");
        return 1;
    }

    // Generating the QR Code for the provided data
    printf("Initiating the QR Code Generation Process...\n");
    generate_qr_code(data);
    printf("Process Completed. Thank you for using the QR Code Generator!\n");

    return 0;
}