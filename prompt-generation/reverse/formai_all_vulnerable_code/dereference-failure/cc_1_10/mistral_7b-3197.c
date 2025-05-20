//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Retro style ASCII art logo
// -----------------------------------------------------
//                          ^
//                         / \
//                        /___\
//                       /    \
//                      /      \
//                     /_______\
//                    | HexCon |
//                    |_______|
//                         v
// -----------------------------------------------------

void print_hex(unsigned char *hex, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%.2X ", hex[i]);
    }
    printf("\n");
}

void hex_string_to_bytes(char *hex_string, unsigned char *bytes, int length) {
    int i = 0, j = 0;
    unsigned char current_byte_high = 0, current_byte_low = 0;

    while (i < length) {
        if (hex_string[j] == ' ') {
            j++;
            continue;
        }

        if (isxdigit(hex_string[j]) && (j < (length - 1)) && isxdigit(hex_string[j + 1])) {
            sscanf(&hex_string[j], "%2hhx", &current_byte_high);
            j += 2;
            sscanf(&hex_string[j], "%2hhx", &current_byte_low);

            bytes[i] = (current_byte_high << 4) | current_byte_low;
            i++;
        } else {
            sscanf(&hex_string[j], "%2hhx", &current_byte_low);
            bytes[i] = current_byte_low;
            i++;
        }
    }
}

int main(int argc, char *argv[]) {
    int i, length;
    unsigned char input[10];

    if (argc != 2) {
        printf("Usage: %s <hexadecimal string>\n", argv[0]);
        return 1;
    }

    length = strlen(argv[1]);

    if (length % 2 != 0) {
        printf("Error: Hexadecimal string length must be even.\n");
        return 1;
    }

    hex_string_to_bytes(argv[1], input, length / 2);
    print_hex(input, length / 2);

    return 0;
}