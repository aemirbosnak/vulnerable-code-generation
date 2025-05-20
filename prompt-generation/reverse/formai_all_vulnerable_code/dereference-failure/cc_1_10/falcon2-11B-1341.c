//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_NAME_SIZE 256
#define MAX_FILE_SIZE 1048576000 // 1GB

void print_usage() {
    printf("Usage:./data_recovery <filename>\n");
    printf("Recovers data from a corrupted file.\n");
    printf("Filename must be less than %d characters long\n", MAX_FILE_NAME_SIZE);
    printf("File size must be less than %d bytes\n", MAX_FILE_SIZE);
}

void read_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    int size = lseek(fd, 0, SEEK_END);
    if (size == -1) {
        perror("Error seeking end of file");
        exit(1);
    }

    char *buffer = malloc(size + 1);
    if (buffer == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    int bytes_read = read(fd, buffer, size);
    if (bytes_read == -1) {
        perror("Error reading file");
        exit(1);
    }
    buffer[size] = '\0';

    printf("Read %d bytes from %s\n", bytes_read, filename);
    printf("Buffer:\n%s\n", buffer);

    free(buffer);
    close(fd);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        print_usage();
        return 1;
    }

    const char *filename = argv[1];
    if (strlen(filename) > MAX_FILE_NAME_SIZE) {
        printf("Error: filename too long\n");
        return 1;
    }

    if (strlen(filename) > MAX_FILE_SIZE) {
        printf("Error: file size too large\n");
        return 1;
    }

    read_file(filename);

    return 0;
}