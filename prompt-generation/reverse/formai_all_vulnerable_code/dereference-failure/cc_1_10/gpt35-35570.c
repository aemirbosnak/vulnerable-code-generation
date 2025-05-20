//FormAI DATASET v1.0 Category: QR code generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define QR_CODE_FILE "qrcode.png"
#define OUT_FILE "output.txt"

int main() {
    QRcode *qr;
    FILE *fp;
    char input[100];

    printf("Enter data to encode: ");
    fgets(input, sizeof(input), stdin);
    strtok(input, "\n"); // remove newline character

    // Generate QR code
    qr = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Write QR code to file
    fp = fopen(QR_CODE_FILE, "wb");
    if (fp == NULL) {
        printf("Could not open file %s", QR_CODE_FILE);
        return 1;
    }
    fwrite(qr->data, qr->width * qr->width, 1, fp);
    fclose(fp);

    // Print QR code to console
    for (int i = 0; i < qr->width; i++) {
        for (int j = 0; j < qr->width; j++) {
            printf("%c", qr->data[i * qr->width + j] ? '*' : ' ');
        }
        printf("\n");
    }

    // Write encoded data to file
    fp = fopen(OUT_FILE, "w");
    if (fp == NULL) {
        printf("Could not open file %s", OUT_FILE);
        return 1;
    }
    fprintf(fp, "%s", input);
    fclose(fp);

    printf("QR code generated and data written to file!\n");

    return 0;
}