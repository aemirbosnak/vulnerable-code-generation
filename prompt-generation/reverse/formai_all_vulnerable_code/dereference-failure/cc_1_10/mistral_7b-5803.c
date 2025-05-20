//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUF_SIZE 100
#define HEX_SIZE 2
#define MAX_NUM 16

void print_error_and_exit(char *msg) {
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

int hex_str_to_int(char *str) {
    int num = 0;
    int power = 0;
    char c;

    for (; *str && isxdigit(*str); str++) {
        c = tolower(*str);
        if (isdigit(c))
            num += (c - '0') << power;
        else
            num += (c - 'a' + 10) << power;
        power += HEX_SIZE;
    }

    if (*str)
        print_error_and_exit("Invalid hexadecimal number\n");

    return num;
}

int main(int argc, char **argv) {
    char *input, *output;
    int num, i;

    if (argc != 3)
        print_error_and_exit("Usage: ./hex_converter <input_hex_str> <output_decimal_num>\n");

    input = argv[1];
    output = malloc(MAX_NUM * sizeof(char));

    num = hex_str_to_int(input);

    if (num > MAX_NUM)
        print_error_and_exit("Number too large to be converted to hexadecimal\n");

    for (i = 0; num; i++) {
        output[i] = "0123456789ABCDEF"[num % 16];
        num /= 16;
    }

    printf("%s\n", output);

    free(output);
    return EXIT_SUCCESS;
}