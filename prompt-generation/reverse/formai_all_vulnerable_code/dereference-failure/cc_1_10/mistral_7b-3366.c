//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_HEX 100

void to_hex(unsigned char *input, char *output, int length) {
    for (int i = 0; i < length; i++) {
        unsigned char byte = input[i];
        char hex[3];

        hex[0] = "0123456789ABCDEF"[byte >> 4];
        hex[1] = "0123456789ABCDEF"[byte & 0xF];

        if (output) {
            output[i * 2] = hex[0];
            output[i * 2 + 1] = hex[1];
        }
    }
}

int hex_to_decimal(char hex) {
    if (isdigit(hex)) {
        return hex - '0';
    } else if (isalpha(hex)) {
        return 10 + hex - 'A';
    } else {
        return -1;
    }
}

void from_hex(char *input, unsigned char *output, int length) {
    for (int i = 0; i < length; i += 2) {
        unsigned char byte = 0;

        byte <<= 4;
        byte += hex_to_decimal(input[i]);
        byte <<= 4;
        byte += hex_to_decimal(input[i + 1]);

        output[i / 2] = byte;
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <hex_string> <output_file>\n", argv[0]);
        return 1;
    }

    int hex_len = strlen(argv[1]);
    if (hex_len % 2 != 0) {
        printf("Error: Invalid hex string length.\n");
        return 1;
    }

    unsigned char *output = (unsigned char *)malloc(hex_len / 2 * sizeof(unsigned char));

    if (!output) {
        perror("Error: Failed to allocate memory for output.\n");
        return 1;
    }

    char hex_str[MAX_HEX] = {0};
    strncpy(hex_str, argv[1], MAX_HEX);

    from_hex(hex_str, output, hex_len / 2);

    FILE *fp = fopen(argv[2], "wb");

    if (!fp) {
        perror("Error: Failed to open output file.\n");
        free(output);
        return 1;
    }

    fwrite(output, hex_len / 2, 1, fp);
    fclose(fp);

    free(output);

    printf("Hex string '%s' converted to binary and saved to '%s'\n", argv[1], argv[2]);

    return 0;
}