//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: real-life
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

// Function to calculate the one's complement checksum
uint8_t calc_checksum(uint8_t *data, uint16_t length) {
    uint8_t checksum = 0;

    for (int i = 0; i < length; i++) {
        checksum ^= data[i];
    }

    // One's complement checksum
    checksum = ~checksum;

    return checksum;
}

// Function to print hexadecimal data with checksum
void print_data_with_checksum(const char *title, uint8_t *data, uint16_t length) {
    printf("%s: ", title);

    for (int i = 0; i < length; i++) {
        if (i > 0 && i % 16 == 0) {
            printf("\n    ");
        }

        printf("%.2X ", data[i]);
    }

    printf("\nChecksum: %.2X\n", calc_checksum(data, length));
}

int main() {
    char buffer[BUFFER_SIZE];
    uint16_t received_data_length = 0;
    uint8_t received_data[BUFFER_SIZE];

    // Initialize serial communication
    // ...

    // Receive data
    fgets(buffer, BUFFER_SIZE, stdin); // Replace with actual serial communication code
    received_data_length = strtol(strtok(buffer, ":"), NULL, 10);

    if (received_data_length > BUFFER_SIZE) {
        fprintf(stderr, "Buffer too small to receive %d bytes\n", received_data_length);
        return 1;
    }

    fgets(buffer, BUFFER_SIZE, stdin); // Replace with actual serial communication code

    sscanf(buffer, "%[^:]:%s", (char *)received_data, (char *)NULL);

    // Convert received data from string to bytes
    for (int i = 0; i < received_data_length; i++) {
        received_data[i] = strtoul(strtok(NULL, " "), NULL, 16);
    }

    print_data_with_checksum("Received data", received_data, received_data_length);

    return 0;
}