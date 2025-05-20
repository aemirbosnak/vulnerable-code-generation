//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOLD_STYLE  0x0F
#define ITALIC_STYLE  0x10
#define UNDERSCORE_STYLE  0x20

void binary_converter(int, int, int);

int main() {
    int num_binary, num_decimal, i, j, flag;
    char binary_string[16];

    printf("Enter a binary number: ");
    scanf("%15s", binary_string);

    num_binary = strtol(binary_string, NULL, 2);
    num_decimal = binary_to_decimal(num_binary);

    printf("The binary number is: %d\n", num_binary);
    printf("The decimal number is: %d\n", num_decimal);

    return 0;
}

int binary_to_decimal(int num) {
    int rem, div;

    rem = num % 2;
    div = num / 2;

    if (rem == 1) {
        div++;
    }

    return div;
}

void binary_converter(int num_binary, int num_decimal, int style) {
    int i, j, flag;
    char binary_string[16];

    if (style == BOLD_STYLE) {
        printf("** Binary Converter **\n");
    } else if (style == ITALIC_STYLE) {
        printf("_ Binary Converter _\n");
    } else if (style == UNDERSCORE_STYLE) {
        printf("_Binary Converter_\n");
    } else {
        printf("Binary Converter\n");
    }

    printf("Enter a binary number: ");
    scanf("%15s", binary_string);

    num_binary = strtol(binary_string, NULL, 2);
    num_decimal = binary_to_decimal(num_binary);

    if (style == BOLD_STYLE) {
        printf("The binary number is: %d\n", num_binary);
        printf("The decimal number is: %d\n", num_decimal);
    } else if (style == ITALIC_STYLE) {
        printf("The binary number is: %d\n", num_binary);
        printf("The decimal number is: %d\n", num_decimal);
    } else if (style == UNDERSCORE_STYLE) {
        printf("The binary number is: %d\n", num_binary);
        printf("The decimal number is: %d\n", num_decimal);
    } else {
        printf("The binary number is: %d\n", num_binary);
        printf("The decimal number is: %d\n", num_decimal);
    }
}