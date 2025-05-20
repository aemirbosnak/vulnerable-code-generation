//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define BUFFER_SIZE 20
#define NUMBERS_TO_PRODUCE 10

// Function to simulate the producer process
void producer(int write_fd) {
    for (int i = 0; i < NUMBERS_TO_PRODUCE; i++) {
        // Generate a number and convert it to string
        char buffer[BUFFER_SIZE];
        snprintf(buffer, BUFFER_SIZE, "%d", i);

        // Write the number to the pipe
        write(write_fd, buffer, strlen(buffer) + 1);
        printf("Produced: %s\n", buffer);
        
        // Sleep for a while to simulate some processing time
        sleep(1);
    }

    // Send an end-of-message signal
    char end_message[] = "DONE";
    write(write_fd, end_message, strlen(end_message) + 1);
}

// Function to simulate the consumer process
void consumer(int read_fd) {
    char buffer[BUFFER_SIZE];

    while (1) {
        // Read from the pipe
        read(read_fd, buffer, BUFFER_SIZE);
        
        // Check for end of messages
        if (strcmp(buffer, "DONE") == 0) {
            printf("Consumer received all messages. Exiting...\n");
            break;
        }

        // Print the received number
        printf("Consumed: %s\n", buffer);
    }
}

int main() {
    // Create a pipe
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("Pipe failed");
        return EXIT_FAILURE;
    }

    // Fork the process to create producer and consumer
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        return EXIT_FAILURE;
    }

    if (pid > 0) {
        // This is the parent process (Producer)
        close(pipe_fd[0]); // Close the read end of the pipe
        producer(pipe_fd[1]); // Call the producer function
        close(pipe_fd[1]); // Close the write end after producing
        
        // Wait for the consumer to finish
        wait(NULL);
    } else {
        // This is the child process (Consumer)
        close(pipe_fd[1]); // Close the write end of the pipe
        consumer(pipe_fd[0]); // Call the consumer function
        close(pipe_fd[0]); // Close the read end after consuming
    }
    
    return EXIT_SUCCESS;
}