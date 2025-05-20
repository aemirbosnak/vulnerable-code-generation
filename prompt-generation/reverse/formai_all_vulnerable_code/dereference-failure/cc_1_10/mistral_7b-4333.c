//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BLOCK_SIZE 65536

typedef struct {
    unsigned char data[BLOCK_SIZE];
    unsigned int checksum;
} block_t;

void calculate_checksum(block_t *block) {
    unsigned int sum = 0;
    int i;

    for (i = 0; i < BLOCK_SIZE; i++) {
        sum += block->data[i];
        if (sum & 0x80000000) {
            sum -= 0x10000000;
        }
    }

    block->checksum = sum;
}

int main(int argc, char *argv[]) {
    FILE *input_file;
    block_t *current_block = calloc(1, sizeof(block_t));
    unsigned char buffer[BLOCK_SIZE];
    unsigned int total_checksum = 0;
    size_t bytes_read;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "rb");

    if (!input_file) {
        perror("Error opening file");
        free(current_block);
        return 1;
    }

    while ((bytes_read = fread(buffer, 1, BLOCK_SIZE, input_file)) > 0) {
        memcpy(current_block->data, buffer, bytes_read);
        calculate_checksum(current_block);
        total_checksum += current_block->checksum;
    }

    fclose(input_file);
    free(current_block);

    printf("Checksum: %x\n", total_checksum);

    return 0;
}