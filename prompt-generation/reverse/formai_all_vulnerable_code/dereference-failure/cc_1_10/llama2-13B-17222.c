//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MESSAGE_BUFFER_SIZE 1024

// Structure to hold the message to be sent
typedef struct {
    char *message;
    size_t length;
} message_t;

// Function to send a message to another process
void send_message(int shmid, message_t *message) {
    // Create a shared memory segment
    int shm = shmget(shmid, MESSAGE_BUFFER_SIZE, IPC_CREAT | 0666);
    if (shm == -1) {
        perror("shmget");
        return;
    }

    // Attach the shared memory segment to the current process
    void *addr = shmat(shm, NULL, 0);
    if (addr == (void *)-1) {
        perror("shmat");
        return;
    }

    // Copy the message to the shared memory segment
    memcpy(addr, message, sizeof(message_t));

    // Detach the shared memory segment from the current process
    if (shmdt(addr) == -1) {
        perror("shmdt");
    }
}

// Function to receive a message from another process
void receive_message(int shmid, message_t *message) {
    // Create a shared memory segment
    int shm = shmget(shmid, MESSAGE_BUFFER_SIZE, IPC_CREAT | 0666);
    if (shm == -1) {
        perror("shmget");
        return;
    }

    // Attach the shared memory segment to the current process
    void *addr = shmat(shm, NULL, 0);
    if (addr == (void *)-1) {
        perror("shmat");
        return;
    }

    // Read the message from the shared memory segment
    memcpy(message, addr, sizeof(message_t));

    // Detach the shared memory segment from the current process
    if (shmdt(addr) == -1) {
        perror("shmdt");
    }
}

int main() {
    // Create a shared memory segment for messages
    int shmid = shmget(IPC_PRIVATE, MESSAGE_BUFFER_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Create a message to be sent
    message_t message = {
        .message = "Greetings, brave knight!",
        .length = strlen("Greetings, brave knight!")
    };

    // Send the message to another process
    send_message(shmid, &message);

    // Receive the message from another process
    message_t received_message;
    receive_message(shmid, &received_message);

    // Print the received message
    printf("Received message: %s\n", received_message.message);

    return 0;
}