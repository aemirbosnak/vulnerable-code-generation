//Falcon-180B DATASET v1.0 Category: System administration ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s file_name mode\n", argv[0]);
        exit(1);
    }

    int file_fd;
    int mode;

    if (strcmp(argv[2], "r") == 0) {
        mode = O_RDONLY;
    } else if (strcmp(argv[2], "w") == 0) {
        mode = O_WRONLY | O_CREAT | O_TRUNC;
    } else if (strcmp(argv[2], "a") == 0) {
        mode = O_WRONLY | O_CREAT | O_APPEND;
    } else {
        printf("Invalid mode\n");
        exit(1);
    }

    file_fd = open(argv[1], mode);

    if (file_fd == -1) {
        printf("Error opening file\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int bytes_read;

    do {
        bytes_read = read(file_fd, buffer, BUFFER_SIZE);

        if (bytes_read == -1) {
            printf("Error reading file\n");
            exit(1);
        }

        if (bytes_read == 0) {
            break;
        }

        printf("%s", buffer);
    } while (1);

    close(file_fd);

    return 0;
}