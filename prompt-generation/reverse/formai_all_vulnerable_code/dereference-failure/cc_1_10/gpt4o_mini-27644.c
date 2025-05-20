//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>

#define BUFFER_SIZE 256

void encode_message(char *message, char *encoded) {
    // Simple encoding: shift characters by 1
    for (int i = 0; message[i] != '\0'; i++) {
        encoded[i] = message[i] + 1;
    }
    encoded[strlen(message)] = '\0'; // Null-terminate the encoded string
}

void decode_message(char *encoded, char *decoded) {
    // Simple decoding: shift characters back by 1
    for (int i = 0; encoded[i] != '\0'; i++) {
        decoded[i] = encoded[i] - 1;
    }
    decoded[strlen(encoded)] = '\0'; // Null-terminate the decoded string
}

int main() {
    int pipe_fd[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];
    char encoded_message[BUFFER_SIZE];
    char decoded_message[BUFFER_SIZE];

    // Create a pipe for communication
    if (pipe(pipe_fd) == -1) {
        perror("Failed to create pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid > 0) { // Parent process
        close(pipe_fd[0]); // Close unused read end

        // Parent sends a message
        const char *message = "Hello, child!";
        encode_message((char *)message, encoded_message);
        write(pipe_fd[1], encoded_message, strlen(encoded_message) + 1);
        printf("Parent sent: %s\n", encoded_message);

        wait(NULL); // Wait for child to finish
        close(pipe_fd[1]); // Close write end
    } else { // Child process
        close(pipe_fd[1]); // Close unused write end

        // Child receives a message
        read(pipe_fd[0], buffer, BUFFER_SIZE);
        decode_message(buffer, decoded_message);
        printf("Child received: %s\n", decoded_message);
        
        // Child sends a reply
        const char *reply = "Hello, parent!";
        encode_message((char *)reply, encoded_message);
        write(pipe_fd[1], encoded_message, strlen(encoded_message) + 1);
        printf("Child sent: %s\n", encoded_message);

        close(pipe_fd[0]); // Close read end
    }

    return 0;
}