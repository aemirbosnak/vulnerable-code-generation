//FormAI DATASET v1.0 Category: QR code generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generateQRCode(const char *inputString, int pixelSize, const char *outputFile) {
    QRcode *qr = QRcode_encodeString(inputString, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qr != NULL) {
        int qr_size = qr->width;
        int pixel_padding = 2;
        int image_size = pixelSize * qr_size + 2 * pixel_padding;
        unsigned char *image_buffer = (unsigned char*)malloc(image_size * image_size * sizeof(unsigned char));
        memset(image_buffer, 255, image_size * image_size);
        unsigned char *image_data_ptr = image_buffer + pixel_padding * image_size + pixel_padding;
        for (int i = 0; i < qr_size; i++) {
            for (int j = 0; j < qr_size; j++) {
                *image_data_ptr = qr->data[i*qr_size+j] & 1;
                image_data_ptr++;
            }
            image_data_ptr += pixelSize * (image_size - qr_size);
            image_data_ptr += pixel_padding * 2;
        }
        QRcode_free(qr);
        FILE *fp = fopen(outputFile, "wb");
        if (fp == NULL) {
            fprintf(stderr, "Failed to open output file %s\n", outputFile);
        } else {
            fprintf(fp, "P1\n%d %d\n", image_size, image_size);
            for (int i = 0; i < image_size; i++) {
                for (int j = 0; j < image_size; j++) {
                    unsigned char pixel = image_buffer[i*image_size+j];
                    fprintf(fp, "%d", pixel);
                }
                fprintf(fp, "\n");
            }
            fclose(fp);
            printf("QR code saved to %s\n", outputFile);
        }
        free(image_buffer);
    }
}

int main() {
    char inputString[1024];
    printf("Enter text to encode in QR code: ");
    fgets(inputString, 1024, stdin);
    inputString[strcspn(inputString, "\r\n")] = 0;
    printf("Enter pixel size (1-10): ");
    int pixelSize;
    scanf("%d", &pixelSize);
    if (pixelSize < 1) {
        pixelSize = 1;
    } else if (pixelSize > 10) {
        pixelSize = 10;
    }
    char outputFile[1024];
    snprintf(outputFile, 1024, "qrcode_%d.pbm", (int)time(NULL));
    generateQRCode(inputString, pixelSize, outputFile);
    return 0;
}