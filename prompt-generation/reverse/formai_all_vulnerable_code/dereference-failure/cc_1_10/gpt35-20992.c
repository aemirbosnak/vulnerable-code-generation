//FormAI DATASET v1.0 Category: QR code reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_QR_CODE_SIZE 1024
#define MAX_QR_CODE_LENGTH 250

typedef struct {
    char data[MAX_QR_CODE_LENGTH];
    int size;
} QRCode;

bool isQRCode(char* message) {
    int length = strlen(message);
    if (length < 21) {
        return false;
    }
    if (message[0] != 'q' || message[1] != 'r' || message[2] != ':') {
        return false;
    }
    if (message[length - 1] != '\n') {
        return false;
    }
    for (int i = 3; i < length - 1; i++) {
        if (message[i] < '0' || (message[i] > '9' && message[i] < 'A') || message[i] > 'Z') {
            return false;
        }
    }
    return true;
}

QRCode* readQRCode() {
    QRCode* qrCode = malloc(sizeof(QRCode));
    qrCode->size = 0;

    char message[MAX_QR_CODE_SIZE];
    fgets(message, MAX_QR_CODE_SIZE, stdin);

    if (isQRCode(message)) {
        int length = strlen(message) - 2;
        strncpy(qrCode->data, message + 3, length - 3);
        qrCode->data[length - 3] = '\0';
        qrCode->size = length - 3;
    }

    return qrCode;
}

int main() {
    printf("Welcome to the QR Code Reader!\n");
    printf("Please scan your QR code:\n");

    QRCode* qrCode = readQRCode();

    if (qrCode->size > 0) {
        printf("QR Code detected: %s\n", qrCode->data);
    } else {
        printf("No valid QR Code found.\n");
    }

    free(qrCode);

    return 0;
}