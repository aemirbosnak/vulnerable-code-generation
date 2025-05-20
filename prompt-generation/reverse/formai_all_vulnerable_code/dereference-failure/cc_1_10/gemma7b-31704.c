//Gemma-7B DATASET v1.0 Category: QR code reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_QR_SIZE 256

typedef struct QRCode {
    int width;
    int height;
    unsigned char **data;
} QRCode;

QRCode *qrcode_read(char *filename) {
    FILE *fp;
    QRCode *qr = malloc(sizeof(QRCode));

    if ((fp = fopen(filename, "r")) == NULL) {
        perror("Error opening file");
        exit(1);
    }

    qr->width = MAX_QR_SIZE;
    qr->height = MAX_QR_SIZE;
    qr->data = (unsigned char **)malloc(qr->height * sizeof(unsigned char *) + qr->width * sizeof(unsigned char));

    for (int i = 0; i < qr->height; i++) {
        qr->data[i] = (unsigned char *)malloc(qr->width * sizeof(unsigned char));
    }

    fscanf(fp, "%d %d", &qr->width, &qr->height);
    for (int i = 0; i < qr->height; i++) {
        for (int j = 0; j < qr->width; j++) {
            fscanf(fp, "%c", &qr->data[i][j]);
        }
    }

    fclose(fp);

    return qr;
}

int main() {
    QRCode *qr = qrcode_read("qrcode.txt");
    printf("QR code data:\n");
    for (int i = 0; i < qr->height; i++) {
        for (int j = 0; j < qr->width; j++) {
            printf("%c ", qr->data[i][j]);
        }
        printf("\n");
    }

    free(qr->data);
    free(qr);

    return 0;
}