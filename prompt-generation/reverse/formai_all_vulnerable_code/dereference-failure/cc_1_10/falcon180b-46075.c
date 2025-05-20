//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 5000
#define MAX_DATA 10000
#define MAX_ERROR 40

typedef struct {
    int size;
    int data[MAX_DATA];
} QRCode;

int getQRCode(QRCode *qrCode, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return -1;
    }

    int size = 0;
    int data = 0;
    while (fscanf(fp, "%d:%d", &size, &data)!= EOF) {
        qrCode->data[size] = data;
        size++;
    }

    qrCode->size = size;
    fclose(fp);

    return 0;
}

int isQRCode(QRCode *qrCode) {
    int i;
    for (i = 0; i < qrCode->size; i++) {
        if (qrCode->data[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void printQRCode(QRCode *qrCode) {
    int i;
    for (i = 0; i < qrCode->size; i++) {
        printf("%d ", qrCode->data[i]);
    }
    printf("\n");
}

int main() {
    QRCode qrCode;
    char filename[100];

    printf("Enter the filename of the QR code: ");
    scanf("%s", filename);

    if (getQRCode(&qrCode, filename) == -1) {
        return -1;
    }

    if (!isQRCode(&qrCode)) {
        printf("Error: Invalid QR code.\n");
        return -1;
    }

    printQRCode(&qrCode);

    return 0;
}