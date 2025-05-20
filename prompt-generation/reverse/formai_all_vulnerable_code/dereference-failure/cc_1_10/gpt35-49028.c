//FormAI DATASET v1.0 Category: QR code generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    QRcode *qrcode;
    unsigned char *qrcodeData;
    int outputFormat, imageSize, i, j;

    char *input = "Hello, world!";
    int version = 5; // QR code version
    int level = QR_ECLEVEL_L; // error correction level

    // Generate QR code
    qrcode = QRcode_encodeString(input, 0, level, QR_MODE_8, 1);
    if (qrcode == NULL) {
        printf("Error generating QR code.\n");
        return 1;
    }

    // Determine output format and calculate image size
    outputFormat = 'P';
    imageSize = qrcode->width * 3;

    // Allocate memory for image data
    qrcodeData = (unsigned char *) malloc(imageSize * qrcode->width);
    if (qrcodeData == NULL) {
        printf("Error allocating memory for QR code image data.\n");
        return 1;
    }

    // Iterate through QR code data and fill image data array
    for (i = 0; i < qrcode->width; i++) {
        for (j = 0; j < qrcode->width; j++) {
            unsigned char value = qrcode->data[i * qrcode->width + j];
            unsigned char *p = qrcodeData + (i * 3 * qrcode->width) + (j * 3);
            switch (value & 0x03) {
                case 0:
                    p[0] = 255;
                    p[1] = 255;
                    p[2] = 255;
                    break;
                case 1:
                    p[0] = 0;
                    p[1] = 0;
                    p[2] = 255;
                    break;
                case 2:
                    p[0] = 255;
                    p[1] = 0;
                    p[2] = 0;
                    break;
                default:
                    p[0] = 0;
                    p[1] = 255;
                    p[2] = 0;
                    break;
            }
        }
    }

    // Print QR code in PGM format
    printf("P2\n%d %d\n255\n", imageSize, imageSize);
    for (i = 0; i < imageSize; i++) {
        for (j = 0; j < imageSize; j++) {
            unsigned char value = qrcodeData[(i * imageSize) + j];
            printf("%d ", value);
        }
        printf("\n");
    }

    // Free memory
    QRcode_free(qrcode);
    free(qrcodeData);

    return 0;
}