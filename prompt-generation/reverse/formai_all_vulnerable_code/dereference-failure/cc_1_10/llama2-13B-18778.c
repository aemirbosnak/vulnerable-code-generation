//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>

#define MSG_SIZE 1024
#define BUFFER_SIZE 4096

struct message {
    char *data;
    size_t length;
};

int main() {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, BUFFER_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Create a semaphore
    int sem = semget(key, 1, IPC_PRIVATE, 0644);
    if (sem == -1) {
        perror("semget");
        return 1;
    }

    // Create a message buffer
    char *buffer = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (buffer == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Start the curious communication
    while (1) {
        // Wait for a message from the other process
        sem_wait(sem);

        // Receive the message
        struct message *message = (struct message *)buffer;
        printf("Received message from %d: %s\n", message->length, message->data);

        // Process the message
        if (message->length > 0) {
            // Do something with the message
            // ...
        }

        // Send a response message
        char *response = "Hello, world!";
        message->data = response;
        message->length = strlen(response);
        buffer = munmap(buffer, BUFFER_SIZE);
        mprotect(buffer, BUFFER_SIZE, PROT_READ | PROT_WRITE);
        shmdt(buffer);

        // Signal the other process that we have sent a response
        sem_post(sem);
    }

    return 0;
}