//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define FIFO_NAME "my_fifo"
#define BUFFER_SIZE 100

void create_fifo() {
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
}

void producer() {
    int fd;
    char buffer[BUFFER_SIZE];

    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 5; i++) {
        snprintf(buffer, BUFFER_SIZE, "Message %d from producer", i);
        if (write(fd, buffer, strlen(buffer) + 1) == -1) {
            perror("write");
            close(fd);
            exit(EXIT_FAILURE);
        }
        printf("Produced: %s\n", buffer);
        sleep(1);  // Simulate some delay
    }

    close(fd);
}

void consumer() {
    int fd;
    char buffer[BUFFER_SIZE];

    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if (read(fd, buffer, BUFFER_SIZE) > 0) {
            printf("Consumed: %s\n", buffer);
        } else {
            break;  // Exit if no more data to read
        }
    }

    close(fd);
}

int main() {
    // Create FIFO
    create_fifo();

    // Fork the processes
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // Parent process: Producer
        producer();
        wait(NULL);  // Wait for child to finish
    } else {
        // Child process: Consumer
        consumer();
    }

    // Clean up FIFO
    if (unlink(FIFO_NAME) == -1) {
        perror("unlink");
        exit(EXIT_FAILURE);
    }

    return 0;
}