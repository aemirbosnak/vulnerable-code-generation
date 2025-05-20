//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100
#define BINARY_SIZE(n) (sizeof(int) * (n / 8 + (n % 8 != 0)))

void binary_print(int number) {
    int binary[32];
    int index = 0;
    memset(binary, 0, sizeof(binary));

    while (number) {
        binary[index++] = number % 2;
        number /= 2;
    }

    for (int i = index - 1; i >= 0; i--)
        putchar(binary[i] + '0');
    putchar('\n');
}

int main(int argc, char *argv[]) {
    char input[MAX_INPUT_SIZE];
    int decimal;

    if (argc != 2) {
        printf("Usage: %s <decimal number>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);

    for (int i = 0; input[i]; i++) {
        if (isdigit(input[i]))
            decimal = decimal * 10 + (input[i] - '0');
        else if (input[i] == ' ')
            continue;
        else {
            printf("Invalid character '%c' in input.\n", input[i]);
            return 1;
        }
    }

    printf("Decimal: %d\n", decimal);
    binary_print(decimal);

    return 0;
}