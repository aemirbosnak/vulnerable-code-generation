//FormAI DATASET v1.0 Category: QR code generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [QRCode Content] [Output File]\n", argv[0]);
        return 1;
    }

    char *content = argv[1];
    char *filename = argv[2];

    // Calculate QRCode version and module size
    QRcode *qrcode;
    qrcode = QRcode_encodeString(content, 0, QR_ECLEVEL_H, QR_MODE_8, 1);
    if (qrcode == NULL) {
        printf("Error: Failed to generate QRCode\n");
        return 1;
    }

    int version = qrcode->version;
    int size = qrcode->width;

    // Open output file
    FILE *out;
    out = fopen(filename, "w");
    if (out == NULL) {
        printf("Error: Failed to open output file\n");
        return 1;
    }

    // Write QRCode image data to file
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (qrcode->data[i * size + j] & 1) {
                fwrite("#", 1, 1, out);
            } else {
                fwrite(" ", 1, 1, out);
            }
        }
        fwrite("\n", 1, 1, out);
    }

    // Close output file and free memory
    fclose(out);
    QRcode_free(qrcode);

    printf("QRCode generated successfully!\n");
    printf("Version: %d\n", version);
    printf("Size: %d x %d\n", size, size);

    return 0;
}