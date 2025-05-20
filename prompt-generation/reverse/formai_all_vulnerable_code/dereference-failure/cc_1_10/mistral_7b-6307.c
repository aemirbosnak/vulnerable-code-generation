//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_DIGITS 16
#define HEX_TO_DECIMAL(x) (isdigit(x) ? ((x) - '0') : ((toupper(x) >= 'A' && toupper(x) <= 'F') ? ((int) (toupper(x) - 'A' + 10)) : -1))

void hex_string_to_bin(const char *hex_string, unsigned char *bin_array, int length) {
    int hex_index = 0, bin_index = 0, byte_index = 0;
    unsigned char byte = 0;

    for (; hex_index < length; hex_index += 2) {
        byte <<= 4;
        byte |= HEX_TO_DECIMAL(hex_string[hex_index]) << 0;
        byte |= HEX_TO_DECIMAL(hex_string[hex_index + 1]) << 4;
        bin_array[byte_index++] = byte;
    }
}

void print_binary(unsigned char *bin_array, int length) {
    int i;

    for (i = 0; i < length; i++) {
        printf("%c", (i % 8 == 0) ? ' ' : (i % 4 == 0) ? '|' : ' ');
        if (bin_array[i] & 128)
            putchar('1');
        else
            putchar('0');
        if ((i + 1) % 8 == 0) {
            putchar(' ');
        }
    }
    putchar('\n');
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <hexadecimal string>\n", argv[0]);
        return 1;
    }

    unsigned char bin_array[MAX_HEX_DIGITS];
    int length = strlen(argv[1]);

    if (length > MAX_HEX_DIGITS * 2) {
        printf("Error: hexadecimal string too long.\n");
        return 1;
    }

    hex_string_to_bin(argv[1], bin_array, length / 2);
    print_binary(bin_array, length / 2);

    return 0;
}