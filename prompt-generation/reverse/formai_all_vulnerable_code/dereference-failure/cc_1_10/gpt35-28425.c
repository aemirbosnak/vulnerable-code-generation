//FormAI DATASET v1.0 Category: Interprocess communication ; Style: interoperable
// Interprocess communication example program
// This program demonstrates interprocess communication between two processes, a sender and a receiver, over a shared memory.
// The sender process writes a message to the shared memory and the receiver process reads the message from the shared memory.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024 // shared memory size

struct shared_mem {
    char message[SHM_SIZE];
};

int main() {
    // create shared memory
    key_t key = ftok("shared_mem", 'R');
    int shmid = shmget(key, sizeof(struct shared_mem), 0666 | IPC_CREAT);

    if(shmid == -1) { // check for error
        perror("shmget");
        exit(1);
    }

    struct shared_mem *shmem = (struct shared_mem *)shmat(shmid, NULL, 0);

    if(shmem == (void *)-1) { // check for error
        perror("shmat");
        exit(1);
    }

    // sender process
    if(fork() == 0) {
        char message[SHM_SIZE];
        printf("Enter a message to send: ");
        fgets(message, SHM_SIZE, stdin);

        strncpy(shmem->message, message, SHM_SIZE);
        printf("Message sent: %s\n", shmem->message);

        exit(0);
    }

    // receiver process
    else {
        sleep(1);
        printf("Received message: %s\n", shmem->message);
    }

    // detach shared memory
    if(shmdt(shmem) == -1) {
        perror("shmdt");
        exit(1);
    }

    // delete shared memory
    if(shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}