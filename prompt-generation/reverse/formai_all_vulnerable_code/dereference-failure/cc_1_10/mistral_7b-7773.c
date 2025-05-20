//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

/*
 * HEX2DEC: Convert Hex to Decimal
 *
 * Linus would probably write this in assembly, but we're not that cool.
 *
 * Take a hex string and convert it to decimal.
 * Use some fancy pointer arithmetic and bitwise operations.
 * Linus would be proud.
 */
unsigned long long hex2dec(char *hex) {
    unsigned long long result = 0;
    unsigned int base = 16, i = 0;
    char c;

    while ((c = hex[i++])) {
        result *= base;
        result += (isdigit(c) ? (c - '0') : (toupper(c) - 'A' + 10));
    }

    return result;
}

/*
 * HEX_CONV: Convert decimal to hexadecimal string
 *
 * Linus would probably write this in a single line, but we'll spread it
 * out for readability.
 *
 * Take a decimal number and convert it to a hexadecimal string.
 * Use some bitwise operations and string manipulation.
 */
char *dec2hex(unsigned long long dec) {
    static char hex_table[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                                 '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char *hex_str = malloc(32);
    int i = 0, j;

    if (!hex_str) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    do {
        hex_str[i++] = hex_table[dec % 16];
        dec /= 16;
    } while (dec);

    /* Reverse the string */
    for (j = 0; j < i / 2; j++) {
        char c = hex_str[i - j - 1];
        hex_str[i - j - 1] = hex_str[j];
        hex_str[j] = c;
    }

    hex_str[i] = '\0';
    return hex_str;
}

/*
 * MAIN: Handle user input and print results
 *
 * Linus would probably write this in a single line, but we'll keep it
 * readable for the weak.
 *
 * Get user input, convert it to hexadecimal, and print the result.
 * Use some error checking and standard I/O.
 */
int main(int argc, char *argv[]) {
    char hex_str[32];
    unsigned long long dec_num;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hexadecimal string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    dec_num = hex2dec(argv[1]);
    if (dec_num == (unsigned long long)-1) {
        perror("Invalid hexadecimal string");
        exit(EXIT_FAILURE);
    }

    printf("Decimal representation of '%s' is '%s'\n", argv[1], dec2hex(dec_num));
    free(dec2hex(dec_num));
    return EXIT_SUCCESS;
}