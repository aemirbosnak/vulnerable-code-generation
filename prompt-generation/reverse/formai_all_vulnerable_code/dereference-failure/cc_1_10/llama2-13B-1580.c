//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10
#define MAX_BUFFER_SIZE 1024 * 1024

typedef struct {
    char *filename;
    int file_size;
    int buffer_size;
} file_info_t;

file_info_t *get_file_info(const char *filename) {
    file_info_t *fi = malloc(sizeof(file_info_t));
    fi->filename = filename;
    fi->file_size = 0;
    fi->buffer_size = 0;

    if (access(filename, F_OK) != 0) {
        perror("Error: File not found");
        return NULL;
    }

    struct stat file_stat;
    stat(filename, &file_stat);
    fi->file_size = file_stat.st_size;

    if (fi->file_size > MAX_FILE_SIZE) {
        fprintf(stderr, "Error: File size exceeds maximum limit (%d MB)\n", fi->file_size / 1024 / 1024);
        return NULL;
    }

    if (fi->file_size > MAX_BUFFER_SIZE) {
        fi->buffer_size = MAX_BUFFER_SIZE;
    } else {
        fi->buffer_size = fi->file_size / 10;
    }

    return fi;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: Insufficient arguments\n");
        return 1;
    }

    file_info_t *fi = get_file_info(argv[1]);
    if (fi == NULL) {
        return 1;
    }

    char *buffer = malloc(fi->buffer_size);
    if (buffer == NULL) {
        perror("Error: Memory allocation failed");
        return 1;
    }

    int fd = open(fi->filename, O_RDONLY, 0666);
    if (fd == -1) {
        perror("Error: Open file failed");
        return 1;
    }

    // mmap the file into memory
    void *mapped_addr = mmap(NULL, fi->file_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (mapped_addr == MAP_FAILED) {
        perror("Error: mmap failed");
        return 1;
    }

    // read from the file
    int bytes_read = read(fd, buffer, fi->buffer_size);
    if (bytes_read == -1) {
        perror("Error: Read failed");
        return 1;
    }

    // check if the read operation was successful
    if (bytes_read < fi->buffer_size) {
        fprintf(stderr, "Error: Partial read\n");
        return 1;
    }

    // print the contents of the file
    printf("File contents: %s\n", buffer);

    // unmap the file from memory
    munmap(mapped_addr, fi->file_size);

    close(fd);
    free(buffer);

    return 0;
}