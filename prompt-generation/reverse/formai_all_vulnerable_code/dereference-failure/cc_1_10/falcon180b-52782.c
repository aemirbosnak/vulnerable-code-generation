//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

typedef struct {
    int x;
    int y;
    int size;
    char data[MAX_SIZE];
} QRCode;

void readQRCode(char *filename, QRCode *qrcode) {
    FILE *fp;
    int i, j, k, x, y, size;
    char ch;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fscanf(fp, "%d %d %d", &x, &y, &size);
    qrcode->x = x;
    qrcode->y = y;
    qrcode->size = size;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            fscanf(fp, "%c", &ch);
            if (ch == '1') {
                qrcode->data[k] = 1;
            } else {
                qrcode->data[k] = 0;
            }
            k++;
        }
    }
    fclose(fp);
}

void printQRCode(QRCode qrcode) {
    int i, j, k;
    for (i = 0; i < qrcode.size; i++) {
        for (j = 0; j < qrcode.size; j++) {
            if (qrcode.data[k] == 1) {
                printf("X ");
            } else {
                printf("  ");
            }
            k++;
        }
        printf("\n");
    }
}

int main() {
    QRCode qrcode;
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);
    readQRCode(filename, &qrcode);
    printf("QR Code:\n");
    printQRCode(qrcode);
    return 0;
}