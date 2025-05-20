//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a single hexadecimal digit to its decimal equivalent
int hex_to_decimal(char c) {
    if (isdigit(c)) return c - '0';
    else if (isalpha(c)) return (isupper(c) ? 10 + (c - 'A') : 15 + (c - 'a'));
    else return -1;
}

// Function to convert a hexadecimal string to a binary string
void hex_to_binary(char *hex, char *binary, int *length) {
    int i, j, hex_len = strlen(hex);
    *length = hex_len * 4;

    for (i = 0; i < hex_len; i++) {
        int byte = hex_to_decimal(hex[i]);
        if (byte == -1) {
            printf("Invalid hexadecimal digit: %c\n", hex[i]);
            exit(1);
        }

        for (j = 0; j < 4; j++) {
            binary[(*length) --] = (byte >> (3 * (3 - j))) & 0b00001111;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hex_string> <output_file>\n", argv[0]);
        return 1;
    }

    char hex[100], binary[400];
    int length;

    strcpy(hex, argv[1]);

    hex_to_binary(hex, binary, &length);

    FILE *fp = fopen(argv[2], "wb");

    if (fp == NULL) {
        perror("Error opening output file");
        return 1;
    }

    fwrite(binary, 1, length, fp);
    fclose(fp);

    printf("Binary representation of hexadecimal string written to %s\n", argv[2]);

    return 0;
}