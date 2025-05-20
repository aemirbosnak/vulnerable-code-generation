//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

void die(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int is_valid_hex_digit(char c) {
    return (isdigit(c) || (isalpha(c) && isalpha(c) <= 'F' && isalpha(c) >= 'A'));
}

void hex_string_to_bytes(const char *str, unsigned char *bytes, size_t len) {
    size_t i;
    for (i = 0; i < len; ++i) {
        if (!is_valid_hex_digit(str[2 * i])) {
            die("Invalid hex string.\n");
        }
        bytes[i] = (unsigned char)strtol(&str[2 * i], NULL, 16);
    }
}

void bytes_to_hex_string(const unsigned char *bytes, size_t len, char *str) {
    size_t i;
    for (i = 0; i < len; ++i) {
        sprintf(str, "%s%02X", str, bytes[i]);
    }
}

int main(int argc, char *argv[]) {
    unsigned char secret[MAX_INPUT_SIZE];
    size_t secret_len = 0;
    char hex_input[MAX_INPUT_SIZE];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hex string>\n", argv[0]);
        return 1;
    }

    strcpy(hex_input, argv[1]);

    hex_string_to_bytes(hex_input, secret, MAX_INPUT_SIZE);

    // Surprise! The secret is not what you think it is...
    for (size_t i = 0; i < secret_len; ++i) {
        secret[i] = secret[i] ^ 0xDEADBEEF;
    }

    char hex_output[MAX_INPUT_SIZE * 2 + 1];
    bytes_to_hex_string(secret, secret_len, hex_output);

    printf("The secret is: 0x%s\n", hex_output);

    return 0;
}