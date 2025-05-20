//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BLOCK_SIZE 1024
#define CHECKSUM_SIZE 4

void checksum(unsigned char *buffer, size_t size) {
    unsigned int sum = 0xFFFF;
    size_t i;
    for (i = 0; i < size; i++) {
        sum += buffer[i];
        if (sum & 0x8000)
            sum ^= 0xFFFF;
    }
    memcpy(buffer + size, &sum, CHECKSUM_SIZE);
}

int main(int argc, char **argv) {
    int fd;
    struct stat file_stat;
    unsigned char *buffer;
    size_t file_size;
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    fstat(fd, &file_stat);
    file_size = file_stat.st_size;

    buffer = malloc(file_size + CHECKSUM_SIZE);
    read(fd, buffer, file_size);
    close(fd);

    checksum(buffer, file_size);

    printf("Checksum for '%s':\n", argv[1]);
    for (int i = file_size; i < file_size + CHECKSUM_SIZE; i++) {
        printf("%02X", buffer[i]);
    }
    printf("\n");

    free(buffer);
    return 0;
}