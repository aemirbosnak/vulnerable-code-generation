//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define QR_SIZE 21
#define STRING_LENGTH 256

void create_qr_image(const char *str) {
    QRcode *qrcode = QRcode_encodeString(str, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        fprintf(stderr, "Alas! The QR code could not be born.\n");
        return;
    }
    
    // Create and Print the QR code
    printf("O QR code doth arise:\n");
    for (int i = 0; i < qrcode->width; i++) {
        for (int j = 0; j < qrcode->width; j++) {
            if (qrcode->data[i * qrcode->width + j] & 1) {
                printf("■ "); // Black module
            } else {
                printf("  "); // White module
            }
        }
        printf("\n");
    }

    QRcode_free(qrcode);
}

int main() {
    char message[STRING_LENGTH];
    printf("Enter a message, sweet as Juliet's first words:\n");
    if (fgets(message, STRING_LENGTH, stdin)) {
        // Remove trailing newline character if there is one
        size_t len = strlen(message);
        if (len > 0 && message[len - 1] == '\n') {
            message[len - 1] = '\0';
        }
        
        printf("In this fond moment, we shall create a QR code for thee...\n");
        create_qr_image(message);
        printf("Thus, with a heart full of love, we conclude this digital ode.\n");
    } else {
        fprintf(stderr, "Fate hath made this a day of silence; no words shall echo...\n");
    }
    
    return 0;
}