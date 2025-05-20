//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NUMBER_OF_BITS 32
#define MAX_NUMBER_OF_BYTES 4

void binary_to_decimal(char *binary_string, int *decimal_value);
void decimal_to_binary(int decimal_value, char *binary_string);

int main() {
    int decimal_value;
    char binary_string[MAX_NUMBER_OF_BYTES];

    // Generate a random decimal value
    srand(time(NULL));
    decimal_value = rand() % 100;

    // Convert decimal to binary
    binary_to_decimal(binary_string, decimal_value);

    // Print the binary string
    printf("Binary representation of %d: %s\n", decimal_value, binary_string);

    // Convert binary to decimal
    decimal_to_binary(decimal_value, binary_string);

    // Print the decimal value
    printf("Decimal value of %s: %d\n", binary_string, decimal_value);

    return 0;
}

void binary_to_decimal(char *binary_string, int *decimal_value) {
    int i, j, sum = 0;

    for (i = 0; i < MAX_NUMBER_OF_BYTES; i++) {
        sum = (sum << 1) + (binary_string[i] - '0');
    }

    *decimal_value = sum;
}

void decimal_to_binary(int decimal_value, char *binary_string) {
    int i, j, rem;

    for (i = 0, j = 0; i < MAX_NUMBER_OF_BYTES; i++) {
        rem = decimal_value % 2;
        binary_string[j] = rem + '0';
        j++;
        decimal_value /= 2;
    }

    while (decimal_value > 0) {
        rem = decimal_value % 2;
        binary_string[j] = rem + '0';
        j++;
        decimal_value /= 2;
    }

    binary_string[j] = '\0';
}