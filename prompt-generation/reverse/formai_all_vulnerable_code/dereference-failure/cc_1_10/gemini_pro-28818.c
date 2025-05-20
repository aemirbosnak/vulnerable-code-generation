//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define CHECKSUM_SIZE 4

// Calculate the checksum of a given data block using a specific algorithm
unsigned int calculate_checksum(const void *data, size_t data_size, unsigned int algorithm_key) {
    unsigned int checksum = 0;
    const unsigned char *data_bytes = (const unsigned char *)data;

    // Iterate over the data bytes and perform the checksum calculation
    for (size_t i = 0; i < data_size; i++) {
        // Apply the algorithm key to the current byte
        unsigned int key_applied_byte = data_bytes[i] ^ algorithm_key;

        // Shift the checksum to the left and add the key-applied byte
        checksum = (checksum << 8) + key_applied_byte;

        // Handle any overflow by masking the checksum
        checksum &= 0xFFFFFFFF;
    }

    return checksum;
}

// Generate a random data block of a specified size
void generate_random_data(void *data, size_t data_size) {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate random bytes and fill the data block
    for (size_t i = 0; i < data_size; i++) {
        ((unsigned char *)data)[i] = rand() % 256;
    }
}

// Print the checksum of a given data block to the console
void print_checksum(const unsigned char *data, size_t data_size, unsigned int algorithm_key) {
    // Calculate the checksum
    unsigned int checksum = calculate_checksum(data, data_size, algorithm_key);

    // Convert the checksum to a hexadecimal string
    char checksum_string[CHECKSUM_SIZE * 2 + 1];
    sprintf(checksum_string, "%08X", checksum);

    // Print the checksum
    printf("Checksum: %s\n", checksum_string);
}

// Main function to test the checksum calculation
int main() {
    // Define the data block size
    size_t data_size = 1024;

    // Allocate memory for the data block
    unsigned char *data = (unsigned char *)malloc(data_size);

    // Generate random data for testing
    generate_random_data(data, data_size);

    // Specify the algorithm key
    unsigned int algorithm_key = 0x12345678;

    // Calculate and print the checksum
    print_checksum(data, data_size, algorithm_key);

    // Free the allocated memory
    free(data);

    return 0;
}