//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(int argc, char *argv[]) {
    char input[100];
    char *result;
    int i, j, k, base, len, sign;

    // Prompt user for input
    printf("Enter a binary number: ");
    fgets(input, 100, stdin);

    // Remove newline character
    input[strcspn(input, "\n")] = '\0';

    // Check if input is valid binary number
    if (!is_binary(input)) {
        printf("Invalid input! Please enter a binary number.\n");
        return 1;
    }

    // Convert binary to decimal
    base = 10;
    len = strlen(input);
    result = malloc(len + 1);
    result[len] = '\0';
    for (i = 0, j = len - 1, sign = 0; i < len; i++) {
        if (input[i] == '1') {
            result[j] = '1';
            j--;
        }
        else if (input[i] == '0') {
            result[j] = '0';
            j--;
        }
        else if (input[i] == '-') {
            sign = 1;
        }
        else if (input[i] == '+') {
            sign = 0;
        }
    }
    if (sign == 1) {
        result[0] = '-';
    }

    // Print result
    printf("Decimal equivalent: %s\n", result);

    free(result);
    return 0;
}

int is_binary(char *str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        if (str[i]!= '0' && str[i]!= '1') {
            return 0;
        }
    }
    return 1;
}