//FormAI DATASET v1.0 Category: QR code reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// function to read QR code and validate its format
bool readQRCode(const char* code) {
    // QR code format validation rules
    if (strlen(code) != 13 || code[0] != 'C' || code[1] != '-' || code[6] != '-' || code[11] != '-') {
        return false;
    }
    for (int i = 2; i < 6; i++) {
        if (code[i] < '0' || code[i] > '9') {
            return false;
        }
    }
    for (int i = 7; i < 11; i++) {
        if (code[i] < 'A' || code[i] > 'Z') {
            return false;
        }
    }
    if (code[12] != 'X' && code[12] != 'Y' && code[12] != 'Z') {
        return false;
    }
    return true;
}

int main() {
    printf("Please scan QR code:\n");
    // assume QR code scanner is connected to serial port and reads code into buffer
    char* buffer = (char*)malloc(sizeof(char) * 14);
    scanf("%s", buffer);
    bool isValid = readQRCode(buffer);
    if (isValid) {
        printf("QR code is valid!\n");
        // parse data from QR code
        char* countryCode = (char*)malloc(sizeof(char) * 3);
        strncpy(countryCode, buffer + 2, 3);
        countryCode[3] = '\0';
        int productCode = atoi(buffer + 7);
        char productType = buffer[12];
        printf("Country Code: %s\n", countryCode);
        printf("Product Code: %d\n", productCode);
        printf("Product Type: %c\n", productType);
        free(countryCode);
    } else {
        printf("Invalid QR code format!\n");
    }
    free(buffer);
    return 0;
}