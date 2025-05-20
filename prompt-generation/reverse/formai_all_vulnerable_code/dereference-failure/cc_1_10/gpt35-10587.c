//FormAI DATASET v1.0 Category: QR code generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

typedef struct qrCode {
    int version;
    int size;
    unsigned char *data;
} qrCode;

qrCode* generateQRCode(char* text) {
    QRcode *qr = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    
    qrCode *code = (qrCode*) malloc(sizeof(qrCode));
    code->version = qr->version;
    code->size = qr->width;
    code->data = qr->data;
    
    return code;
}

void printQRCode(qrCode* code) {
    printf("QR Code (Version %d, Size %d):\n", code->version, code->size);
    int i, j;
    for (i = 0; i < code->size; i++) {
        for (j = 0; j < code->size; j++) {
            if (*(code->data + i * code->size + j) & 1) {
                printf("##");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void saveQRCode(qrCode* code, char* filename) {
    FILE *fp = fopen(filename, "wb");
    int i, j;
    for (i = 0; i < code->size; i++) {
        for (j = 0; j < code->size; j++) {
            if (*(code->data + i * code->size + j) & 1) {
                fprintf(fp, "##");
            } else {
                fprintf(fp, "  ");
            }
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main() {
    char* text = "Hello, world!";
    qrCode* code = generateQRCode(text);
    printQRCode(code);
    saveQRCode(code, "qrcode.txt");
    free(code->data);
    free(code);
    return 0;
}