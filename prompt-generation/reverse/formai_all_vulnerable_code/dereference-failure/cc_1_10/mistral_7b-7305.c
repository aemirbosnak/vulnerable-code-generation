//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define FILE_MAGIC "HappyFile"
#define BLOCK_SIZE 512
#define MAX_FILES 10

typedef struct {
    char name[32];
    off_t size;
    off_t start;
    char magic[8];
} FileHeader;

typedef struct {
    FileHeader files[MAX_FILES];
    char data[BLOCK_SIZE * (MAX_FILES + 1)];
} HappyDisk;

void print_header(const FileHeader *header) {
    printf("%s: size = %lld, start = %lld\n", header->name, header->size, header->start);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <corrupted file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    HappyDisk *happy_disk = mmap(NULL, sizeof(HappyDisk), PROT_READ, MAP_PRIVATE, fd, 0);
    if (happy_disk == MAP_FAILED) {
        perror("Error mapping file to memory");
        close(fd);
        return 1;
    }

    printf("*********************************\n");
    printf("* Welcome to the Happy Recovery! *\n");
    printf("*********************************\n");

    int num_files = 0;
    for (int i = 0; i < MAX_FILES; i++) {
        FileHeader *header = &happy_disk->files[i];
        if (strncmp(header->magic, FILE_MAGIC, 8) == 0) {
            num_files++;
            print_header(header);
        }
    }

    if (num_files == 0) {
        printf("No valid files found!\n");
    } else {
        printf("Found %d valid files!\n", num_files);
    }

    munmap(happy_disk, sizeof(HappyDisk));
    close(fd);

    return 0;
}