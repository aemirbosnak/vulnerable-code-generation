//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024

void binary_string_from_decimal(unsigned long decimal, char* binary_string, int length) {
    int i;
    for (i = length - 1; i >= 0; i--) {
        binary_string[i] = (decimal % 2) + '0';
        decimal /= 2;
    }
}

void decimal_from_binary_string(char* binary_string, unsigned long* decimal, int length) {
    int i, sum, base = 1;
    *decimal = 0;
    for (i = length - 1; i >= 0; i--) {
        sum += (*(binary_string + i) - '0') * base;
        base *= 2;
        *decimal += sum;
        sum = 0;
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <decimal_number> <binary_string_length>\n", argv[0]);
        return 1;
    }

    unsigned long decimal = atol(argv[1]);
    int binary_length = atoi(argv[2]);
    char binary_string[MAX_INPUT_SIZE];

    binary_string_from_decimal(decimal, binary_string, binary_length);

    printf("Decimal Number: %lu\n", decimal);
    printf("Binary String: ");

    int i;
    for (i = 0; i < binary_length; i++) {
        printf("%c", binary_string[i]);
    }
    printf("\n");

    unsigned long dec_result;
    decimal_from_binary_string(binary_string, &dec_result, binary_length);

    printf("Decimal Result: %lu\n", dec_result);

    return 0;
}