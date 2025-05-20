//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MESSAGE_QUEUE_SIZE 1024

typedef struct message {
    int type;
    char data[1024];
} message_t;

int main() {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    size_t size = sizeof(message_t) * MESSAGE_QUEUE_SIZE;
    int shmid = shmget(key, size, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget() failed");
        return 1;
    }

    // Attach to the shared memory segment
    void *addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (addr == MAP_FAILED) {
        perror("mmap() failed");
        return 1;
    }

    // Create a message queue in the shared memory
    message_t *queue = (message_t *)addr;
    for (int i = 0; i < MESSAGE_QUEUE_SIZE; i++) {
        queue[i].type = 0; // Initialize all messages as empty
    }

    // Start the communication loop
    while (1) {
        // Wait for a message to arrive
        while (queue->type == 0) {
            usleep(1000); // Wait for 1 second
        }

        // Process the message
        switch (queue->type) {
            case 1:
                printf("Received message: %s\n", queue->data);
                break;
            case 2:
                printf("Received message: %d\n", atoi(queue->data));
                break;
            default:
                printf("Received unknown message: %d\n", queue->type);
                break;
        }

        // Clear the message
        queue->type = 0;
    }

    // Exit the program
    munmap(addr, size);
    shmctl(shmid, IPC_RMID, 0);
    return 0;
}