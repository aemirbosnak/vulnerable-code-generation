//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define MESSAGE_SIZE 1024

// Structure to store message data
typedef struct {
    char message[MESSAGE_SIZE];
} message_t;

// Function to create a shared memory segment
void create_shm(int shmid) {
    // Create a shared memory segment
    int shm = shmget(shmid, MESSAGE_SIZE, IPC_CREAT | 0644);
    if (shm == -1) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to the current process
    void *addr = shmat(shm, NULL, 0);
    if (addr == (void *) -1) {
        perror("shmat() failed");
        exit(EXIT_FAILURE);
    }

    // Set the message data in the shared memory segment
    message_t *msg = addr;
    strcpy(msg->message, "Hello from parent process!");
}

// Function to send a message to a child process
void send_message(int shmid) {
    // Create a message buffer
    char message[MESSAGE_SIZE];
    strcpy(message, "Hello from child process!");

    // Attach the shared memory segment to the current process
    void *addr = shmat(shmid, NULL, 0);
    if (addr == (void *) -1) {
        perror("shmat() failed");
        exit(EXIT_FAILURE);
    }

    // Write the message to the shared memory segment
    message_t *msg = addr;
    strcpy(msg->message, message);

    // Detach the shared memory segment from the current process
    if (shmdt(addr) == -1) {
        perror("shmdt() failed");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Create a shared memory segment for message passing
    int shmid = shmget(IPC_PRIVATE, MESSAGE_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        create_shm(shmid);
        send_message(shmid);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        wait(NULL);
        send_message(shmid);
        exit(EXIT_SUCCESS);
    }

    return 0;
}