//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 65536
#define CHECKSUM_SIZE 4

typedef struct {
    unsigned char data[BLOCK_SIZE];
    unsigned short checksum;
} Block;

void calculate_checksum(unsigned short *checksum, const unsigned char *data, size_t length) {
    *checksum = 0;
    for (size_t i = 0; i < length; ++i) {
        *checksum = ( (*checksum) << 1 ) ^ (*((unsigned char *) checksum) ^ data[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Error opening file");
        return 1;
    }

    Block block;
    size_t bytes_read;
    unsigned short checksum = 0;

    while ((bytes_read = fread(block.data, 1, sizeof(block.data), input_file)) > 0) {
        calculate_checksum(&checksum, block.data, bytes_read);

        // Display some post-apocalyptic messages while calculating checksum
        printf("\nRadiation levels rising...\n");
        fflush(stdout);
        for (size_t i = 0; i < bytes_read; ++i) {
            if ((i % 1024) == 0) {
                printf("Calculating checksum for block %zu of %zu...\n", i / 1024, bytes_read / 1024);
                fflush(stdout);
            }
        }
    }

    if (feof(input_file)) {
        printf("\nChecksum calculated successfully.\n");
        printf("Checksum: %04x\n", checksum);
    } else {
        perror("Error reading file");
        return 1;
    }

    fclose(input_file);

    return 0;
}