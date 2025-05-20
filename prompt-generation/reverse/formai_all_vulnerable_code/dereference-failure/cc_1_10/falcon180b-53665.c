//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    char *binary;
    int decimal;
} BinaryConverter;

BinaryConverter *createConverter() {
    BinaryConverter *converter = (BinaryConverter *) malloc(sizeof(BinaryConverter));
    converter->binary = (char *) malloc(MAX_SIZE * sizeof(char));
    converter->decimal = 0;
    converter->binary[0] = '\0';
    return converter;
}

void destroyConverter(BinaryConverter *converter) {
    free(converter->binary);
    free(converter);
}

void appendBinary(BinaryConverter *converter, int value) {
    char temp[MAX_SIZE];
    sprintf(temp, "%d", value);
    strcat(converter->binary, temp);
}

int getDecimal(BinaryConverter *converter) {
    return converter->decimal;
}

void setDecimal(BinaryConverter *converter, int decimal) {
    converter->decimal = decimal;
}

int main() {
    BinaryConverter *converter = createConverter();
    int decimal = 42;
    int binary[32];
    int length = 0;

    while (decimal > 0) {
        binary[length++] = decimal % 2;
        decimal /= 2;
    }

    for (int i = length - 1; i >= 0; i--) {
        appendBinary(converter, binary[i]);
    }

    printf("Binary: %s\n", converter->binary);
    printf("Decimal: %d\n", getDecimal(converter));

    destroyConverter(converter);
    return 0;
}