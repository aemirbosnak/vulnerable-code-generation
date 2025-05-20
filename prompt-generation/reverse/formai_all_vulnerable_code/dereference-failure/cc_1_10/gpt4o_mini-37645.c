//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "my_fifo"
#define BUFFER_SIZE 100

void writer() {
    int fd;
    char message[BUFFER_SIZE];
    
    // Open the FIFO for writing
    if ((fd = open(FIFO_NAME, O_WRONLY)) < 0) {
        perror("Open FIFO for writing");
        exit(EXIT_FAILURE);
    }
    
    // Send messages
    for (int i = 0; i < 5; i++) {
        snprintf(message, sizeof(message), "Message %d from writer\n", i + 1);
        write(fd, message, strlen(message) + 1);
        sleep(1);  // Simulate some delay
    }
    
    // Close the FIFO
    close(fd);
    printf("Writer finished sending messages.\n");
}

void reader() {
    int fd;
    char buffer[BUFFER_SIZE];
    
    // Open the FIFO for reading
    if ((fd = open(FIFO_NAME, O_RDONLY)) < 0) {
        perror("Open FIFO for reading");
        exit(EXIT_FAILURE);
    }
    
    // Read messages from the FIFO
    while (1) {
        ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
        if (bytesRead <= 0) {
            break;  // Exit if no bytes are read
        }
        printf("Received: %s", buffer);
    }
    
    // Close the FIFO
    close(fd);
    printf("Reader finished reading messages.\n");
}

int main() {
    // Create the FIFO
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("Creating FIFO");
        exit(EXIT_FAILURE);
    }

    // Fork the process to create a writer and a reader
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    
    if (pid == 0) { 
        // Child process: reader
        reader();
    } else {
        // Parent process: writer
        writer();
        // Wait for the reader to finish
        wait(NULL);
    }
    
    // Remove the FIFO
    unlink(FIFO_NAME);
    return 0;
}