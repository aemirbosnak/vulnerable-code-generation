//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000 // Maximum size of input string

int hexToDec(char hex) {
    if (isdigit(hex)) {
        return hex - '0';
    } else if (tolower(hex) >= 'a' && tolower(hex) <= 'f') {
        return tolower(hex) - 'a' + 10;
    } else {
        return 0;
    }
}

void decToHex(int dec, char* hex, int startIndex) {
    char hexDigits[] = "0123456789abcdef";
    int i = startIndex;
    while (dec > 0) {
        int rem = dec % 16;
        hex[i++] = hexDigits[rem];
        dec /= 16;
    }
    hex[i] = '\0';
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hexadecimal_number>\n", argv[0]);
        exit(1);
    }

    char hex[MAX_SIZE] = {0};
    strcpy(hex, argv[1]);

    int decimal = 0;
    int i = strlen(hex) - 1;
    while (i >= 0) {
        int hexDigit = hexToDec(hex[i]);
        if (hexDigit == 0) {
            printf("Invalid hexadecimal character: %c\n", hex[i]);
            exit(1);
        }
        decimal += hexDigit * pow(16, strlen(hex) - i - 1);
        i--;
    }

    printf("Decimal equivalent: %d\n", decimal);

    char decHex[MAX_SIZE] = {0};
    decToHex(decimal, decHex, 0);

    printf("Hexadecimal equivalent: %s\n", decHex);

    return 0;
}