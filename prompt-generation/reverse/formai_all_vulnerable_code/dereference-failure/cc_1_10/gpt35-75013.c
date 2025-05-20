//FormAI DATASET v1.0 Category: QR code reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QR_CODE_LENGTH 100

void readQRCode(char *qrCode);
bool verifyQRCode(char *qrCode);
void processData(char *qrCode);

int main() {
    printf("Welcome to the C QR code reader program!\n\n");
    printf("Please scan a QR code using your device's camera and paste the result here:\n");

    char qrCode[MAX_QR_CODE_LENGTH];
    readQRCode(qrCode);

    if (verifyQRCode(qrCode)) {
        printf("\nQR code verified successfully! Processing data...\n\n");
        processData(qrCode);
    } else {
        printf("\nInvalid QR code format. Please try again.\n");
    }

    return 0;
}

void readQRCode(char *qrCode) {
    fgets(qrCode, MAX_QR_CODE_LENGTH, stdin);

    // Remove newline character from end of input string
    size_t len = strlen(qrCode);
    if (qrCode[len - 1] == '\n') {
        qrCode[len - 1] = '\0';
    }
}

bool verifyQRCode(char *qrCode) {
    // Verify that QR code starts with "QR:"
    if (strncmp(qrCode, "QR:", 3) != 0) {
        return false;
    }

    // Verify that QR code contains only alphanumeric characters and underscores
    for (int i = 3; i < strlen(qrCode); i++) {
        if (!(isalnum(qrCode[i]) || qrCode[i] == '_')) {
            return false;
        }
    }

    return true;
}

void processData(char *qrCode) {
    // Strip "QR:" from beginning of QR code
    qrCode += 3;

    // Split QR code into key-value pairs
    char *token = strtok(qrCode, "_");
    while (token != NULL) {
        char *key = strtok(token, ":");
        char *value = strtok(NULL, ":");
        printf("%s: %s\n", key, value);

        token = strtok(NULL, "_");
    }
}