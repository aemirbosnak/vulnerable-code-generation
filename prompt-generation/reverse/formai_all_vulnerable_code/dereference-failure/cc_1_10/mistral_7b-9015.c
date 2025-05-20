//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define BLOCK_SIZE 4096
#define CHECKSUM_SIZE 4

typedef struct {
    uint32_t sum;
    uint8_t pad[CHECKSUM_SIZE];
} Checksum;

void checksum_file(const char *filename) {
    int fd;
    void *map_base;
    size_t filesize;
    Checksum cs;
    char buffer[BLOCK_SIZE];

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(fileno(fd), 0, SEEK_END);
    filesize = ftell(fileno(fd));
    fseek(fileno(fd), 0, SEEK_SET);

    map_base = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map_base == MAP_FAILED) {
        perror("Error mapping file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    cs.sum = 0;
    while (filesize > BLOCK_SIZE) {
        memcpy(buffer, map_base, BLOCK_SIZE);
        cs.sum += *(uint32_t *)buffer;
        map_base += BLOCK_SIZE;
        filesize -= BLOCK_SIZE;
    }

    if (filesize > 0) {
        memcpy(buffer, map_base, filesize);
        cs.sum += *(uint32_t *)buffer;
    }

    munmap(map_base, filesize);
    close(fd);

    printf("File '%s' checksum:\n", filename);
    fwrite(&cs, sizeof(Checksum), 1, stdout);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    checksum_file(argv[1]);
    return EXIT_SUCCESS;
}