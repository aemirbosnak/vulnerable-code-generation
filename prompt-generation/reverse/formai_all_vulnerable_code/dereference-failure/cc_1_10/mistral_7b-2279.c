//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LEN 32
#define HEX_TO_BIN_LEN (MAX_HEX_LEN * 2)

void hex_to_bin(char *hex, char *bin) {
    int i, j;
    int hex_val;

    for (i = 0; i < MAX_HEX_LEN; i++) {
        if (hex[i] == '\0') break;

        hex_val = hex[i] >= '0' && hex[i] <= '9' ? hex[i] - '0' :
                 hex[i] >= 'A' && hex[i] <= 'F' ? hex[i] - 'A' + 10 : -1;

        if (hex_val < 0) {
            fprintf(stderr, "Invalid hexadecimal digit: %c\n", hex[i]);
            exit(EXIT_FAILURE);
        }

        for (j = 4; j > 0; j--) {
            bin[i * 2 + j] = (hex_val >> (j * 4)) & 0x01;
        }
    }

    bin[HEX_TO_BIN_LEN] = '\0';
}

void print_bin(char *bin) {
    int i;

    for (i = HEX_TO_BIN_LEN; i > 0; i--) {
        printf("%c", i % 8 == 0 ? (i > 0 ? ' ' : '\n') : bin[i] == '0' ? '0' : '1');
        if (i > 0 && i % 8 == 0) continue;
        putchar(bin[i]);
    }
}

int main(int argc, char **argv) {
    char input_hex[MAX_HEX_LEN + 1];
    char output_bin[HEX_TO_BIN_LEN + 1];

    if (argc != 2) {
        printf("Usage: %s <hexadecimal string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    strncpy(input_hex, argv[1], MAX_HEX_LEN);
    input_hex[MAX_HEX_LEN] = '\0';

    hex_to_bin(input_hex, output_bin);

    printf("Input hexadecimal string: %s\n", input_hex);
    printf("Equivalent binary string:\n");
    print_bin(output_bin);

    return EXIT_SUCCESS;
}