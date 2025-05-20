//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#define FIFO_NAME "my_fifo"
#define BUFFER_SIZE 100

void create_fifo() {
    // Create a named FIFO (first-in, first-out)
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
}

void writer_process() {
    int fd;
    char buffer[BUFFER_SIZE];

    // Open the FIFO for writing
    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("open (writer)");
        exit(EXIT_FAILURE);
    }

    // Write messages to the FIFO
    for (int i = 1; i <= 5; i++) {
        snprintf(buffer, sizeof(buffer), "Message %d from Writer", i);
        write(fd, buffer, strlen(buffer) + 1); // +1 to include the null terminator
        printf("Writer: Sent: %s\n", buffer);
        sleep(1);
    }

    // Close the FIFO
    close(fd);
}

void reader_process() {
    int fd;
    char buffer[BUFFER_SIZE];

    // Open the FIFO for reading
    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open (reader)");
        exit(EXIT_FAILURE);
    }

    // Read messages from the FIFO
    for (int i = 1; i <= 5; i++) {
        read(fd, buffer, sizeof(buffer));
        printf("Reader: Received: %s\n", buffer);
    }

    // Close the FIFO
    close(fd);
}

int main() {
    // Create the FIFO
    create_fifo();

    // Fork the process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // Parent process acts as the writer
    if (pid > 0) {
        writer_process();
        wait(NULL); // Wait for the child process to finish
    } 
    // Child process acts as the reader
    else {
        sleep(1); // Give the writer a second to create the FIFO
        reader_process();
    }

    // Remove the FIFO
    unlink(FIFO_NAME);

    return 0;
}