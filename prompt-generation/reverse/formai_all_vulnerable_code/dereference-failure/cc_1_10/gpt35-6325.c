//FormAI DATASET v1.0 Category: QR code generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void print_qr(char* message, int qrcode_version) {

    printf("Generating QR Code for: %s\n", message);

    QRcode* qrcode = QRcode_encodeString(message, 0, QR_ECLEVEL_Q, qrcode_version, 1);

    if (!qrcode) {
        printf("Error while generating QR Code.\n");
        return;
    }

    printf("\nQR Code (Version %d):\n\n", qrcode_version);

    for (int i = 0; i < qrcode->width; i++) {
        for (int j = 0; j < qrcode->width; j++) {
            if (qrcode->data[i * qrcode->width + j] & 1) {
                printf("  ");
            } else {
                printf("##");
            }
        }
        printf("\n");
    }

    printf("\n");

    QRcode_free(qrcode);
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("Usage: qrgen <message> [<version>]\n");
        return 1;
    }

    char* message = argv[1];
    int qrcode_version = 1;

    if (argc >= 3) {
        qrcode_version = atoi(argv[2]);
    }

    if (qrcode_version < 1 || qrcode_version > 40) {
        printf("Error: Invalid QR code version specified. Valid range: 1 to 40 inclusive.\n");
        return 1;
    }

    print_qr(message, qrcode_version);

    return 0;
}