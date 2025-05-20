//FormAI DATASET v1.0 Category: QR code reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_QR_CODE_SIZE 1000

typedef struct qr_code_data {
    int version;
    char data[MAX_QR_CODE_SIZE];
} QRCodeData;

QRCodeData* readQRCode(char* qrCodeString) {
    QRCodeData* qrCode = (QRCodeData*)malloc(sizeof(QRCodeData));
    qrCode->version = -1;
    memset(qrCode->data, '\0', MAX_QR_CODE_SIZE);

    // Parse version number from input string
    char* versionString = strtok(qrCodeString, ":");
    if (versionString == NULL) {
        printf("Error: Invalid QR code format\n");
        return qrCode;
    }
    qrCode->version = atoi(versionString);

    // Parse data from input string
    char* dataString = strtok(NULL, ":");
    if (dataString == NULL) {
        printf("Error: Invalid QR code format\n");
        return qrCode;
    }
    strncpy(qrCode->data, dataString, MAX_QR_CODE_SIZE);

    // Validate data length
    if (strlen(qrCode->data) > (UINT_MAX >> 1)) {
        printf("Error: Data length exceeds maximum value\n");
        qrCode->version = -1;
        memset(qrCode->data, '\0', MAX_QR_CODE_SIZE);
    }

    return qrCode;
}

int main() {
    char qrCodeString[MAX_QR_CODE_SIZE];

    printf("Enter QR code string: ");
    fgets(qrCodeString, MAX_QR_CODE_SIZE, stdin);

    QRCodeData* qrCode = readQRCode(qrCodeString);
    if (qrCode->version == -1) {
        printf("Invalid QR code input\n");
        return 0;
    }

    printf("QR code version: %d\n", qrCode->version);
    printf("QR code data: %s\n", qrCode->data);

    free(qrCode);

    return 0;
}