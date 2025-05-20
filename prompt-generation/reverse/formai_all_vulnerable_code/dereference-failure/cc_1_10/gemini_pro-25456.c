//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define LOWER_HEX_BIT_MASK    0x0F
#define UPPER_HEX_BIT_MASK    0xF0

uint8_t calculate_checksum(char *input, size_t input_length) {
    uint8_t checksum = 0;

    for (size_t i = 0; i < input_length; i++) {
        checksum += input[i];
    }

    return checksum;
}

void print_checksum(uint8_t checksum) {
    printf("Checksum: 0x%02X\n", checksum);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *input = argv[1];
    size_t input_length = strlen(input);

    uint8_t checksum = calculate_checksum(input, input_length);
    print_checksum(checksum);

    // Let's get creative now!
    printf("\nOh boy, it's a party in checksum land!\n");

    if (checksum == 0) {
        printf("Woohoo! The checksum is a perfect zero!\n");
    } else if (checksum % 2 == 0) {
        printf("Parity party! The checksum is even!\n");
    } else {
        printf("Oddball alert! The checksum is odd!\n");
    }

    // Nibble time!
    uint8_t lower_nibble = checksum & LOWER_HEX_BIT_MASK;
    uint8_t upper_nibble = checksum & UPPER_HEX_BIT_MASK;

    printf("Lower nibble: 0x%01X\n", lower_nibble);
    printf("Upper nibble: 0x%01X\n", upper_nibble);

    if (lower_nibble == upper_nibble) {
        printf("Twin nibbles! How cute!\n");
    } else {
        printf("Nibble mismatch! Maybe they need some counseling.\n");
    }

    return EXIT_SUCCESS;
}