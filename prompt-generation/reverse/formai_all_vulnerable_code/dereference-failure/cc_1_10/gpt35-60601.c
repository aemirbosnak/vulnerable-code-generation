//FormAI DATASET v1.0 Category: QR code reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CODE_LENGTH 100 // Maximum length of a QR code

// Function to check if the given string is a QR code
bool isQRCode(char* str) {
    // QR code should start with "QR:" and end with ":END"
    if (strncmp(str, "QR:", 3) != 0 || strncmp(str + strlen(str) - 4, ":END", 4) != 0) {
        return false;
    }

    // Check the length of the QR code
    int code_length = strlen(str) - 7;
    if (code_length <= 0 || code_length > MAX_CODE_LENGTH) {
        return false;
    }

    // Check if the QR code contains only valid characters
    for (int i = 3; i < strlen(str) - 4; i++) {
        if (!(str[i] == '0' || str[i] == '1')) {
            return false;
        }
    }

    return true;
}

// Function to read a QR code from the user
void readQRCode(char* code) {
    printf("Please scan the QR code:\n");
    fgets(code, MAX_CODE_LENGTH + 7, stdin);
}

// Function to decode a QR code
void decodeQRCode(char* code) {
    printf("QR code decoded:\n");
    for (int i = 3; i < strlen(code) - 4; i += 8) {
        char binary[9];
        strncpy(binary, code + i, 8);
        binary[8] = '\0';
        printf("%c", strtol(binary, NULL, 2));
    }
    printf("\n");
}

int main() {
    char code[MAX_CODE_LENGTH + 7];

    while (true) {
        readQRCode(code);

        if (isQRCode(code)) {
            decodeQRCode(code);
        } else {
            printf("Invalid QR code format.\n");
        }
    }

    return 0;
}