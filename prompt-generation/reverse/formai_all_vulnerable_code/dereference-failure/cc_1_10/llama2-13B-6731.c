//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <semaphore.h>

#define BUFFER_SIZE 1024

// Structure to hold the message to be sent
struct message {
    char *data;
    size_t length;
};

// Semaphore to synchronize communication between processes
sem_t sem;

// Array to store the messages to be sent
struct message messages[5];

// Function to send a message to the other process
void send_message(int pid, char *data, size_t length) {
    // Create a new message structure
    struct message message;
    message.data = data;
    message.length = length;

    // Write the message to a shared memory segment
    char *shm = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, -1, 0);
    if (shm == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }
    memcpy(shm, &message, sizeof(message));

    // Signal the other process to read the message
    sem_post(&sem);
}

// Function to receive a message from the other process
void receive_message(int pid) {
    // Wait for a message to be available
    sem_wait(&sem);

    // Read the message from the shared memory segment
    char *shm = mmap(NULL, BUFFER_SIZE, PROT_READ, MAP_SHARED, -1, 0);
    if (shm == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }
    struct message *message = (struct message *)shm;

    // Print the received message
    printf("Received message from process %d: %s\n", message->length, message->data);

    // Unmap the shared memory segment
    munmap(shm, BUFFER_SIZE);
}

int main(int argc, char *argv[]) {
    // Initialize the semaphore
    sem_init(&sem, 0, 1);

    // Create a new process to send messages
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        for (int i = 0; i < 5; i++) {
            // Create a new message structure
            struct message message;
            message.data = "Hello, world!";
            message.length = strlen(message.data);

            // Send the message to the other process
            send_message(1, message.data, message.length);
        }
        exit(0);
    } else {
        // Parent process
        for (int i = 0; i < 5; i++) {
            // Receive a message from the other process
            receive_message(1);
        }
        exit(0);
    }

    return 0;
}