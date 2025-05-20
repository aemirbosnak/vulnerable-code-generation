//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LEN 33
#define HEX_TO_BIN_LEN 4

void die(const char *msg) {
    perror(msg);
    exit(1);
}

void hex_string_to_bin(const char *hex_str, unsigned char *bin_arr, int len) {
    int i, j, index;
    unsigned char c;

    for (i = 0; i < len; i++) {
        bin_arr[i] = 0;
    }

    for (i = 0; i < strlen(hex_str); i += 2) {
        c = hex_str[i];
        if (isdigit(c)) {
            index = c - '0';
        } else {
            index = tolower(c) - 'a' + 10;
        }

        c = hex_str[i + 1];
        bin_arr[i / 2] |= index << (4 * (i % 2));
    }
}

void print_bin(unsigned char *bin_arr, int len) {
    int i;

    printf("Binary representation: ");
    for (i = 0; i < len; i++) {
        printf("%02x ", bin_arr[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    unsigned char bin_arr[MAX_HEX_LEN / HEX_TO_BIN_LEN];
    char hex_str[MAX_HEX_LEN];
    int len;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hexadecimal string>\n", argv[0]);
        exit(1);
    }

    strcpy(hex_str, argv[1]);
    len = strlen(hex_str);

    if (len % 2 != 0) {
        fprintf(stderr, "Error: Hexadecimal string length must be even.\n");
        exit(1);
    }

    hex_string_to_bin(hex_str, bin_arr, len / 2);
    print_bin(bin_arr, len / 2);

    return 0;
}