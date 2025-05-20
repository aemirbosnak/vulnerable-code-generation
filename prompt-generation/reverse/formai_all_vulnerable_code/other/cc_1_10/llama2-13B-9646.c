//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MESSAGE_BUFFER_SIZE 1024

// Structure to store message data
typedef struct {
    char *message;
    int message_length;
} message_t;

// Function to send message to other process
void send_message(int shmid, char *message) {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shm = shmget(key, MESSAGE_BUFFER_SIZE, IPC_CREAT | 0644);

    // Check if shared memory segment creation was successful
    if (shm == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach shared memory segment to this process
    if (shmat(shm, NULL, 0) == -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Write message to shared memory segment
    message_t *message_ptr = (message_t *)shmat;
    message_ptr->message = message;
    message_ptr->message_length = strlen(message);

    // Detach shared memory segment from this process
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }
}

// Function to receive message from other process
void receive_message(int shmid) {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shm = shmget(key, MESSAGE_BUFFER_SIZE, IPC_CREAT | 0644);

    // Check if shared memory segment creation was successful
    if (shm == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach shared memory segment to this process
    if (shmat(shm, NULL, 0) == -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Read message from shared memory segment
    message_t *message_ptr = (message_t *)shmat;
    char *message = message_ptr->message;
    int message_length = message_ptr->message_length;

    // Print received message
    printf("Received message: %s\n", message);

    // Detach shared memory segment from this process
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shm = shmget(key, MESSAGE_BUFFER_SIZE, IPC_CREAT | 0644);

    // Check if shared memory segment creation was successful
    if (shm == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach shared memory segment to this process
    if (shmat(shm, NULL, 0) == -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Create a pipe for communication
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a new process to send message
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        char message[] = "Hello from child process!";
        send_message(shm, message);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        receive_message(shm);
    }

    return 0;
}