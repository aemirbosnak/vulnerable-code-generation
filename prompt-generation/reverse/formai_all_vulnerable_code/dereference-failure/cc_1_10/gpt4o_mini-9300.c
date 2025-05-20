//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_NAME "my_fifo"
#define BUFFER_SIZE 256

// Function prototypes
void create_fifo();
void send_messages();
void receive_messages();

int main() {
    // Create the FIFO
    create_fifo();

    // Fork a new process for sending messages
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process: Send messages
        send_messages();
    } else {
        // Parent process: Receive messages
        receive_messages();
    }

    // Clean up and exit
    unlink(FIFO_NAME);
    return 0;
}

// Function to create a named FIFO
void create_fifo() {
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo failed");
        exit(EXIT_FAILURE);
    }
}

// Function to send messages to the FIFO
void send_messages() {
    int fd;
    char buffer[BUFFER_SIZE];

    // Open the FIFO for writing
    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("Failed to open FIFO for writing");
        exit(EXIT_FAILURE);
    }

    // Sending a series of messages
    for (int i = 0; i < 5; i++) {
        snprintf(buffer, BUFFER_SIZE, "Message %d from sender", i + 1);
        write(fd, buffer, strlen(buffer) + 1);  // Include null terminator
        printf("Sent: %s\n", buffer);
        sleep(1);  // Simulate some delay
    }

    // Close the FIFO
    close(fd);
}

// Function to receive messages from the FIFO
void receive_messages() {
    int fd;
    char buffer[BUFFER_SIZE];

    // Open the FIFO for reading
    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open FIFO for reading");
        exit(EXIT_FAILURE);
    }

    // Receiving messages
    for (int i = 0; i < 5; i++) {
        read(fd, buffer, BUFFER_SIZE); // Read message from FIFO
        printf("Received: %s\n", buffer);
    }

    // Close the FIFO
    close(fd);
}