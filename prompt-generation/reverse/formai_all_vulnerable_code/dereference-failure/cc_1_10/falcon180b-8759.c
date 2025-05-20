//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

typedef struct {
    char data[BUFFER_SIZE];
    int data_size;
} Message;

int main() {
    int fd1, fd2, bytes_read;
    Message msg;

    // Create named pipes
    if (mkfifo("pipe1", 0666) == -1) {
        fprintf(stderr, "Error creating pipe1: %s\n", strerror(errno));
        exit(1);
    }

    if (mkfifo("pipe2", 0666) == -1) {
        fprintf(stderr, "Error creating pipe2: %s\n", strerror(errno));
        exit(1);
    }

    // Open pipes for reading and writing
    fd1 = open("pipe1", O_RDONLY);
    if (fd1 == -1) {
        fprintf(stderr, "Error opening pipe1: %s\n", strerror(errno));
        exit(1);
    }

    fd2 = open("pipe2", O_WRONLY);
    if (fd2 == -1) {
        fprintf(stderr, "Error opening pipe2: %s\n", strerror(errno));
        exit(1);
    }

    // Send message from one process to another
    msg.data_size = strlen("Hello, world!");
    strcpy(msg.data, "Hello, world!");

    if (write(fd2, &msg, sizeof(msg))!= sizeof(msg)) {
        fprintf(stderr, "Error writing to pipe2: %s\n", strerror(errno));
        exit(1);
    }

    // Receive message from another process
    bytes_read = read(fd1, &msg, sizeof(msg));
    if (bytes_read <= 0) {
        fprintf(stderr, "Error reading from pipe1: %s\n", strerror(errno));
        exit(1);
    }

    printf("Received message: %s\n", msg.data);

    close(fd1);
    close(fd2);

    return 0;
}