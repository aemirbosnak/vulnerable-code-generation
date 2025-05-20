//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    uint8_t hex[3];
    uint8_t size;
} hex_t;

void parse_hex(const char *str, hex_t *hex) {
    hex->size = 0;
    *hex = (hex_t){0};

    while (*str && (hex->size < 3)) {
        if (isxdigit(*str)) {
            uint8_t value = isdigit(*str) ? (*str - '0') : (tolower(*str) - 'a' + 10);
            if (hex->size == 0) {
                hex->hex[hex->size++] = value << 4;
            } else {
                hex->hex[hex->size - 1] |= value << 4;
                hex->hex[hex->size++] = value;
                hex->size--;
            }
            str++;
        } else {
            printf("Invalid hexadecimal character: %c\n", *str);
            break;
        }
    }
}

void print_hex(const hex_t hex) {
    if (hex.size == 1) {
        printf("0x%02x", hex.hex[0]);
    } else if (hex.size == 2) {
        printf("0x%02x%02x", hex.hex[0], hex.hex[1]);
    } else {
        printf("Invalid hexadecimal data: size=%d\n", hex.size);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hex string> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t str_len = strlen(argv[1]);
    hex_t hex;

    if (str_len % 2 == 1) {
        printf("Invalid hexadecimal string length: %ld\n", str_len);
        return EXIT_FAILURE;
    }

    parse_hex(argv[1], &hex);

    FILE *output_file = fopen(argv[2], "wb");

    if (!output_file) {
        perror("Error opening output file: ");
        return EXIT_FAILURE;
    }

    fwrite(hex.hex, 1, hex.size, output_file);
    fclose(output_file);

    printf("Converted hexadecimal string: ");
    print_hex(hex);
    printf("\n");

    return EXIT_SUCCESS;
}