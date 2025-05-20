//FormAI DATASET v1.0 Category: QR code generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {

    char qr_string[256];
    int size, border_width;
    FILE *fp;

    if (argc < 2) {
        printf("Usage: %s <text to encode>\n", argv[0]);
        return 1;
    }

    strncpy(qr_string, argv[1], 255);

    /* Create QR code */
    QRcode *qr = QRcode_encodeString(qr_string, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    if (!qr) {
        fprintf(stderr, "Error: Failed to encode QR code.\n");
        return 1;
    }

    /* Output QR code to file */
    fp = fopen("qrcode.html", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: Failed to open file for writing.\n");
        return 1;
    }

    /* Set QR code size and border width */
    size = 10;
    border_width = 1;

    /* Write HTML containing the QR code */
    fprintf(fp, "<html>\n");
    fprintf(fp, "<head>\n");
    fprintf(fp, "<title>QR code</title>\n");
    fprintf(fp, "</head>\n");
    fprintf(fp, "<body>\n");
    fprintf(fp, "<svg viewBox=\"0 0 %d %d\" xmlns=\"http://www.w3.org/2000/svg\">\n", qr->width + border_width * 2, qr->width + border_width * 2);
    fprintf(fp, "<rect width=\"%d\" height=\"%d\" fill=\"#ffffff\"/>\n", qr->width + border_width * 2, qr->width + border_width * 2);
    for (int y = 0; y < qr->width; y++) {
        for (int x = 0; x < qr->width; x++) {
            if (qr->data[y * qr->width + x] & 1) {
                fprintf(fp, "<rect x=\"%d\" y=\"%d\" width=\"1\" height=\"1\" fill=\"#000000\"/>\n", x + border_width, y + border_width);
            }
        }
    }
    fprintf(fp, "</svg>\n");
    fprintf(fp, "</body>\n");
    fprintf(fp, "</html>\n");

    /* Clean up */
    fclose(fp);
    QRcode_free(qr);

    return 0;
}