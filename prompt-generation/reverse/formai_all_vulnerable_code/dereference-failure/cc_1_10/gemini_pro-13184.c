//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

static const char *hex_digits = "0123456789abcdef";

// Convert a byte to a bitmask.
static uint8_t byte_to_bitmask(uint8_t byte) {
    uint8_t bitmask = 0;
    for (int i = 0; i < 8; i++) {
        bitmask |= (byte & (1 << i)) ? (1 << (7 - i)) : 0;
    }
    return bitmask;
}

// Convert a bitmask to a string.
static char *bitmask_to_string(uint8_t bitmask) {
    char *string = malloc(9);
    for (int i = 0; i < 8; i++) {
        string[i] = (bitmask & (1 << (7 - i))) ? '1' : '0';
    }
    string[8] = '\0';
    return string;
}

// Convert a hexadecimal string to a byte array.
static uint8_t *hex_string_to_bytes(const char *string) {
    uint8_t *bytes = malloc(strlen(string) / 2);
    for (int i = 0; i < strlen(string) / 2; i++) {
        char high_nibble = *(string + 2 * i);
        char low_nibble = *(string + 2 * i + 1);
        bytes[i] = (hex_digits[high_nibble - '0'] << 4) | hex_digits[low_nibble - '0'];
    }
    return bytes;
}

// Convert a byte array to a hexadecimal string.
static char *bytes_to_hex_string(const uint8_t *bytes, int length) {
    char *string = malloc(length * 2 + 1);
    for (int i = 0; i < length; i++) {
        char high_nibble = hex_digits[(bytes[i] >> 4) & 0xf];
        char low_nibble = hex_digits[bytes[i] & 0xf];
        string[2 * i] = high_nibble;
        string[2 * i + 1] = low_nibble;
    }
    string[length * 2] = '\0';
    return string;
}

// Convert a binary string to a bitmask.
static uint8_t binary_string_to_bitmask(const char *string) {
    uint8_t bitmask = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == '1') {
            bitmask |= (1 << (7 - i));
        }
    }
    return bitmask;
}

// Convert a bitmask to a binary string.
static char *bitmask_to_binary_string(uint8_t bitmask) {
    char *string = malloc(9);
    for (int i = 0; i < 8; i++) {
        string[i] = (bitmask & (1 << (7 - i))) ? '1' : '0';
    }
    string[8] = '\0';
    return string;
}

// Convert a decimal string to a byte.
static uint8_t decimal_string_to_byte(const char *string) {
    int value = atoi(string);
    if (value < 0 || value > 255) {
        fprintf(stderr, "Error: Invalid decimal value: %s\n", string);
        exit(1);
    }
    return (uint8_t)value;
}

// Convert a byte to a decimal string.
static char *byte_to_decimal_string(uint8_t byte) {
    char *string = malloc(4);
    sprintf(string, "%d", byte);
    return string;
}

// Convert a byte array to a decimal string.
static char *bytes_to_decimal_string(const uint8_t *bytes, int length) {
    char *string = malloc(length * 4 + 1);
    for (int i = 0; i < length; i++) {
        char *byte_string = byte_to_decimal_string(bytes[i]);
        strcat(string, byte_string);
        free(byte_string);
        if (i < length - 1) {
            strcat(string, ", ");
        }
    }
    string[length * 4] = '\0';
    return string;
}

// Print a byte array as a table.
static void print_byte_array(const uint8_t *bytes, int length) {
    printf("Byte  Hex Binary Decimal\n");
    printf("----- --- ----- -------\n");
    for (int i = 0; i < length; i++) {
        char *hex_string = bytes_to_hex_string(bytes + i, 1);
        char *binary_string = bitmask_to_binary_string(byte_to_bitmask(bytes[i]));
        char *decimal_string = byte_to_decimal_string(bytes[i]);
        printf("%02x    %s  %s   %s\n", i, hex_string, binary_string, decimal_string);
        free(hex_string);
        free(binary_string);
        free(decimal_string);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        exit(1);
    }

    char *input = argv[1];

    // Determine the input type.
    bool is_hexadecimal = false;
    bool is_binary = false;
    bool is_decimal = false;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            is_decimal = true;
        } else if ((input[i] >= 'a' && input[i] <= 'f') || (input[i] >= 'A' && input[i] <= 'F')) {
            is_hexadecimal = true;
        } else if (input[i] == '0' || input[i] == '1') {
            is_binary = true;
        } else {
            fprintf(stderr, "Error: Invalid input: %s\n", input);
            exit(1);
        }
    }

    // Convert the input to a byte array.
    uint8_t *bytes;
    if (is_hexadecimal) {
        bytes = hex_string_to_bytes(input);
    } else if (is_binary) {
        bytes = malloc(strlen(input) / 8);
        for (int i = 0; i < strlen(input) / 8; i++) {
            bytes[i] = binary_string_to_bitmask(input + i * 8);
        }
    } else if (is_decimal) {
        char *token = strtok(input, ", ");
        bytes = malloc(strlen(input) / 4);
        int i = 0;
        while (token != NULL) {
            bytes[i++] = decimal_string_to_byte(token);
            token = strtok(NULL, ", ");
        }
    }

    // Print the byte array in table format.
    print_byte_array(bytes, (is_hexadecimal || is_binary) ? strlen(input) / 2 : strlen(input) / 4);

    // Free the allocated memory.
    free(bytes);

    return 0;
}