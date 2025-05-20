//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

void error_handling(char *message);

int main() {
    int fd1, fd2;
    char *buffer1, *buffer2;
    int bytes_read;
    int bytes_written;

    fd1 = open("pipe1", O_RDWR);
    if (fd1 == -1) {
        error_handling("Error opening pipe1\n");
    }

    fd2 = open("pipe2", O_RDWR);
    if (fd2 == -1) {
        error_handling("Error opening pipe2\n");
    }

    buffer1 = (char *) malloc(BUFFER_SIZE * sizeof(char));
    buffer2 = (char *) malloc(BUFFER_SIZE * sizeof(char));

    if (buffer1 == NULL || buffer2 == NULL) {
        error_handling("Memory error\n");
    }

    bytes_read = read(fd1, buffer1, BUFFER_SIZE);
    if (bytes_read == -1) {
        error_handling("Error reading from pipe1\n");
    }

    buffer1[bytes_read] = '\0';
    printf("Received message from pipe1: %s\n", buffer1);

    memset(buffer2, 0, BUFFER_SIZE);
    strcat(buffer2, "Hello from pipe2\n");

    bytes_written = write(fd2, buffer2, strlen(buffer2));
    if (bytes_written == -1) {
        error_handling("Error writing to pipe2\n");
    }

    close(fd1);
    close(fd2);

    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(1);
}