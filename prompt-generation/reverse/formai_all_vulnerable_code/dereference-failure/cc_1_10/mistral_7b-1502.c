//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void hex_to_bin(unsigned char hex, char *bin) {
    unsigned char nibble;
    int index;

    for (index = 0; index < 4; index++) {
        nibble = hex & 0xF;
        bin[index] = nibble > 9 ? (char) (nibble - 10 + 'A') : (char) (nibble + '0');
        hex >>= 4;
    }
}

void print_binary(char *bin) {
    int index;

    for (index = 0; index < 4; index++) {
        printf("%c", bin[3 - index]);
    }
}

void convert_hex_to_binary(char hex[]) {
    unsigned char i;
    char bin[5];

    for (i = 0; i < strlen(hex); i++) {
        if (!isxdigit(hex[i])) {
            printf("Invalid Hexadecimal character '%c' in input.\n", hex[i]);
            exit(EXIT_FAILURE);
        }

        hex[i] = toupper(hex[i]);

        hex_to_bin(hex[i], bin);

        printf("%s ", bin);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <hexadecimal string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Converting Hexadecimal string '%s' to Binary:\n", argv[1]);
    convert_hex_to_binary(argv[1]);

    return EXIT_SUCCESS;
}