//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 512

void hex_to_decimal(char *input, int *output) {
    int i = 0;
    int sum = 0;
    int len = strlen(input);
    bool negative = false;

    // Check for negative number
    if (input[0] == '-') {
        negative = true;
        i++;
    }

    // Convert hex to decimal
    for (; i < len; i++) {
        if (isxdigit(input[i])) {
            int digit = isdigit(input[i]) ? input[i] - '0' : input[i] - 'A' + 10;
            sum += digit * pow(16, len - i - 1);
        }
    }

    // Set output to negative number if needed
    if (negative)
        *output = -sum;
    else
        *output = sum;
}

int main(int argc, char **argv) {
    char input[MAX_INPUT_SIZE];
    int decimal;

    if (argc != 2) {
        printf("Usage: %s <hexadecimal_number>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);

    hex_to_decimal(input, &decimal);

    printf("The decimal representation of %s is %d.\n", input, decimal);

    return 0;
}