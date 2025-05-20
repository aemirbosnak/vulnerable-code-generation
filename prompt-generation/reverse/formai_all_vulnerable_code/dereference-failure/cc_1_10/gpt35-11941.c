//FormAI DATASET v1.0 Category: QR code generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <qrencode.h>

void generateQRcode(char *data, int version, const char *outfile) {
    /* Initialize QRcode object to NULL */
    QRcode *qr = NULL;

    /* Create QRcode object from input data */
    qr = QRcode_encodeString(data, version, QR_ECLEVEL_H, QR_MODE_8, 1);

    /* Open output file for writing */
    FILE *fp = fopen(outfile, "wb");

    if (fp != NULL) {
        /* Write QRcode to output file */
        int i, j;
        for (i = 0; i < qr->width; i++) {
            for (j = 0; j < qr->width; j++) {
                if (qr->data[i * qr->width + j] & 1) {
                    fputc('1', fp);
                } else {
                    fputc('0', fp);
                }
            }
            fputc('\n', fp);
        }

        /* Close output file */
        fclose(fp);
    }

    /* Free QRcode object */
    QRcode_free(qr);
}

int main() {
    char data[1000];
    int version = 0;
    char outfile[100];

    /* Prompt user for input data */
    printf("Enter data to encode:\n");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0';

    /* Prompt user for version (1-40) */
    printf("Enter QRcode version (1-40):\n");
    scanf("%d", &version);

    /* Prompt user for output file name */
    printf("Enter output file name:\n");
    scanf("%s", outfile);

    /* Generate QRcode and write to output file */
    generateQRcode(data, version, outfile);

    return 0;
}