//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

// Function prototypes
uint16_t cksum16(const void *buf, size_t count);
uint32_t cksum32(const void *buf, size_t count);

// Main function
int main(int argc, char *argv[]) {
    // Check for arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <algorithm> <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get algorithm and file name
    const char *algorithm = argv[1];
    const char *filename = argv[2];

    // Open file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate buffer
    void *buf = malloc(size);
    if (buf == NULL) {
        perror("malloc");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Read file into buffer
    fread(buf, size, 1, fp);
    fclose(fp);

    // Calculate checksum
    uint16_t cksum16_val;
    uint32_t cksum32_val;
    if (strcmp(algorithm, "cksum16") == 0) {
        cksum16_val = cksum16(buf, size);
        printf("Checksum16: %04x\n", cksum16_val);
    } else if (strcmp(algorithm, "cksum32") == 0) {
        cksum32_val = cksum32(buf, size);
        printf("Checksum32: %08x\n", cksum32_val);
    } else {
        fprintf(stderr, "Invalid algorithm: %s\n", algorithm);
        free(buf);
        return EXIT_FAILURE;
    }

    // Free buffer
    free(buf);

    return EXIT_SUCCESS;
}

// Calculate 16-bit checksum
uint16_t cksum16(const void *buf, size_t count) {
    const uint8_t *p = (const uint8_t *)buf;
    uint16_t sum = 0;
    for (size_t i = 0; i < count; i++) {
        sum += p[i];
        if (sum > 0xffff) {
            sum -= 0xffff;
        }
    }
    return sum;
}

// Calculate 32-bit checksum
uint32_t cksum32(const void *buf, size_t count) {
    const uint8_t *p = (const uint8_t *)buf;
    uint32_t sum = 0;
    for (size_t i = 0; i < count; i++) {
        sum += p[i];
        if (sum > 0xffffffff) {
            sum -= 0xffffffff;
        }
    }
    return sum;
}