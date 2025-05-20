//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: optimized
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>

#define BINARY_WIDTH 8
#define BINARY_STR_LEN 32

// Function to convert binary to string
void binary_to_string(uint8_t *binary, size_t len, char *str) {
    size_t i;
    for (i = 0; i < len; i++) {
        if (binary[i] & 1) {
            str[i * BINARY_WIDTH + BINARY_STR_LEN - 1] = '1';
        } else {
            str[i * BINARY_WIDTH + BINARY_STR_LEN - 1] = '0';
        }
    }
    str[len * BINARY_WIDTH] = '\0';
}

// Function to convert string to binary
void string_to_binary(char *str, uint8_t *binary, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) {
        if (str[i] == '1') {
            binary[i / BINARY_WIDTH] |= (1 << (i % BINARY_WIDTH));
        } else {
            binary[i / BINARY_WIDTH] &= ~(1 << (i % BINARY_WIDTH));
        }
    }
}

int main() {
    uint8_t binary[10];
    char str[10];
    size_t len = 10;

    // Initialize binary array with random values
    for (size_t i = 0; i < len; i++) {
        binary[i] = rand() & 0x01;
    }

    // Convert binary to string
    binary_to_string(binary, len, str);

    // Print the string
    printf("Binary string: %s\n", str);

    // Convert string to binary
    string_to_binary(str, binary, len);

    // Print the binary
    for (size_t i = 0; i < len; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");

    return 0;
}