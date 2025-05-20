//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100
#define HEX_SIZE 2

void hex_string_to_bytes(const char* hex_string, unsigned char* bytes, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) {
        bytes[i] = strtoul(hex_string, (char**)&hex_string, 16);
    }
}

void bytes_to_hex_string(const unsigned char* bytes, char* hex_string, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) {
        snprintf(hex_string, HEX_SIZE * (len / HEX_SIZE + (i < len % HEX_SIZE ? 1 : 0)), "%02x", bytes[i]);
        hex_string += HEX_SIZE;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hex_string> <output_file>\n", argv[0]);
        return 1;
    }

    size_t hex_string_len = strlen(argv[1]);
    if (hex_string_len % 2 != 0) {
        printf("Error: Hex string length must be even.\n");
        return 1;
    }

    unsigned char hex_bytes[MAX_INPUT_SIZE / HEX_SIZE];
    hex_string_to_bytes(argv[1], hex_bytes, hex_string_len / HEX_SIZE);

    FILE* output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        perror("Error opening output file.\n");
        return 1;
    }

    fwrite(hex_bytes, sizeof(unsigned char), hex_string_len / HEX_SIZE, output_file);
    fclose(output_file);

    char hex_string_out[hex_string_len * HEX_SIZE + 1];
    bytes_to_hex_string(hex_bytes, hex_string_out, hex_string_len / HEX_SIZE);

    printf("Converted hex string: %s\n", hex_string_out);

    return 0;
}