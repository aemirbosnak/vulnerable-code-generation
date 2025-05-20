//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <stdint.h>

#define BLOCK_SIZE 65536
#define CHUNK_SIZE 4096

typedef struct {
    uint32_t total;
    uint32_t adler;
} adler32;

adler32 calculate_checksum(unsigned char *buffer, size_t size) {
    adler32 checksum = {0, 1};

    while (size > 0) {
        size_t chunk_size = size > CHUNK_SIZE ? CHUNK_SIZE : size;
        size -= chunk_size;

        for (size_t i = 0; i < chunk_size; ++i) {
            uint16_t sum1 = (checksum.adler & 0xFFFF) + buffer[i];
            uint16_t sum2 = sum1 & 0xFFFF;
            sum1 += (sum1 >> 16);
            checksum.adler = (sum1 & 0xFFFF) + (checksum.adler >> 16);
            buffer += chunk_size > BLOCK_SIZE ? BLOCK_SIZE : chunk_size;
        }
    }

    checksum.adler = (checksum.adler & 0xFFFF) + (checksum.total & 0xFFFF);
    checksum.total += size;

    return checksum;
}

int main() {
    srand(time(NULL));

    uint8_t *data = calloc(1, rand() % 1024 * 1024 + 1);

    if (!data) {
        perror("calloc");
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < rand() % 1024 * 1024; ++i) {
        data[i] = rand() % 256;
    }

    adler32 checksum = calculate_checksum(data, rand() % 1024 * 1024);

    printf("Checksum calculation:\n");
    printf("Total bytes processed: %u\n", checksum.total);
    printf("Adler-32 checksum: %08x%08x\n", checksum.adler >> 16, checksum.adler & 0xFFFF);

    free(data);

    return EXIT_SUCCESS;
}