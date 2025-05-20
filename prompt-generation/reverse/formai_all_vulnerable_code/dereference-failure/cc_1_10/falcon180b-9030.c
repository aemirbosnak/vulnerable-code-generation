//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NUM_LEN 64
#define MAX_BIN_LEN (MAX_NUM_LEN * 8 + 1)

char *binary_to_decimal(char *binary) {
    int decimal = 0;
    int power = 0;
    int len = strlen(binary);
    char *decimal_str = malloc(MAX_NUM_LEN);

    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    sprintf(decimal_str, "%d", decimal);
    return decimal_str;
}

char *decimal_to_binary(int decimal) {
    char *binary = malloc(MAX_BIN_LEN);
    int len = 0;

    while (decimal > 0) {
        int remainder = decimal % 2;
        strncat(binary, remainder == 0? "0" : "1", 1);
        decimal /= 2;
        len++;
    }

    for (int i = 0; i < MAX_BIN_LEN - len; i++) {
        strncat(binary, "0", 1);
    }

    return binary;
}

int main() {
    char input[MAX_NUM_LEN];
    char *decimal_str;
    char *binary_str;

    printf("Enter a decimal number: ");
    scanf("%s", input);

    decimal_str = binary_to_decimal(input);
    printf("Decimal: %s\n", decimal_str);

    binary_str = decimal_to_binary(atoi(decimal_str));
    printf("Binary: %s\n", binary_str);

    free(decimal_str);
    free(binary_str);

    return 0;
}