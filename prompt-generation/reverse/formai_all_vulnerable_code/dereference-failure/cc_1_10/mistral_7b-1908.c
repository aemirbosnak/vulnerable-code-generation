//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 33 // Maximum length of hexadecimal number
#define BASE_SIZE 16 // Size of hexadecimal base

void print_error_and_exit(char error_message) {
    printf("\n%cError: %c%s%c\n", 174, error_message, "Invalid hexadecimal number.", 174);
    exit(EXIT_FAILURE);
}

int is_hexadecimal(const char *str) {
    int i = 0;

    if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X')) {
        i += 2;
    }

    while (str[i] != '\0') {
        if (!isxdigit(str[i])) {
            return 0;
        }
        i++;
    }

    return 1;
}

int *hex_to_decimal(const char *str, int *length) {
    int i = 0, value = 0, power = 0;
    int *decimal = (int *)calloc(MAX_LENGTH, sizeof(int));

    if (!decimal) {
        print_error_and_exit('M');
    }

    if (!is_hexadecimal(str)) {
        free(decimal);
        print_error_and_exit('I');
    }

    *length = 0;

    while (str[i] != '\0') {
        value = isdigit(str[i]) ? str[i] - '0' : tolower(str[i]) - 'a' + 10;

        if (*length > 0) {
            decimal[*length] += value * pow(16, power);
            power++;
        } else {
            decimal[0] = value;
            power = 1;
        }

        i++;
        (*length)++;
    }

    return decimal;
}

void print_decimal(int *decimal, int length) {
    int i = length - 1;

    while (i >= 0) {
        printf("%d", decimal[i]);
        i--;
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    int *decimal;
    int length;

    if (argc != 2) {
        print_error_and_exit('U');
    }

    decimal = hex_to_decimal(argv[1], &length);

    if (decimal) {
        printf("Decimal representation of '%s':\n", argv[1]);
        print_decimal(decimal, length);
        free(decimal);
    }

    return EXIT_SUCCESS;
}