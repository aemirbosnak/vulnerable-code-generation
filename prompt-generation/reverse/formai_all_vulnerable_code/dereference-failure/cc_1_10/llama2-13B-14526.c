//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFFER_SIZE 1024
#define PID 1234

// Structure to hold the message and the pid of the sender
struct message {
    char *message;
    int pid;
};

// Function to send a message to the parent process
void send_message(char *message) {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, BUFFER_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Write the message to the shared memory segment
    char *shm = shmat(shmid, NULL, 0);
    if (shm == NULL) {
        perror("shmat");
        exit(1);
    }
    strcpy(shm, message);

    // Signal the parent process to read the message
    kill(PID, SIGUSR1);

    // Detach the process to prevent zombies
    if (fork() == 0) {
        // Parent process
        wait(NULL);
    }
}

// Function to read a message from the shared memory segment
char *read_message() {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, BUFFER_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory segment
    char *shm = shmat(shmid, NULL, 0);
    if (shm == NULL) {
        perror("shmat");
        exit(1);
    }

    // Read the message from the shared memory segment
    char *message = shm;

    // Clean up
    shmctl(shmid, IPC_RMID, NULL);

    return message;
}

int main() {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, BUFFER_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Fork a child process
    if (fork() == 0) {
        // Child process
        char *message = "Hello from the child process!";
        send_message(message);
        exit(0);
    }

    // Parent process
    char *message = read_message();
    printf("Received message from the child process: %s\n", message);

    // Clean up
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}