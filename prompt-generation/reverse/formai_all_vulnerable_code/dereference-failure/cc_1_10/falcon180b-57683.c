//Falcon-180B DATASET v1.0 Category: System administration ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void read_file(int fd, char *filename) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    printf("Reading file %s:\n", filename);
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        buffer[bytes_read - 1] = '\0';
        printf("%s", buffer);
    }
    if (bytes_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
}

void write_file(int fd, char *filename) {
    char buffer[BUFFER_SIZE];
    int bytes_written;

    printf("Writing to file %s:\n", filename);
    while (fgets(buffer, BUFFER_SIZE, stdin)!= NULL) {
        if (strlen(buffer) == 0 || buffer[0] == '\n') {
            continue;
        }
        bytes_written = write(fd, buffer, strlen(buffer));
        if (bytes_written == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char *argv[]) {
    int fd;
    char mode[3];

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s [r|w] filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    strcpy(mode, argv[1]);
    strcat(mode, "b");

    if ((fd = open(argv[3], mode, 0644)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "r") == 0) {
        read_file(fd, argv[3]);
    } else if (strcmp(argv[1], "w") == 0) {
        write_file(fd, argv[3]);
    } else {
        fprintf(stderr, "Invalid mode\n");
        exit(EXIT_FAILURE);
    }

    close(fd);
    return EXIT_SUCCESS;
}