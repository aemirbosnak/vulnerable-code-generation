//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define FIFO_NAME "mypipe"
#define BUFFER_SIZE 100

int main() {
    // Writer process
    int write_fd;
    char buffer[BUFFER_SIZE];

    // Create a named pipe (FIFO)
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("Failed to create FIFO");
        exit(EXIT_FAILURE);
    }

    // Open the FIFO for writing
    write_fd = open(FIFO_NAME, O_WRONLY);
    if (write_fd == -1) {
        perror("Failed to open FIFO for writing");
        exit(EXIT_FAILURE);
    }

    // Send messages to the pipe
    for (int i = 0; i < 5; i++) {
        snprintf(buffer, BUFFER_SIZE, "Message %d from Writer", i + 1);
        write(write_fd, buffer, strlen(buffer) + 1); // +1 for the null terminator
        printf("Writer sent: %s\n", buffer);
        sleep(1); // Sleep for a second before sending the next message
    }

    // Close the write end
    close(write_fd);

    // Reader process
    int read_fd;
    
    // Open the FIFO for reading
    read_fd = open(FIFO_NAME, O_RDONLY);
    if (read_fd == -1) {
        perror("Failed to open FIFO for reading");
        exit(EXIT_FAILURE);
    }

    // Read messages from the pipe
    for (int i = 0; i < 5; i++) {
        memset(buffer, 0, BUFFER_SIZE); // Clear the buffer
        read(read_fd, buffer, BUFFER_SIZE);
        printf("Reader received: %s\n", buffer);
    }

    // Close the read end
    close(read_fd);
    
    // Remove the FIFO
    if (unlink(FIFO_NAME) == -1) {
        perror("Failed to remove FIFO");
        exit(EXIT_FAILURE);
    }

    return 0;
}