//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: portable
#include <stdio.h>
#include <string.h>

// Function to convert a decimal number to a hexadecimal string
char* decimalToHexadecimal(int n) {
    char* hexString = (char*)malloc(sizeof(char)*10);
    if (hexString == NULL) {
        return NULL;
    }

    // Convert the decimal number to hexadecimal
    int remainder = n % 16;
    char* hexDigit = (char*)malloc(sizeof(char)*2);
    if (hexDigit == NULL) {
        free(hexString);
        return NULL;
    }
    sprintf(hexDigit, "%c", (char)('0' + remainder));
    hexString = strcat(hexString, hexDigit);
    free(hexDigit);

    while (n >= 16) {
        remainder = n % 16;
        hexDigit = (char*)malloc(sizeof(char)*2);
        if (hexDigit == NULL) {
            free(hexString);
            return NULL;
        }
        sprintf(hexDigit, "%c", (char)('0' + remainder));
        hexString = strcat(hexString, hexDigit);
        free(hexDigit);
        n /= 16;
    }

    // Append the remainder to the hexadecimal string
    remainder = n;
    hexDigit = (char*)malloc(sizeof(char)*2);
    if (hexDigit == NULL) {
        free(hexString);
        return NULL;
    }
    sprintf(hexDigit, "%c", (char)('0' + remainder));
    hexString = strcat(hexString, hexDigit);
    free(hexDigit);

    return hexString;
}

int main() {
    int decimalNumber = 123;
    char* hexString = decimalToHexadecimal(decimalNumber);
    if (hexString == NULL) {
        printf("Error converting decimal to hexadecimal\n");
        return 1;
    }
    printf("Hexadecimal equivalent of %d is %s\n", decimalNumber, hexString);
    free(hexString);
    return 0;
}