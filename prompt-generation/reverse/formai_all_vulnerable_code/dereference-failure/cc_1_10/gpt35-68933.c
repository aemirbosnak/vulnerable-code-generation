//FormAI DATASET v1.0 Category: QR code reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_QR_CODE_LENGTH 100

// Function to check if the given string can represent a QR code.
bool isQRCode(const char* text) {
    if(text == NULL) {
        return false;
    }
    int len = strlen(text);
    if(len < 2 || len > MAX_QR_CODE_LENGTH) {
        return false;
    }
    for(int i = 0; i < len; i++) {
        if(text[i] != '0' && text[i] != '1') {
            return false;
        }
    }
    return true;
}

// Function to read the QR code from the user.
char* getQRCode() {
    char* qrCode = NULL;
    size_t bufferLen = 0;
    printf("Enter the QR code: ");
    getline(&qrCode, &bufferLen, stdin);
    qrCode[strcspn(qrCode, "\n")] = '\0';
    if(!isQRCode(qrCode)) {
        free(qrCode);
        qrCode = NULL;
        printf("Invalid QR code!\n");
    }
    return qrCode;
}

// Function to decode the QR code.
char* decodeQRCode(const char* qrCode) {
    int len = strlen(qrCode);
    char* decodedText = malloc((len/8 + 1) * sizeof(char));
    decodedText[0] = '\0';
    for(int i = 0; i < len; i += 8) {
        int byte = 0;
        for(int j = 0; j < 8; j++) {
            byte = (byte << 1) | (qrCode[i+j] - '0');
        }
        sprintf(decodedText + strlen(decodedText), "%c", byte);
    }
    return decodedText;
}

int main() {
    printf("===== QR CODE READER =====\n");
    while(true) {
        char* qrCode = getQRCode();
        if(qrCode == NULL) {
            printf("Exiting program...\n");
            break;
        }
        char* decodedText = decodeQRCode(qrCode);
        printf("Decoded text: %s\n", decodedText);
        free(qrCode);
        free(decodedText);
    }
    return 0;
}