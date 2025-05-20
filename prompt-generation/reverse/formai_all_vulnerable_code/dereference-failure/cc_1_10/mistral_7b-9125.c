//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024
#define MAX_FILE_SIZE 1048576

typedef struct {
    int magic;
    char data[BUFFER_SIZE];
} FileHeader;

int main(int argc, char *argv[]) {
    int fd, ret;
    char *map_base;
    FileHeader *header;
    char *input_file, *output_file;

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    input_file = argv[1];
    output_file = argv[2];

    fd = open(input_file, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open input file");
        exit(1);
    }

    struct stat file_stat;
    fstat(fd, &file_stat);

    if (file_stat.st_size > MAX_FILE_SIZE) {
        printf("Input file is too large\n");
        exit(1);
    }

    map_base = mmap(NULL, file_stat.st_size + sizeof(FileHeader), PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (map_base == MAP_FAILED) {
        perror("Failed to mmap input file");
        close(fd);
        exit(1);
    }

    header = (FileHeader *)map_base;
    header->magic = 0x12345678;

    ret = read(fd, header->data, file_stat.st_size);
    if (ret != file_stat.st_size) {
        perror("Failed to read input file");
        munmap(map_base, file_stat.st_size + sizeof(FileHeader));
        close(fd);
        exit(1);
    }

    close(fd);

    fd = open(output_file, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Failed to open output file for writing");
        munmap(map_base, file_stat.st_size + sizeof(FileHeader));
        exit(1);
    }

    write(fd, header, sizeof(FileHeader));
    write(fd, header->data, file_stat.st_size);

    munmap(map_base, file_stat.st_size + sizeof(FileHeader));
    close(fd);

    return 0;
}