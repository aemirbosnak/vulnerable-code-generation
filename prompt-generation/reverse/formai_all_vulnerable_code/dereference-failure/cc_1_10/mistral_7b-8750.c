//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 33

void print_error_and_exit(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

int str_to_hex(const char *str, unsigned char *buf) {
    int len = strlen(str), i;
    if (len > MAX_LENGTH || len % 2 == 1) {
        print_error_and_exit("Invalid hex string length.\n");
    }

    for (i = 0; i < len; i += 2) {
        int hex = strtol(&str[i], NULL, 16);
        if (i + 1 < len) {
            buf[i / 2] = (hex << 4) | strtol(&str[i + 1], NULL, 16);
            i++;
        } else {
            buf[i / 2] = hex;
        }
    }
    return len / 2;
}

unsigned int hex_to_decimal(unsigned char *buf, int len) {
    unsigned int decimal = 0;
    int i;

    for (i = 0; i < len; i++) {
        decimal = decimal * 16 + buf[i];
    }

    return decimal;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        print_error_and_exit("Usage: ./hex_conv hex_string\n");
    }

    unsigned char hex_str[MAX_LENGTH];
    memcpy(hex_str, argv[1], strlen(argv[1]) + 1);

    int len = str_to_hex(argv[1], hex_str);
    if (len == -1) {
        return EXIT_FAILURE;
    }

    unsigned int decimal = hex_to_decimal(hex_str, len);
    printf("Decimal value: %u\n", decimal);

    return EXIT_SUCCESS;
}