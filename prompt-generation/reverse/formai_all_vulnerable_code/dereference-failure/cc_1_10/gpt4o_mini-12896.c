//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE 256
#define MAX_MESSAGES 5

void create_fifo() {
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        if (errno != EEXIST) {
            perror("FIFO creation failed");
            exit(EXIT_FAILURE);
        }
    }
}

void writer() {
    int fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("Writer: Failed to open FIFO");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    for (int i = 0; i < MAX_MESSAGES; i++) {
        snprintf(buffer, sizeof(buffer), "Message %d from Writer\n", i + 1);
        write(fd, buffer, strlen(buffer) + 1);
        printf("Writer: Sent: %s", buffer);
        sleep(1); // Simulate some work with sleep
    }

    close(fd);
}

void reader() {
    char buffer[BUFFER_SIZE];
    int fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("Reader: Failed to open FIFO");
        exit(EXIT_FAILURE);
    }

    while (1) {
        ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
        if (bytesRead > 0) {
            printf("Reader: Received: %s", buffer);
        } else {
            break; // Exit loop on EOF
        }
    }

    close(fd);
}

int main() {
    // Create the FIFO
    create_fifo();

    // Fork two processes: one for writing and one for reading
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process - Reader
        reader();
    } else {
        // Parent process - Writer
        writer();
        // Wait for child process to finish
        wait(NULL);
        // Clean up FIFO after use
        unlink(FIFO_NAME);
    }

    return 0;
}