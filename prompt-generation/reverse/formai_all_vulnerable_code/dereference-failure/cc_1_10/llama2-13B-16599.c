//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>

#define MESSAGE_SIZE 1024

// Structure to hold the message to be sent
struct message {
    char message[MESSAGE_SIZE];
};

// Function to send a message
void send_message(int shmid, char *message) {
    // Create a shared memory segment
    int shm = shmget(IPC_PRIVATE, MESSAGE_SIZE, IPC_CREAT | 0644);
    if (shm == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to the message
    char *shm_ptr = mmap(NULL, MESSAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Fill the message with the desired data
    strcpy(shm_ptr, message);

    // Unlock the shared memory segment
    shmctl(shm, IPC_RMID, 0);
}

// Function to receive a message
void receive_message(int shmid) {
    // Create a shared memory segment
    int shm = shmget(IPC_PRIVATE, MESSAGE_SIZE, IPC_CREAT | 0644);
    if (shm == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to the message
    char *shm_ptr = mmap(NULL, MESSAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Read the message from the shared memory segment
    char message[MESSAGE_SIZE];
    memcpy(message, shm_ptr, MESSAGE_SIZE);

    // Unlock the shared memory segment
    shmctl(shm, IPC_RMID, 0);

    // Print the received message
    printf("Received message: %s\n", message);
}

int main() {
    // Create a shared memory segment for the message
    int shmid = shmget(IPC_PRIVATE, MESSAGE_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Create a message to be sent
    char message[] = "Greetings, brave knight! The map to the golden fleece is in the north, held by Sir Percival.";

    // Send the message to Sir Lancelot
    send_message(shmid, message);

    // Receive the message from Sir Gawain
    receive_message(shmid);

    // Print the received message
    printf("Received message from Sir Gawain: %s\n", message);

    return 0;
}