//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Print usage information and exit.
void usage(const char *progname) {
    fprintf(stderr, "Usage: %s <number>\n", progname);
    fprintf(stderr, "Converts a decimal number to binary.\n");
    exit(1);
}

// Convert a decimal number to binary.
char *to_binary(uint64_t num) {
    // Allocate a buffer for the binary representation.
    char *buf = malloc(65);
    if (buf == NULL) {
        perror("malloc");
        exit(1);
    }

    // Convert the number to binary.
    int i = 64;
    while (num > 0) {
        buf[i--] = (num & 1) + '0';
        num >>= 1;
    }

    buf[64] = '\0';

    // Return the binary representation.
    return buf;
}

// Main function.
int main(int argc, char *argv[]) {
    // Check if the user provided a number.
    if (argc != 2) {
        usage(argv[0]);
    }

    // Convert the user-provided number to a uint64_t.
    char *endptr;
    uint64_t num = strtoull(argv[1], &endptr, 10);
    if (*endptr != '\0') {
        fprintf(stderr, "Invalid number: %s\n", argv[1]);
        usage(argv[0]);
    }

    // Convert the number to binary.
    char *binary = to_binary(num);

    // Print the binary representation.
    printf("%s\n", binary);

    // Free the buffer used to store the binary representation.
    free(binary);

    return 0;
}