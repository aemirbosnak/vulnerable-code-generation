//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BINARY_DIGITS 32

int main(int argc, char *argv[]) {
    char input_str[MAX_BINARY_DIGITS];
    int input_len, i;

    // Read input from command line
    input_len = strlen(argv[1]);
    if (input_len > MAX_BINARY_DIGITS) {
        printf("Error: Input string is too long.\n");
        return 1;
    }

    strcpy(input_str, argv[1]);

    // Convert input string to uppercase
    for (i = 0; i < input_len; i++) {
        input_str[i] = toupper(input_str[i]);
    }

    // Convert binary to decimal
    int decimal = 0;
    int base = 1;
    for (i = input_len - 1; i >= 0; i--) {
        if (input_str[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }

    // Convert decimal to binary
    char binary_str[MAX_BINARY_DIGITS];
    int j = 0;
    while (decimal > 0) {
        int remainder = decimal % 2;
        binary_str[j] = remainder + '0';
        j++;
        decimal /= 2;
    }
    binary_str[j] = '\0';

    // Print output
    printf("Binary: %s\n", binary_str);
    printf("Decimal: %d\n", decimal);

    return 0;
}