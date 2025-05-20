//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUF_SIZE 1024

struct file_header {
    char magic[4];
    int file_size;
    char file_name[28];
};

void read_file(int fd, char *buffer) {
    int bytes_read = 0;
    while ((bytes_read = read(fd, buffer, BUF_SIZE)) > 0) {
        buffer += bytes_read;
    }
}

int is_valid_header(struct file_header *header) {
    return (strcmp(header->magic, "FILE") == 0 && header->file_size > 0);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: Failed to open file '%s'\n", argv[1]);
        exit(1);
    }

    struct stat statbuf;
    if (fstat(fd, &statbuf) == -1) {
        fprintf(stderr, "Error: Failed to get file status\n");
        exit(1);
    }

    char buffer[statbuf.st_size];
    read_file(fd, buffer);

    struct file_header *header = (struct file_header *)buffer;
    if (!is_valid_header(header)) {
        fprintf(stderr, "Error: Invalid file header\n");
        exit(1);
    }

    int file_size = header->file_size;
    char file_name[header->file_size + 1];
    strncpy(file_name, header->file_name, header->file_size);
    file_name[header->file_size] = '\0';

    printf("File name: %s\n", file_name);
    printf("File size: %d bytes\n", file_size);

    close(fd);
    return 0;
}