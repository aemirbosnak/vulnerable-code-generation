//FormAI DATASET v1.0 Category: QR code reader ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>

typedef struct {
    char* version;
    char* type;
    char* data;
} QRCode;

QRCode* readQRCode(char* code) {
    QRCode* qrcode = (QRCode*) malloc(sizeof(QRCode));
    char* token;
    token = strtok(code, ",");
    qrcode->version = strcpy((char*)malloc(sizeof(token)), token);
    token = strtok(NULL, ",");
    qrcode->type = strcpy((char*)malloc(sizeof(token)), token);
    token = strtok(NULL, ",");
    qrcode->data = strcpy((char*)malloc(sizeof(token)), token);
    return qrcode;
}

bool isValidQRCode(QRCode* qrcode) {
    if (strcmp(qrcode->version, "C") != 0) {
        return false;
    }
    if (strcmp(qrcode->type, "QR") != 0) {
        return false;
    }
    if (strlen(qrcode->data) < 50) {
        return false;
    }
    return true;
}

int main() {
    char code[256];
    printf("Scan QR Code:\n");
    scanf("%s", code);
    QRCode* qrcode = readQRCode(code);
    if (!isValidQRCode(qrcode)) {
        printf("Invalid QR Code.\n");
        return 0;
    }
    printf("QR Code read successfully.\n");
    printf("Version: %s\n", qrcode->version);
    printf("Type: %s\n", qrcode->type);
    printf("Data: %s\n", qrcode->data);
    free(qrcode->version);
    free(qrcode->type);
    free(qrcode->data);
    free(qrcode);
    return 0;
}