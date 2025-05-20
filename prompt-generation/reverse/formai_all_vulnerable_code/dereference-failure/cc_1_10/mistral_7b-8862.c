//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define FIFO_NAME "myfifo"

int main() {
    int fd1, fd2, ret;
    char buf[100];
    pid_t pid;

    // Create a named pipe (FIFO) for inter-process communication
    if (mkfifo(FIFO_NAME, 0666) == -1 && errno != EEXIST) {
        perror("Error creating FIFO");
        exit(EXIT_FAILURE);
    }

    // Open read end of the FIFO for the parent process
    if ((fd1 = open(FIFO_NAME, O_RDONLY)) == -1) {
        perror("Error opening FIFO for reading");
        exit(EXIT_FAILURE);
    }

    // Fork a new process to write to the FIFO
    if ((pid = fork()) < 0) {
        perror("Error forking");
        exit(EXIT_FAILURE);
    }

    // Child process writes to the FIFO
    if (pid == 0) {
        char message[] = "Hello from child!";

        // Open write end of the FIFO
        if ((fd2 = open(FIFO_NAME, O_WRONLY)) == -1) {
            perror("Error opening FIFO for writing");
            exit(EXIT_FAILURE);
        }

        // Write message to the FIFO
        ret = write(fd2, message, strlen(message) + 1);
        if (ret < 0) {
            perror("Error writing to FIFO");
            exit(EXIT_FAILURE);
        }

        close(fd2);
        exit(EXIT_SUCCESS);
    }

    // Parent process reads message from the FIFO
    close(fd1);

    // Open write end of the FIFO to prevent other writes
    if ((fd2 = open(FIFO_NAME, O_WRONLY)) == -1) {
        perror("Error opening FIFO for writing");
        exit(EXIT_FAILURE);
    }

    // Read message from the FIFO
    ret = read(fd2, buf, sizeof(buf));
    if (ret < 0) {
        perror("Error reading from FIFO");
        exit(EXIT_FAILURE);
    }

    printf("Parent received message: %s\n", buf);

    close(fd2);
    wait(NULL);

    unlink(FIFO_NAME);

    return EXIT_SUCCESS;
}