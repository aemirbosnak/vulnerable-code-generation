//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define BUFFER_SIZE 1024

int main() {
    // Create a shared memory segment
    int shmid = shmget(IPC_PRIVATE, BUFFER_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget() failed");
        return 1;
    }

    // Attach to the shared memory segment
    void *mem = shmat(shmid, NULL, 0);
    if (mem == (void *) -1) {
        perror("shmat() failed");
        return 1;
    }

    // Write a message to the shared memory
    char *message = "Hello from the parent process!";
    strcpy(mem, message);

    // Create a new process
    pid_t pid = fork();
    if (pid == 0) {
        // In the child process, read the message from the shared memory
        char *read_message = mem;
        printf("Received message: %s\n", read_message);

        // Create a new shared memory segment
        shmid = shmget(IPC_PRIVATE, BUFFER_SIZE, IPC_CREAT | 0644);
        if (shmid == -1) {
            perror("shmget() failed");
            return 1;
        }

        // Attach to the new shared memory segment
        void *new_mem = shmat(shmid, NULL, 0);
        if (new_mem == (void *) -1) {
            perror("shmat() failed");
            return 1;
        }

        // Overwrite the message in the new shared memory segment
        char *new_message = "Hello from the child process!";
        strcpy(new_mem, new_message);

        // Exit the child process
        exit(0);
    } else {
        // In the parent process, wait for the child process to finish
        wait(NULL);
    }

    // Remove the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}