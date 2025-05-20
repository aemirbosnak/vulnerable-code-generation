//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

#define MSG_SIZE 1024
#define SHM_SIZE 4096

// Structure to hold message data
typedef struct {
    char message[MSG_SIZE];
} message_t;

// Function to send message from parent to child
void send_message(int shmidx, char *message) {
    // Create a shared memory segment
    int shm = shmget(shmidx, SHM_SIZE, IPC_CREAT | 0644);
    if (shm == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Write message to shared memory
    char *shmp = shmat(shm, NULL, 0);
    if (shmp == (char *)(-1)) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    strcpy(shmp, message);

    // Wake up child process
    kill(getppid(), SIGUSR1);
}

// Function to receive message from child
void recv_message(int shmidx) {
    // Create a shared memory segment
    int shm = shmget(shmidx, SHM_SIZE, IPC_CREAT | 0644);
    if (shm == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Read message from shared memory
    char *shmp = shmat(shm, NULL, 0);
    if (shmp == (char *)(-1)) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Print received message
    printf("Received message: %s\n", shmp);

    // Clean up shared memory
    shmctl(shm, IPC_RMID, 0);
}

int main(void) {
    // Create a shared memory segment for message passing
    int shmidx = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0644);
    if (shmidx == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // In child process, receive message from parent
    if (pid > 0) {
        recv_message(shmidx);
    } else {
        // In parent process, send message to child
        send_message(shmidx, "Hello from parent!");

        // Wait for child to finish
        wait(NULL);
    }

    return 0;
}