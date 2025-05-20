//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_DIGITS 32

typedef struct {
    char *binary;
    int decimal;
} BinaryConverter;

BinaryConverter *create_binary_converter(int decimal) {
    BinaryConverter *converter = malloc(sizeof(BinaryConverter));
    converter->binary = calloc(MAX_DIGITS, sizeof(char));
    converter->decimal = decimal;
    return converter;
}

void destroy_binary_converter(BinaryConverter *converter) {
    free(converter->binary);
    free(converter);
}

void convert_to_binary(BinaryConverter *converter) {
    int quotient, remainder;
    int i = 0;
    converter->binary[i++] = '0';
    converter->binary[i++] = 'b';

    while (converter->decimal > 0) {
        quotient = converter->decimal / 2;
        remainder = converter->decimal % 2;
        converter->binary[i++] = remainder + '0';
        converter->decimal = quotient;
    }

    converter->binary[i] = '\0';
}

int main() {
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    BinaryConverter *converter = create_binary_converter(decimal);
    convert_to_binary(converter);

    printf("The binary representation of %d is: %s\n", decimal, converter->binary);

    destroy_binary_converter(converter);

    return 0;
}