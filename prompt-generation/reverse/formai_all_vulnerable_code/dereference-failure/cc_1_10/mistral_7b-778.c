//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to validate hexadecimal string
int isHex(const char *str) {
    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++) {
        if (isxdigit(str[i]) && (str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F') || (str[i] >= 'a' && str[i] <= 'f')) {
            continue;
        } else {
            return 0;
        }
    }

    return 1;
}

// Function to convert hexadecimal string to decimal
unsigned long long hexStringToDecimal(const char *str) {
    unsigned long long result = 0;
    unsigned long long temp = 1;

    for (int i = strlen(str) - 1; i >= 0; i--) {
        char c = str[i];

        if (isdigit(c)) {
            result += (isdigit(c) - '0') * temp;
        } else {
            result += (isupper(c) ? ((int)c - 'A' + 10) : (int)c - 'a' + 10) * temp;
        }

        temp *= 16;
    }

    return result;
}

// Function to convert decimal to binary
void decimalToBinary(unsigned long long decimal, int bitSize) {
    char binary[64] = {0};
    int i = 0;

    for (; decimal > 0; decimal /= 2) {
        binary[i++] = decimal % 2 + '0';
    }

    for (; i < bitSize; i++) {
        binary[i] = '0';
    }

    binary[bitSize] = '\0';

    printf("%s\n", binary);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hex_string> <bit_size>\n", argv[0]);
        return 1;
    }

    if (!isHex(argv[1])) {
        printf("Error: Invalid hexadecimal string.\n");
        return 1;
    }

    unsigned long long decimal = hexStringToDecimal(argv[1]);
    int bitSize = atoi(argv[2]);

    if (bitSize < 1) {
        printf("Error: Invalid bit size.\n");
        return 1;
    }

    printf("Decimal: %llu\n", decimal);
    decimalToBinary(decimal, bitSize);

    return 0;
}