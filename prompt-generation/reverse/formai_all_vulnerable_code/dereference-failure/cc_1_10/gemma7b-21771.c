//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct HexadecimalConverter {
    char *buffer;
    int bufferSize;
    int position;
    int isNegative;
} HexadecimalConverter;

HexadecimalConverter *initializeConverter(int size) {
    HexadecimalConverter *converter = malloc(sizeof(HexadecimalConverter));
    converter->buffer = malloc(size * MAX_BUFFER_SIZE);
    converter->bufferSize = size * MAX_BUFFER_SIZE;
    converter->position = 0;
    converter->isNegative = 0;
    return converter;
}

void appendHexDigit(HexadecimalConverter *converter, int digit) {
    char digitStr[2];
    sprintf(digitStr, "%x", digit);
    int strLen = strlen(digitStr);
    int i = converter->position - 1;
    for (i; i >= 0 && strLen > 0; i--) {
        converter->buffer[i] = digitStr[strLen - 1];
        strLen--;
    }
    converter->position++;
}

void setNegative(HexadecimalConverter *converter, int isNegative) {
    converter->isNegative = isNegative;
}

void convertHex(HexadecimalConverter *converter, int value) {
    if (value < 0) {
        setNegative(converter, 1);
        value = abs(value);
    }
    int digit = value / 16;
    appendHexDigit(converter, digit);
    convertHex(converter, value - digit * 16);
}

int main() {
    HexadecimalConverter *converter = initializeConverter(10);
    convertHex(converter, 0xf);
    convertHex(converter, -0x12);
    printf("%s", converter->buffer);
    free(converter->buffer);
    free(converter);
    return 0;
}