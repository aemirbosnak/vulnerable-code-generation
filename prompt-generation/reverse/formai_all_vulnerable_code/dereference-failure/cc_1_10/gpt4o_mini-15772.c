//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_BUFFER_SIZE 1024

// Function to calculate the checksum using a simple additive method
uint32_t calculate_checksum(const uint8_t *data, size_t length) {
    uint32_t checksum = 0;
    for (size_t i = 0; i < length; i++) {
        checksum += data[i];
    }
    return checksum;
}

// Function to get user input
size_t get_input_data(uint8_t *buffer, size_t max_size) {
    printf("Enter the data (up to %zu bytes, hit ENTER to finish):\n", max_size - 1);
    fgets((char *)buffer, max_size, stdin);
    
    // Determine actual length and remove newline character if present
    size_t length = strnlen((char *)buffer, max_size);
    if (length > 0 && buffer[length - 1] == '\n') {
        buffer[length - 1] = '\0'; // Remove newline
        length--; // Adjust length
    }
    
    return length;
}

// Function to print checksum in hexadecimal format
void print_checksum(uint32_t checksum) {
    printf("Checksum: 0x%X\n", checksum);
}

// Main function
int main() {
    uint8_t buffer[MAX_BUFFER_SIZE];
    printf("Welcome to the Checksum Calculator!\n");
    
    // Get user input data
    size_t data_length = get_input_data(buffer, MAX_BUFFER_SIZE);
    
    // Calculate the checksum
    uint32_t checksum = calculate_checksum(buffer, data_length);
    
    // Print the checksum
    print_checksum(checksum);
    
    return 0;
}