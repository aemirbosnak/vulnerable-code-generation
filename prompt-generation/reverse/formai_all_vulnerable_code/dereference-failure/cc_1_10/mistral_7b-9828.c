//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE 512

// Adler-32 checksum function
uint32_t adler32(const uint8_t *buf, size_t len) {
    uint32_t checksum = 1, sum1 = 1, sum2 = 0;

    while (len--) {
        sum1 = (sum1 + *buf++) % 65521;
        sum2 = (sum2 + sum1) % 65521;
    }

    checksum = sum1 << 16 | sum2;

    return checksum;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[BLOCK_SIZE];
    size_t bytes_read;
    uint32_t checksum;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");

    if (!file) {
        perror("Error opening file");
        return 1;
    }

    checksum = 1;

    while ((bytes_read = fread(buffer, sizeof(char), BLOCK_SIZE, file)) > 0) {
        checksum = adler32(buffer, bytes_read);
    }

    if (ferror(file)) {
        perror("Error reading file");
        return 1;
    }

    fclose(file);

    printf("Checksum for %s: 0x%08x\n", argv[1], checksum);

    return 0;
}