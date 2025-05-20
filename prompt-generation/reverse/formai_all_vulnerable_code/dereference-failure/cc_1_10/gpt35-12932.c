//FormAI DATASET v1.0 Category: QR code generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

/* Function to generate QR code */

static void generate_qrcode(const char *text, const char *outfile, QRcode *qrcode, int size, int margin)
{
    FILE *fp;
    int i, j;
    unsigned char *row, *p;

    if ((fp = fopen(outfile, "wb")) != NULL) {
        row = (unsigned char*)calloc(qrcode->width, sizeof(unsigned char));
        p = qrcode->data;
        for (i = 0; i < qrcode->width; ++i) {
            for (j = 0; j < qrcode->width; ++j) {
                row[j] = (*p & 1) ? 0 : 255;
                p++;
            }
            for (j = 0; j < size; ++j) {
                fwrite(row, sizeof(unsigned char), qrcode->width, fp);
            }
        }
        memset(row, 255, qrcode->width*size);
        for (i = 0; i < margin*size; ++i) {
            fwrite(row, sizeof(unsigned char), qrcode->width*size, fp);
        }
        free(row);
        fclose(fp);
    }
}

int main(int argc, char **argv)
{
    QRcode *qrcode;
    int margin, size;
    char text[256];
    char outfile[256];

    /* Get data from user */
    printf("Enter Data: ");
    scanf("%s", text);

    printf("Enter File Name: ");
    scanf("%s", outfile);

    printf("Enter the QR size: ");
    scanf("%d", &size);

    printf("Enter the QR margin: ");
    scanf("%d", &margin);

    /* Generate QR code */
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode != NULL) {
        generate_qrcode(text, outfile, qrcode, size, margin);
        QRcode_free(qrcode);
    } else {
        printf("Failed to generate QR code.\n");
        exit(EXIT_FAILURE);
    }
    printf("QR code generated! \n");

    return 0;
}