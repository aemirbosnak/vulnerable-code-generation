//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define FILE_NAME "shared_file"
#define READ_MODE "r"
#define WRITE_MODE "w"

int main() {
    int fd = -1;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    fd = open(FILE_NAME, WRITE_MODE);
    if (fd == -1) {
        fprintf(stderr, "Error opening file for writing: %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        printf("Enter a message to write to the shared file: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        bytes_written = write(fd, buffer, strlen(buffer));
        if (bytes_written == -1) {
            fprintf(stderr, "Error writing to file: %s\n", strerror(errno));
            exit(1);
        }
        printf("Message written successfully.\n");
    }

    close(fd);

    fd = open(FILE_NAME, READ_MODE);
    if (fd == -1) {
        fprintf(stderr, "Error opening file for reading: %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1) {
            fprintf(stderr, "Error reading from file: %s\n", strerror(errno));
            exit(1);
        }
        buffer[bytes_read] = '\0';
        printf("Message from shared file: %s", buffer);
    }

    close(fd);

    return 0;
}