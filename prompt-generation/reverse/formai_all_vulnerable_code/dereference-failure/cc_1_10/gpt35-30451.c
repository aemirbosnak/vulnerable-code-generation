//FormAI DATASET v1.0 Category: QR code generator ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CODE_LEN 64

const char *ENCODING_TABLE[] = {
    "0001101", "0011001", "0010011", "0111101", "0100011",
    "0110001", "0101111", "0111011", "0110111", "0001011"
};

void printQRCode(char* qrCode) {
    printf("%s\n", qrCode);
}

bool validateString(const char* str, size_t len) {
    for (int i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

void generateQRCode(const char* code) {
    char qrCode[MAX_CODE_LEN];
    memset(qrCode, 0, MAX_CODE_LEN);

    size_t len = strlen(code);

    if (len < 12 || len > 16 || !validateString(code, len)) {
        printf("Invalid code length or type\n");
        return;
    }

    // Add start and end markers
    strcat(qrCode, "101");

    // Add 6-bit Type indicator
    char typeIndicator[7];
    strncpy(typeIndicator, code, 6);
    typeIndicator[6] = '\0';
    strcat(qrCode, ENCODING_TABLE[atoi(typeIndicator)]);
    strcat(qrCode, "01010");

    // Add variable-length data component
    int i;
    for (i = 6; i < len; i++) {
        char element[3];
        strncpy(element, &code[i], 2);
        element[2] = '\0';
        strcat(qrCode, ENCODING_TABLE[atoi(element)]);
    }

    // Add padding if necessary
    if (i % 2 == 0) {
        strcat(qrCode, "0000");
    }

    // Add end markers
    strcat(qrCode, "101");

    printQRCode(qrCode);
}

int main(int argc, char** argv) {
    if (argc == 2) {
        generateQRCode(argv[1]);
    } else {
        printf("Invalid arguments. Usage: qr_code_generator <code>\n");
        return -1;
    }
    return 0;
}