//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Adler-32 checksum function
uint32_t adler32(const uint8_t *buf, size_t size) {
    uint32_t a = 1, b = 1;

    while (size--) {
        a = (a + *buf++) % 65521;
        b = (b + a) % 65521;
    }

    return (b << 16) | a;
}

// Function to read data from a file
size_t read_file(const char *filename, uint8_t **buffer) {
    FILE *file = fopen(filename, "rb");
    size_t size;

    if (!file) {
        perror("Error opening file");
        return 0;
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    *buffer = malloc(size);
    if (!*buffer) {
        perror("Error allocating memory");
        fclose(file);
        return 0;
    }

    size_t bytes_read = fread(*buffer, 1, size, file);
    fclose(file);

    if (bytes_read != size) {
        perror("Error reading file");
        free(*buffer);
        *buffer = NULL;
        return 0;
    }

    return size;
}

// Function to print the checksum in hexadecimal format
void print_checksum(uint32_t checksum) {
    char hex[8];

    for (int i = 0; i < 4; i++) {
        int byte = (checksum >> (8 * (3 - i))) & 0xFF;
        sprintf(hex + (2 * i), "%02X", byte);
    }

    printf("Checksum: %s\n", hex);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    uint8_t *buffer = NULL;
    size_t size = read_file(argv[1], &buffer);

    if (!size) {
        perror("Error reading file");
        return 1;
    }

    uint32_t checksum = adler32(buffer, size);
    print_checksum(checksum);

    free(buffer);

    return 0;
}