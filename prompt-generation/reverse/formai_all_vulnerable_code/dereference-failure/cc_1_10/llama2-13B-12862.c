//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#define MESSAGE_SIZE 1024

// Structure to store message data
typedef struct {
    char *message;
    size_t length;
} message_t;

// Function to send message to another process
void send_message(int shmid, const char *message, size_t length) {
    // Create a shared memory segment
    int shm = shmget(IPC_PRIVATE, MESSAGE_SIZE, IPC_CREAT | 0666);
    if (shm == -1) {
        perror("shmget() failed");
        return;
    }

    // Write message to shared memory
    char *shm_message = (char *)shmat(shm, NULL, 0);
    memcpy(shm_message, message, length);
    shm_message[length] = '\0';

    // Send signal to other process to read message
    kill(getppid(), SIGUSR1);
}

// Function to receive message from another process
void receive_message(int shmid) {
    // Create a shared memory segment
    int shm = shmget(IPC_PRIVATE, MESSAGE_SIZE, IPC_CREAT | 0666);
    if (shm == -1) {
        perror("shmget() failed");
        return;
    }

    // Read message from shared memory
    char *shm_message = (char *)shmat(shm, NULL, 0);
    size_t length = strlen(shm_message);

    // Print received message
    printf("Received message: %s\n", shm_message);

    // Clean up shared memory
    shmctl(shm, IPC_RMID, 0);
}

int main() {
    // Create a shared memory segment for message
    int shmid = shmget(IPC_PRIVATE, MESSAGE_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget() failed");
        return 1;
    }

    // Fork a child process to receive message
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        receive_message(shmid);
    } else {
        // Parent process
        char message[] = "Hello from parent!";
        send_message(shmid, message, strlen(message));
        wait(NULL);
    }

    return 0;
}