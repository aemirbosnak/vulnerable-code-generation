//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100
#define HEX_SIZE 2

void die(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

int is_hex(char c) {
    if (isdigit(c)) return 1 + (c - '0');
    if (isalpha(c)) return 10 + (toupper(c) - 'A');
    return 0;
}

int str2hex(const char *str, unsigned char *out, size_t len) {
    int sum = 0, i = 0;
    size_t n = 0;

    while (n < len && str[n] && i < len / 2) {
        if (!is_hex(str[n]) || !is_hex(str[n + 1])) {
            die("Invalid hex string\n");
        }

        sum |= (is_hex(str[n]) << (4 * (3 - (i % 3)))) | is_hex(str[n + 1]);
        n += HEX_SIZE;
        i++;
    }

    if (n < len) {
        die("Invalid hex string\n");
    }

    memcpy(out, &sum, len);
    return len;
}

int main(int argc, char **argv) {
    unsigned char in[MAX_INPUT_SIZE];
    size_t len = 0;

    if (argc < 2) {
        printf("Usage: %s <hex string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    len = strlen(argv[1]);
    if (len & 1) {
        len++;
    }

    if (len > MAX_INPUT_SIZE) {
        die("Input size too large\n");
    }

    if (str2hex(argv[1], in, len) != len) {
        die("Error converting hex string\n");
    }

    printf("Converted hex string:\n");
    for (size_t i = 0; i < len; i++) {
        printf("%.2X", in[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}