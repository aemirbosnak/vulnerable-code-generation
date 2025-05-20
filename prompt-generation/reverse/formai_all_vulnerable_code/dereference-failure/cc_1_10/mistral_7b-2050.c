//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define FIFO_NAME "myfifo"

void writer(const char *message) {
    int fd;

    if ((mkfifo(FIFO_NAME, 0666)) < 0 && errno != EEXIST) {
        perror("Error creating named pipe");
        exit(EXIT_FAILURE);
    }

    if ((fd = open(FIFO_NAME, O_WRONLY)) < 0) {
        perror("Error opening named pipe for writing");
        exit(EXIT_FAILURE);
    }

    if (write(fd, message, strlen(message)) < 0) {
        perror("Error writing to named pipe");
        exit(EXIT_FAILURE);
    }

    printf("Writer: Message '%s' sent to reader\n", message);
    close(fd);
}

void reader() {
    char buffer[100];
    int fd;

    if ((fd = open(FIFO_NAME, O_RDONLY)) < 0) {
        perror("Error opening named pipe for reading");
        exit(EXIT_FAILURE);
    }

    if (read(fd, buffer, sizeof(buffer)) < 0) {
        perror("Error reading from named pipe");
        exit(EXIT_FAILURE);
    }

    printf("Reader: Message '%s' received from writer\n", buffer);
    close(fd);

    unlink(FIFO_NAME);
}

int main() {
    pid_t pid;

    if ((pid = fork()) < 0) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process: reader
        reader();
        exit(EXIT_SUCCESS);
    }

    if (pid > 0) { // Parent process: writer
        writer("Hello, World!");
        wait(NULL);
        exit(EXIT_SUCCESS);
    }

    perror("Error forking process");
    exit(EXIT_FAILURE);
}