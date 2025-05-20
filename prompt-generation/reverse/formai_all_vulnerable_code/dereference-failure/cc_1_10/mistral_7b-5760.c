//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: artistic
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Galactic Hash Function Prototype
uint32_t GalacticHash(const uint8_t* data, size_t length);

// Constants for the Galactic Hash Function
#define GALACTIC_CONST_A 0x675435E6
#define GALACTIC_CONST_B 0x12345EAD
#define GALACTIC_CONST_C 0xEFCDAB89
#define GALACTIC_ROUNDS 10

// Helper function for left rotate
uint32_t RotateLeft(uint32_t value, int shift) {
    return (value << shift) | (value >> (32 - shift));
}

// Galactic Hash Function
uint32_t GalacticHash(const uint8_t* data, size_t length) {
    uint32_t hash[GALACTIC_ROUNDS] = {GALACTIC_CONST_A, GALACTIC_CONST_B, GALACTIC_CONST_C};
    size_t offset = 0;

    for (int i = 0; i < GALACTIC_ROUNDS; i++) {
        for (size_t j = 0; j < length; j++) {
            uint8_t byte = data[offset++];
            uint32_t temp = hash[i];

            // Add byte to the current hash value
            temp = (temp + byte) * 0x1000193;

            // Perform left rotation
            temp = RotateLeft(temp, 14);

            // Add previous hash value
            temp = temp ^ hash[i-1];

            // Store the current hash value in the previous hash value
            hash[i] = temp;
        }
    }

    // Combine the final hash values
    uint32_t checksum = hash[GALACTIC_ROUNDS-1];
    for (int i = GALACTIC_ROUNDS - 1; i >= 1; i--) {
        checksum = checksum ^ hash[i-1];
    }

    return checksum;
}

// Main function
int main() {
    const uint8_t input[] = "Galactic Hash Function";

    // Calculate the Galactic Hash of the input data
    uint32_t checksum = GalacticHash(input, strlen(input));

    printf("Galactic Hash of \"%s\": 0x%08X\n", input, checksum);

    return 0;
}