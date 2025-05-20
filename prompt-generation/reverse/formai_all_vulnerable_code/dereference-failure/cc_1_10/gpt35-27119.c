//FormAI DATASET v1.0 Category: QR code reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Function to check if the scanned QR code is valid or not
bool isValidQR(char* code) {
    int length = strlen(code);

    // QR code should start with "QR:"
    if (strncmp(code, "QR:", 3) != 0)
        return false;
    
    // QR code should end with ";"
    if (code[length-1] != ';')
        return false;

    // QR code should have eight digits followed by four alphabets
    if (length != 13 || !isdigit(code[3]) || !isdigit(code[4]) || !isdigit(code[5]) || !isdigit(code[6]) || !isdigit(code[7]) || !isdigit(code[8]) || !isdigit(code[9]) || !isdigit(code[10]) || !isalpha(code[11]) || !isalpha(code[12]))
        return false;

    return true;    
}

int main() {
    char qrCode[14];
    bool valid = false;

    srand(time(NULL)); // Seed for random number generator

    printf("Welcome to the QR code scanner program!\n\n");

    // Random QR code is generated for demo
    sprintf(qrCode, "QR:%d%d%d%d%d%d%d%s;", rand()%10, rand()%10, rand()%10, rand()%10, rand()%10, rand()%10, rand()%10, "ABCD");

    printf("Scanning QR code...\n");
    printf("QR code read: %s\n", qrCode);

    // Checking if scanned QR code is valid or not
    valid = isValidQR(qrCode);

    if (valid) {
        printf("\nQR code is valid!\n");
        printf("Product details:\n");

        // Extracting product information from QR code
        printf("Product ID: %c%c%c%c%c%c%c\n", qrCode[3], qrCode[4], qrCode[5], qrCode[6], qrCode[7], qrCode[8], qrCode[9]);
        printf("Product Type: %c%c%c%c\n\n", qrCode[11], qrCode[12], qrCode[13], qrCode[14]);
    } else {
        printf("\nInvalid QR code. Try again!\n");
    }

    return 0;
}