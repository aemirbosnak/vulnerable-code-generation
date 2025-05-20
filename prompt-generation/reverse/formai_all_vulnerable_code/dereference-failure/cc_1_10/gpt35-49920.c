//FormAI DATASET v1.0 Category: QR code reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert the QR code to binary
void decodeQRCode(char* str, int len, char** binary) {
    *binary = (char*) malloc(len*8*sizeof(char));
    for (int i = 0; i < len; i++) {
        char c = str[i];
        int ascii = (int) c;
        int val = 0;
        for (int j = 0; j < 8; j++) {
            if (ascii & (1 << j)) {
                (*binary)[(i*8) + j] = '1';
            }
            else {
                (*binary)[(i*8) + j] = '0';
            }
        }
    }
}

// Function to get the decimal value of a binary string
int binaryToDecimal(char* str) {
    int len = strlen(str);
    int val = 0;
    for (int i = len-1; i >= 0; i--) {
        if (str[i] == '1') {
            val += 1 << (len-1-i);
        }
    }
    return val;
}

// Function to check if the QR code is valid medieval code
int isValidCode(char* binary) {
    int len = strlen(binary);
    if (len < 16) {
        return 0;
    }
    if (len % 16 != 0) {
        return 0;
    }
    for (int i = 0; i < len; i += 16) {
        int val = binaryToDecimal(&binary[i]);
        if (val < 32 || val > 126) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char* medievalCode = "$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    printf("Welcome traveller! I am your trusty QR code reader.\n");
    printf("Please show me the QR code you found.\n");
    char qrCode[1000];
    scanf("%s", qrCode);

    char* binary = NULL;
    decodeQRCode(qrCode, strlen(qrCode), &binary);

    if (!isValidCode(binary)) {
        printf("That is not a valid medieval QR code! Please try again.\n");
        return 0;
    }

    printf("Ah, I see that this QR code contains a message in medieval code:\n");

    for (int i = 0; i < strlen(binary); i += 16) {
        int val = binaryToDecimal(&binary[i]);
        printf("%c", medievalCode[val-32]);
    }
    printf("\n");
    return 0;
}