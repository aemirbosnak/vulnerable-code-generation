//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BINARY_LENGTH 32

void binary_string_from_decimal(unsigned int decimal, char* binary_string) {
    int i;
    for (i = BINARY_LENGTH; decimal > 0; i--) {
        binary_string[i - 1] = decimal % 2 + '0';
        decimal /= 2;
    }
    binary_string[BINARY_LENGTH] = '\0';
}

void decimal_from_binary_string(const char* binary_string, unsigned int* decimal) {
    int i, power = 0;
    unsigned int result = 0;

    for (i = 0; binary_string[i] != '\0'; i++) {
        if (binary_string[i] == '1') {
            result += pow(2, power);
        }
        power++;
    }

    *decimal = result;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <decimal_number> <output_binary_string>\n", argv[0]);
        return 1;
    }

    unsigned int decimal;
    char binary_string[BINARY_LENGTH + 1];

    decimal = atoi(argv[1]);
    binary_string_from_decimal(decimal, binary_string);

    printf("Decimal Number: %u\n", decimal);
    printf("Binary String: ");
    fputs(binary_string, stdout);
    printf("\n");

    unsigned int output_decimal;
    char* output_binary_string = malloc(BINARY_LENGTH + 1);

    strncpy(output_binary_string, argv[2], BINARY_LENGTH + 1);
    output_binary_string[BINARY_LENGTH] = '\0';

    decimal_from_binary_string(output_binary_string, &output_decimal);

    printf("Output Binary String: %s\n", output_binary_string);
    printf("Equivalent Decimal Number: %u\n", output_decimal);

    free(output_binary_string);

    return 0;
}