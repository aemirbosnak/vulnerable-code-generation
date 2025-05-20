//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QR_MAX_SIZE 4096

typedef struct {
    int size;
    int *data;
} QRCode;

QRCode* generateQRCode(char* input) {
    int size = strlen(input);
    int* data = (int*)malloc(QR_MAX_SIZE * sizeof(int));
    memset(data, 0, QR_MAX_SIZE * sizeof(int));

    int pos = 0;
    for (int i = 0; i < size; i++) {
        int c = input[i];
        if (c >= '0' && c <= '9') {
            data[pos++] = c - '0';
        } else if (c >= 'A' && c <= 'Z') {
            data[pos++] = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'z') {
            data[pos++] = c - 'a' + 36;
        }
    }

    QRCode* qrCode = (QRCode*)malloc(sizeof(QRCode));
    qrCode->size = size;
    qrCode->data = data;

    return qrCode;
}

void printQRCode(QRCode* qrCode) {
    int size = qrCode->size;
    int* data = qrCode->data;

    printf("QR Code:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (data[(i * size) + j] == 0) {
                printf("  ");
            } else {
                printf("##");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char input[100];
    printf("Enter input: ");
    scanf("%s", input);

    QRCode* qrCode = generateQRCode(input);
    printQRCode(qrCode);

    free(qrCode->data);
    free(qrCode);

    return 0;
}