//Falcon2-11B DATASET v1.0 Category: Binary Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int size;
    char* data;
} BinaryConverter;

BinaryConverter* createBinaryConverter(const char* binary) {
    BinaryConverter* converter = malloc(sizeof(BinaryConverter));
    converter->size = strlen(binary);
    converter->data = strdup(binary);
    return converter;
}

void freeBinaryConverter(BinaryConverter* converter) {
    free(converter->data);
    free(converter);
}

void convertBinaryToDecimal(BinaryConverter* converter, int* decimal) {
    int power = 0;
    int digit = 0;
    int decimalDigit = 0;
    int sum = 0;

    while (power < converter->size) {
        digit = converter->data[power] - '0';
        if (digit == 1) {
            decimalDigit = 2 * decimalDigit + 1;
        } else if (digit == 2) {
            decimalDigit = 2 * decimalDigit;
        } else {
            decimalDigit = 0;
        }
        power++;
        sum += decimalDigit;
    }
    *decimal = sum;
}

int main() {
    const char* binary = "11011010";
    BinaryConverter* converter = createBinaryConverter(binary);
    int decimal;
    convertBinaryToDecimal(converter, &decimal);
    printf("Decimal: %d\n", decimal);
    freeBinaryConverter(converter);
    return 0;
}