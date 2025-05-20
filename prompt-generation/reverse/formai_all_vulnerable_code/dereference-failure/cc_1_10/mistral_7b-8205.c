//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HEX_TO_BIN(x)  (0x ## x)
#define BIN_TO_HEX(x)  (0x##1*((x)>>7)&0x1 | 0x##2*((x)>>6)&0x1 | \
                        0x##3*((x)>>5)&0x1 | 0x##4*((x)>>4)&0x1 | \
                        0x##5*((x)>>3)&0x1 | 0x##6*((x)>>2)&0x1 | \
                        0x##7*(x)&0x1 | 0x##8)

typedef struct {
    unsigned char hex[3];
    unsigned char bin[4];
} hex_bin;

void error_and_exit(char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        error_and_exit("Usage: hex2bin <hex_string>");
    }

    size_t input_len = strlen(argv[1]);

    if (input_len % 2 != 0) {
        error_and_exit("Invalid hexadecimal string length.");
    }

    hex_bin *hex_bin_struct = malloc(sizeof(hex_bin) * (input_len / 2));

    for (size_t i = 0; i < input_len / 2; i++) {
        sscanf(argv[1] + i * 2, "%2hhx", &hex_bin_struct[i].hex[0]);
        sscanf(argv[1] + i * 2 + 1, "%2hhx", &hex_bin_struct[i].hex[1]);

        for (int j = 0; j < 4; j++) {
            hex_bin_struct[i].bin[j] = BIN_TO_HEX((hex_bin_struct[i].hex[0] >> (4 * (3 - j))) & 0xF);
        }
    }

    for (size_t i = 0; i < input_len / 2; i++) {
        for (int j = 0; j < 4; j++) {
            putchar(hex_bin_struct[i].bin[j]);
        }
    }

    free(hex_bin_struct);

    return EXIT_SUCCESS;
}