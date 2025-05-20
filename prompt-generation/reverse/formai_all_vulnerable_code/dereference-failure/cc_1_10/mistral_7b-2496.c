//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

void decode_hex(const char *str, unsigned char *output, size_t size) {
    size_t i;
    for (i = 0; i < size; ++i) {
        unsigned char byte = 0;
        int nibble1 = 0;
        int nibble2 = 0;

        if (isxdigit(*str)) {
            nibble1 = toupper(*str++) - '0';
            if (isxdigit(*str)) {
                nibble2 = toupper(*str++) - '0';
                byte = (nibble1 << 4) | nibble2;
            } else {
                byte = nibble1;
            }
        } else {
            break;
        }

        output[i] = byte;
    }
}

void encode_hex(const unsigned char *input, size_t size, char *output) {
    size_t i;
    for (i = 0; i < size; ++i) {
        int nibble1 = (input[i] & 0xF0) >> 4;
        int nibble2 = input[i] & 0x0F;

        if (nibble1 < 10) {
            output[2 * i] = '0' + nibble1;
        } else {
            output[2 * i] = 'A' + (nibble1 - 0xA);
        }

        if (nibble2 < 10) {
            output[2 * i + 1] = '0' + nibble2;
        } else {
            output[2 * i + 1] = 'A' + (nibble2 - 0xA);
        }
    }
    output[2 * size] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_hex_string> <output_binary_file>\n", argv[0]);
        return 1;
    }

    size_t input_size = strlen(argv[1]);
    unsigned char input_buffer[MAX_SIZE];

    if (input_size % 2 != 0) {
        printf("Error: Hex string length must be even.\n");
        return 1;
    }

    decode_hex(argv[1], input_buffer, input_size / 2);

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        perror("Error opening output file.");
        return 1;
    }

    fwrite(input_buffer, 1, input_size / 2, output_file);
    fclose(output_file);

    printf("Hex string '%s' has been converted to binary file '%s'\n", argv[1], argv[2]);

    return 0;
}