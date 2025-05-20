//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_HEX_CHARS 100

void hex_string_to_bytes(const char *hex_string, unsigned char *bytes) {
    int i;
    unsigned int temp;

    for (i = 0; i < strlen(hex_string) / 2; i++) {
        sscanf(&hex_string[i * 2], "%2x", &temp);
        bytes[i] = temp;
    }
}

bool is_hexadecimal(const char *str) {
    int i;

    for (i = 0; str[i]; i++) {
        if (!isxdigit(str[i]))
            return false;
    }

    return true;
}

void print_bytes(const unsigned char *bytes, int num_bytes) {
    int i;

    for (i = 0; i < num_bytes; i++) {
        printf("%.2X ", bytes[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hexadecimal string>\n", argv[0]);
        return 1;
    }

    if (!is_hexadecimal(argv[1])) {
        printf("Error: Invalid hexadecimal string.\n");
        return 1;
    }

    unsigned char hex_bytes[MAX_HEX_CHARS / 2];
    hex_string_to_bytes(argv[1], hex_bytes);
    print_bytes(hex_bytes, strlen(argv[1]) / 2);

    return 0;
}