//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BYTES 32
#define MAX_CHARS 65

typedef struct {
    unsigned char bytes[MAX_BYTES];
    char chars[MAX_CHARS];
} binary_char;

void binary_to_chars(unsigned char *binary, binary_char *bc) {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 7; j >= 0; j--) {
            bc->chars[i * 8 + j] = (binary[i / 8] >> j) & 1 ? '1' : '0';
        }
    }
    bc->chars[8 * MAX_BYTES] = '\0';
}

void chars_to_binary(binary_char *bc, unsigned char *binary) {
    int i, j, bit;
    for (i = 0; i < MAX_BYTES; i++) {
        binary[i] = 0;
        for (j = 0; j < 8; j++) {
            bit = (bc->chars[i * 8 + j] == '1') ? 1 : 0;
            binary[i] |= bit << (7 - j);
        }
    }
}

int main(int argc, char **argv) {
    binary_char bin_char;
    unsigned char binary[MAX_BYTES];
    int i;

    if (argc != 2) {
        printf("Usage: %s <binary string>\n", argv[0]);
        return 1;
    }

    for (i = 0; argv[1][i] != '\0'; i++) {
        if (isdigit(argv[1][i])) {
            bin_char.bytes[i / 3] |= (unsigned char) (strtoul(&argv[1][i], NULL, 2) << (i % 3 * 3));
        }
    }

    binary_to_chars(bin_char.bytes, &bin_char);
    printf("Binary string: %s\n", argv[1]);
    printf("Binary:\n");
    for (i = 0; i < MAX_BYTES; i++) {
        printf("%02x ", bin_char.bytes[i]);
    }
    printf("\nChars:\n%s\n", bin_char.chars);

    chars_to_binary(&bin_char, binary);
    printf("Converted binary string: ");
    for (i = 0; i < MAX_BYTES; i++) {
        printf("%02x ", binary[i]);
    }
    printf("\n");

    return 0;
}