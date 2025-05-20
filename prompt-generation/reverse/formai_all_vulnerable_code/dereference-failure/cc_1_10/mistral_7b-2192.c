//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BIN_SIZE 8

void binary_string(unsigned char *binary, int size) {
    int i;

    for (i = size; i > 0; i--) {
        printf("%c", (binary[i] > 0) ? '1' : '0');
    }
    printf("\n");
}

int hex_to_decimal(char hex) {
    if (hex >= '0' && hex <= '9')
        return hex - '0';
    else if (hex >= 'A' && hex <= 'F')
        return hex - 'A' + 10;
    return -1;
}

void hex_string_to_binary(char *hex_string, unsigned char *binary) {
    int i, j, length, dec_val;

    length = strlen(hex_string);

    for (i = 0, j = 0; i < length; i += 2) {
        dec_val = hex_to_decimal(hex_string[i]) * 16;

        if (i + 1 < length)
            dec_val += hex_to_decimal(hex_string[i + 1]);

        binary[j++] = dec_val >> 4;
        binary[j++] = dec_val & 0x0F;
    }
}

int main(int argc, char **argv) {
    unsigned char binary[BIN_SIZE];
    int i, size;

    if (argc != 3) {
        printf("Usage : %s <hex_string> <output_binary_file>\n", argv[0]);
        return -1;
    }

    size = strlen(argv[1]);

    if ((size % 2) != 0) {
        printf("Error : Hex string length should be even.\n");
        return -1;
    }

    hex_string_to_binary(argv[1], binary);
    binary_string(binary, BIN_SIZE);

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        perror("Error opening output file.\n");
        return -1;
    }

    fwrite(binary, sizeof(unsigned char), BIN_SIZE, output);
    fclose(output);

    printf("Binary data written to %s successfully.\n", argv[2]);

    return 0;
}