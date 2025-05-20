//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>

#define BLOCK_SIZE 1024
#define CHECKSUM_SIZE 4

void calculate_checksum(unsigned char *buffer, size_t length) {
    unsigned int sum = 0;
    for (size_t i = 0; i < length; i++) {
        sum += buffer[i];
    }
    memcpy(buffer + length, &sum, CHECKSUM_SIZE);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct stat file_stat;
    if (stat(argv[1], &file_stat) != 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    void *file_map = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, open(argv[1], O_RDONLY), 0);
    if (file_map == MAP_FAILED) {
        perror("Error mapping file");
        exit(EXIT_FAILURE);
    }

    unsigned char *buffer = file_map;
    size_t file_length = file_stat.st_size;

    calculate_checksum(buffer, file_length);

    size_t checksum_length = CHECKSUM_SIZE;
    unsigned char checksum[CHECKSUM_SIZE];
    memcpy(checksum, buffer + file_length, CHECKSUM_SIZE);

    printf("File Checksum:\n");
    for (size_t i = 0; i < CHECKSUM_SIZE; i++) {
        printf("%02x", checksum[i]);
    }
    printf("\n");

    munmap(file_map, file_stat.st_size);
    close(open(argv[1], O_RDONLY));

    return EXIT_SUCCESS;
}