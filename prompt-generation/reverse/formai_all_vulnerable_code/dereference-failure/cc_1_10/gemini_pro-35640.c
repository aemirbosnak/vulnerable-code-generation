//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>

#define HEX_BASE 16
#define HEX_DIGITS "0123456789ABCDEF"
#define HEX_DIGITS_LOWER "0123456789abcdef"

static bool is_hex_digit(char c)
{
    return strchr(HEX_DIGITS, c) != NULL;
}

static bool is_hex_digit_lower(char c)
{
    return strchr(HEX_DIGITS_LOWER, c) != NULL;
}

static int hex_digit_to_int(char c)
{
    if (is_hex_digit(c)) {
        return c - '0';
    } else if (is_hex_digit_lower(c)) {
        return c - 'a' + 10;
    } else {
        return -1;
    }
}

static int hex_str_to_int(const char *str)
{
    int value = 0;

    while (*str != '\0') {
        int digit = hex_digit_to_int(*str);
        if (digit < 0) {
            return -1;
        }
        value = value * HEX_BASE + digit;
        str++;
    }

    return value;
}

static char *int_to_hex_str(int value)
{
    char *str = malloc(11);
    if (str == NULL) {
        return NULL;
    }

    int i = 0;
    do {
        int digit = value % HEX_BASE;
        str[i++] = HEX_DIGITS[digit];
        value /= HEX_BASE;
    } while (value > 0);

    str[i] = '\0';
    return str;
}

static void print_hex_str(int value)
{
    char *str = int_to_hex_str(value);
    if (str == NULL) {
        perror("malloc");
        return;
    }

    printf("%s\n", str);
    free(str);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hexadecimal number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int value = hex_str_to_int(argv[1]);
    if (value < 0) {
        fprintf(stderr, "Invalid hexadecimal number: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    print_hex_str(value);
    return EXIT_SUCCESS;
}