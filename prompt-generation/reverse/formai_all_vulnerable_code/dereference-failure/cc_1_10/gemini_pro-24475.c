//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: irregular
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// A pure C, no-stdlib implementation of the Fletcher-16 checksum algorithm.

// Define the field size in bits. Fletcher-16 uses a 16-bit field.
#define FIELD_SIZE 16

// Define the checksum size in bits. Fletcher-16 uses a 32-bit checksum.
#define CHECKSUM_SIZE 32

// Define the initial checksum value.
#define INITIAL_CHECKSUM 0

// Define the checksum update function.
#define CHECKSUM_UPDATE(chksum, val) \
    do { \
        chksum += val; \
        if (chksum >= (1 << FIELD_SIZE)) { \
            chksum -= (1 << FIELD_SIZE); \
        } \
    } while (0)

// Define the checksum finalize function.
#define CHECKSUM_FINALIZE(chksum) \
    do { \
        chksum = (chksum << (CHECKSUM_SIZE - FIELD_SIZE)) \
               | (chksum >> FIELD_SIZE); \
    } while (0)

// Define the checksum calculation function.
uint32_t checksum(const void *buf, size_t len)
{
    const uint8_t *p = buf;
    uint32_t chksum = INITIAL_CHECKSUM;

    for (size_t i = 0; i < len; i++) {
        CHECKSUM_UPDATE(chksum, p[i]);
    }

    CHECKSUM_FINALIZE(chksum);

    return chksum;
}

// Demonstrate the checksum calculation function.
int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <data>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *data = argv[1];
    size_t len = strlen(data);
    uint32_t chksum = checksum(data, len);

    printf("Checksum: 0x%08x\n", chksum);

    return EXIT_SUCCESS;
}