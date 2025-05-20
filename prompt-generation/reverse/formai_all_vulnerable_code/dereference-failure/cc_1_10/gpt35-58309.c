//FormAI DATASET v1.0 Category: QR code generator ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QR_CODE_SIZE 21

// Convert decimal to binary in string format
char *decToBin(int decimal) {
    char *binary = malloc(sizeof(char) * 9);  
    int index = 7;
    
    // Loop through each bit of the binary equivalent
    for(int i = 0; i < 8; i++) {
        int bitValue = decimal >> i;
        binary[index--] = (bitValue % 2 == 0 ? '0' : '1');
    }
    
    // Add null terminator to end of string
    binary[8] = '\0';
    
    return binary;
}

// Generate QR Code using input string
char *generateQRCode(char *input) {
    char *qrCode = malloc(sizeof(char) * QR_CODE_SIZE);
    
    // Iterate through input string
    for(int i = 0; i < strlen(input); i++) {
        // Convert each character to its ASCII value
        int ascii = (int)input[i];
        // Convert ASCII value to binary
        char *binary = decToBin(ascii);
        // Append binary representation to QR Code
        strcat(qrCode, binary);
    }
    
    return qrCode;
}

int main() {
    char *inputString = "HELLO WORLD";
    
    char *qrCode = generateQRCode(inputString);
    
    printf("Input String: %s\n", inputString);
    printf("QR Code: %s\n", qrCode);
    
    free(qrCode);
    
    return 0;
}