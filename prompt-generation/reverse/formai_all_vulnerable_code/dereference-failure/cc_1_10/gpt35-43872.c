//FormAI DATASET v1.0 Category: Binary Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char value[8];
} byte;

char toHex(int value) {
    if (value <= 9) {
        return value + '0';
    } else {
        return value - 10 + 'A';
    }
}

void toBinary(int value, byte *result) {
    for (int i = 0; i < 8; i++) {
        result->value[i] = (value & (1 << i)) ? '1' : '0';
    }
}

void toHexadecimal(byte *binary, char *result) {
    for (int i = 0; i < 8; i += 4) {
        int hexValue = 0;
        for (int j = 0; j < 4; j++) {
            hexValue += (binary->value[i+j] == '1') ? (1 << 3-j) : 0;
        }
        *(result++) = toHex(hexValue);
    }
    *result = '\0';
}

void paranoidPrint(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        usleep(100);
        printf("%c", str[i]);
        fflush(stdout);
    }
}

int main() {
    paranoidPrint("Enter an unsigned byte value (0 - 255): ");
    unsigned int value;
    scanf("%d", &value);
    if (value > 255) {
        paranoidPrint("Invalid value. Program will now exit.\n");
        return 1;
    }
    byte binary;
    toBinary(value, &binary);
    char hex[3];
    toHexadecimal(&binary, hex);
    paranoidPrint("\nBinary value: ");
    paranoidPrint(binary.value);
    paranoidPrint("\nHexadecimal value: ");
    paranoidPrint(hex);
    paranoidPrint("\n");
    return 0;
}