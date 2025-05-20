//FormAI DATASET v1.0 Category: QR code reader ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define QR Code
typedef struct QRCode {
    char *name;
    int size;
    char *data;
} QRCode;

// Function Prototype
char* readQRCode(FILE*);
void displayQRCode(QRCode*);
void freeQRCode(QRCode*);

int main() {
    FILE *file;
    char *fileName = "example_qr_code.txt";
    QRCode *qrCode = (QRCode*) malloc(sizeof(QRCode));

    // Open QR Code file
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", fileName);
        return 1;
    }

    // Read QR Code data
    qrCode->data = readQRCode(file);

    // Parse QR Code data
    char *token = strtok(qrCode->data, ";");
    qrCode->name = (char*) malloc(sizeof(char) * strlen(token));
    strcpy(qrCode->name, token);

    token = strtok(NULL, ";");
    qrCode->size = atoi(token);

    // Display QR Code
    displayQRCode(qrCode);

    // Free QR Code memory
    freeQRCode(qrCode);

    return 0;
}

// Function to read QR Code data from file
char* readQRCode(FILE *file) {
    char *qrCodeData = (char*) malloc(sizeof(char));

    char c;
    int index = 0;
    while ((c = fgetc(file)) != EOF) {
        if (isspace(c)) {
            continue;
        }

        qrCodeData[index++] = c;
        qrCodeData = (char*) realloc(qrCodeData, sizeof(char) * (index + 1));
    }

    qrCodeData[index] = '\0';
    return qrCodeData;
}

// Function to display QR Code data
void displayQRCode(QRCode *qrCode) {
    printf("QR Code Name: %s\n", qrCode->name);
    printf("QR Code Size: %d\n", qrCode->size);
    printf("QR Code Data: %s\n", qrCode->data);
}

// Function to free QR Code memory
void freeQRCode(QRCode *qrCode) {
    free(qrCode->name);
    free(qrCode->data);
    free(qrCode);
}