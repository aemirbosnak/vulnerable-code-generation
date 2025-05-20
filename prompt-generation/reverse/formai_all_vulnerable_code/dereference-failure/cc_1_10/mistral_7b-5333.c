//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define CHECKSUM_SIZE 4

unsigned char checksum(unsigned char *data, size_t size) {
    unsigned char sum[CHECKSUM_SIZE] = {0};
    size_t i;

    for (i = 0; i < size; i++) {
        sum[i % CHECKSUM_SIZE] ^= data[i];
    }

    return sum[size % CHECKSUM_SIZE];
}

void print_checksum(unsigned char checksum_byte) {
    printf("Checksum: ");
    for (int i = 0; i < CHECKSUM_SIZE; i++) {
        printf("%02x ", checksum_byte >> (8 * i) & 0xFF);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    struct stat file_stats;
    fstat(fd, &file_stats);
    size_t file_size = file_stats.st_size;

    void *map_base = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map_base == MAP_FAILED) {
        perror("Error mapping file to memory");
        close(fd);
        return 1;
    }

    unsigned char *data = map_base;
    unsigned char checksum_byte = checksum(data, file_size);
    munmap(map_base, file_size);
    close(fd);

    printf("File size: %ld bytes\n", file_size);
    print_checksum(checksum_byte);

    return 0;
}