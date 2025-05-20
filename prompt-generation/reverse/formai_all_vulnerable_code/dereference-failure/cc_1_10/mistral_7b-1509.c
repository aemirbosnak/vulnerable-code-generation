//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BLOCK_SIZE 1024
#define CHECKSUM_SIZE 4

typedef struct {
    unsigned char data[BLOCK_SIZE];
    unsigned int sum;
} ChecksumBlock;

void checksum_update(ChecksumBlock *block, unsigned int data) {
    block->sum += data;
    block->sum = (block->sum & 0xFFFFFFFF) + (block->sum >> 32);
}

bool checksum_validate(ChecksumBlock *block, unsigned int expected_checksum) {
    if (block->sum != expected_checksum) {
        printf("CHECKSUM ERROR: Expected 0x%08X, found 0x%08X\n", expected_checksum, block->sum);
        return false;
    }
    return true;
}

void process_file(FILE *file, ChecksumBlock *checksum_block) {
    size_t bytes_read;
    while ((bytes_read = fread(checksum_block->data, 1, BLOCK_SIZE, file))) {
        for (size_t i = 0; i < bytes_read; i++) {
            checksum_update(checksum_block, checksum_block->data[i]);
        }
    }
    if (feof(file)) {
        printf("FILE PROCESSING COMPLETE\n");
        if (checksum_validate(checksum_block, 0)) {
            printf("CHECKSUM VALIDATED!\n");
        } else {
            printf("CHECKSUM FAILED!\n");
            exit(EXIT_FAILURE);
        }
    } else {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    ChecksumBlock checksum_block = { 0 };
    process_file(file, &checksum_block);

    fclose(file);
    return EXIT_SUCCESS;
}