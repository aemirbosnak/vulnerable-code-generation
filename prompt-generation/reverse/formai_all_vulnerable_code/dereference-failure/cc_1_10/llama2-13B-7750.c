//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MESSAGE_SIZE 1024
#define SHM_KEY 0xdeadbeef
#define SHM_SIZE 4096

typedef struct {
    char message[MESSAGE_SIZE];
    int length;
} message_t;

int main() {
    key_t key = SHM_KEY;
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Create a shared memory segment
    void *shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Create a message buffer in the shared memory
    message_t *message = (message_t *)shm;

    // Write a message to the shared memory
    strcpy(message->message, "Hello from parent process!");
    message->length = strlen(message->message);

    // Fork a child process and communicate with it using shared memory
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        close(shmid);
        munmap(shm, SHM_SIZE);

        // Read the message from the shared memory
        message_t *message = (message_t *)shm;
        printf("Received message: %s\n", message->message);

        // Write a response to the shared memory
        strcpy(message->message, "Hello from child process!");
        message->length = strlen(message->message);

        // Exit the child process
        exit(0);
    } else {
        // Parent process
        wait(NULL);

        // Read the response from the shared memory
        message_t *message = (message_t *)shm;
        printf("Received response: %s\n", message->message);
    }

    // Clean up
    close(shmid);
    munmap(shm, SHM_SIZE);

    return 0;
}