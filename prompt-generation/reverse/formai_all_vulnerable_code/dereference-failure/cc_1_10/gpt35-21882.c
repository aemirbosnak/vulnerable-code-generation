//FormAI DATASET v1.0 Category: Binary Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This program takes a decimal number as input and converts it into binary.
 * The conversion is done by repeatedly dividing the number by 2 and recording
 * the remainder as either 0 or 1 in a string. Finally, the string is printed
 * in reverse order to get the binary representation of the decimal number.
 *
 * Written in true Linus Torvalds style.
 */

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s decimal_number\n", argv[0]);
        return 1;
    }

    int decimal_number = atoi(argv[1]);

    if (decimal_number <= 0) {
        printf("Error: Input number must be positive!\n");
        return 1;
    }

    char binary_string[100];
    int index = 0;

    while (decimal_number > 0) {
        binary_string[index++] = decimal_number % 2 == 0 ? '0' : '1';
        decimal_number /= 2;
    }

    if (index == 0) {
        printf("0\n");
        return 0;
    }

    binary_string[index] = '\0';

    printf("Binary representation of %d is: ", atoi(argv[1]));

    for (int i = strlen(binary_string) - 1; i >= 0; i--) {
        printf("%c", binary_string[i]);
    }

    printf("\n");

    return 0;
}