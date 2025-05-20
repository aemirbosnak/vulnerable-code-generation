//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BLOCK_SIZE 4096

typedef unsigned long long ull;

void adler32(const void *data, size_t length, ull *sum1, ull *sum2);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    struct stat file_stat;
    if (stat(argv[1], &file_stat) == -1) {
        perror("Error reading file stats");
        return 1;
    }

    ull sum1 = 1, sum2 = 0;
    void *buffer = malloc(BLOCK_SIZE);

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        free(buffer);
        return 1;
    }

    while (1) {
        size_t read_bytes = read(fd, buffer, BLOCK_SIZE);
        if (read_bytes <= 0) {
            break;
        }

        adler32(buffer, read_bytes, &sum1, &sum2);
    }

    close(fd);
    free(buffer);

    printf("Checksum: %llx%llx\n", sum1, sum2);

    return 0;
}

void adler32(const void *data, size_t length, ull *sum1, ull *sum2) {
    const unsigned char *buf = data;
    ull bonk = *sum1, bada = *sum2;

    while (length--) {
        bonk = bonk + (*buf++) % 256;
        bada = bada + bonk;
        bonk = (bonk & 0xffffffff) + (bada >> 32);
        bada = bada + (bonk >> 32);
    }

    *sum1 = bonk;
    *sum2 = bada;
}