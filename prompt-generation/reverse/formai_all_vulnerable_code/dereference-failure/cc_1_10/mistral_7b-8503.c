//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define FILE_NAME "example.txt"

typedef struct {
    int magic_number;
    char data[BUFFER_SIZE];
} my_struct;

void print_file_invasively(char *filename) {
    int fd;
    struct stat file_stat;
    void *mmap_address;
    my_struct *my_data;

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (fstat(fd, &file_stat) < 0) {
        perror("Error getting file size");
        exit(EXIT_FAILURE);
    }

    mmap_address = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mmap_address == MAP_FAILED) {
        perror("Error memory mapping file");
        exit(EXIT_FAILURE);
    }

    my_data = (my_struct *) mmap_address;

    printf("Magic number: %d\n", my_data->magic_number);

    write(STDOUT_FILENO, my_data->data, file_stat.st_size - sizeof(my_struct));

    munmap(mmap_address, file_stat.st_size);
    close(fd);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    print_file_invasively(argv[1]);

    return EXIT_SUCCESS;
}