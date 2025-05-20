//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

#define BUF_SIZE 1024

void read_data(int fd, char *buffer, int size);
void write_data(int fd, char *buffer, int size);

int main(int argc, char **argv) {
    int fd;
    int size;
    char *filename;
    char *buffer;

    if (argc!= 3) {
        printf("Usage: %s <filename> <size>\n", argv[0]);
        return 1;
    }

    filename = argv[1];
    size = atoi(argv[2]);

    fd = open(filename, O_RDWR);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    buffer = malloc(size);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    read_data(fd, buffer, size);

    printf("Data recovered:\n%s\n", buffer);

    free(buffer);
    close(fd);

    return 0;
}

void read_data(int fd, char *buffer, int size) {
    int bytes_read;

    bytes_read = read(fd, buffer, size);
    if (bytes_read == -1) {
        printf("Error reading file: %s\n", strerror(errno));
        exit(1);
    }

    if (bytes_read == 0) {
        printf("End of file reached\n");
        exit(1);
    }
}

void write_data(int fd, char *buffer, int size) {
    int bytes_written;

    bytes_written = write(fd, buffer, size);
    if (bytes_written == -1) {
        printf("Error writing file: %s\n", strerror(errno));
        exit(1);
    }

    if (bytes_written!= size) {
        printf("Error writing file: Short write\n");
        exit(1);
    }
}