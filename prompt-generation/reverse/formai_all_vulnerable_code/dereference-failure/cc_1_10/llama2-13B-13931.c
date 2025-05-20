//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

#define MESSAGE_SIZE 1024

// Structure to hold the message and the sender's ID
typedef struct {
    char message[MESSAGE_SIZE];
    int sender_id;
} message_t;

// Array to store the shared memory segments
char *shm_segments[10];

// Function to create a shared memory segment
void create_shm_segment(int size) {
    key_t key = IPC_PRIVATE;
    shm_segments[0] = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (shm_segments[0] == MAP_FAILED) {
        perror("mmap() failed");
        exit(EXIT_FAILURE);
    }
}

// Function to send a message to another process
void send_message(int receiver_pid, char *message) {
    // Create a shared memory segment for the message
    create_shm_segment(MESSAGE_SIZE);

    // Write the message to the shared memory segment
    char *shm_ptr = shm_segments[0];
    memcpy(shm_ptr, message, MESSAGE_SIZE);

    // Send the message to the receiver process
    if (shm_ptr == MAP_FAILED) {
        perror("shm_ptr failed");
        exit(EXIT_FAILURE);
    }

    // Wait for the receiver process to read the message
    while (1) {
        waitpid(receiver_pid, NULL, 0);
    }
}

// Function to receive a message from another process
void receive_message(int sender_pid) {
    // Create a shared memory segment for the message
    create_shm_segment(MESSAGE_SIZE);

    // Wait for the sender process to send the message
    while (1) {
        waitpid(sender_pid, NULL, 0);
    }

    // Read the message from the shared memory segment
    char *shm_ptr = shm_segments[0];
    memcpy(shm_ptr, shm_segments[0], MESSAGE_SIZE);
}

int main() {
    // Fork two processes
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() failed");
        exit(EXIT_FAILURE);
    }

    // Parent process
    if (pid == 0) {
        // Create a shared memory segment for the message
        create_shm_segment(MESSAGE_SIZE);

        // Write a message to the shared memory segment
        char message[] = "Hello, child process!";
        send_message(1, message);

        // Wait for the child process to read the message
        waitpid(1, NULL, 0);
    }

    // Child process
    else {
        // Receive the message from the parent process
        receive_message(0);

        // Print the received message
        printf("Received message: %s\n", shm_segments[0]);

        // Exit the child process
        exit(EXIT_SUCCESS);
    }

    return 0;
}