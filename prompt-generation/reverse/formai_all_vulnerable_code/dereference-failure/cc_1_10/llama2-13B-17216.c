//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024

void *shm_ptr;

int main(int argc, char *argv[]) {
    key_t key = SHM_KEY;
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize the shared memory
    printf("Parent process: Initializing shared memory...\n");
    memset(shm_ptr, 0, SHM_SIZE);

    // Fork a child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        printf("Child process: Hello from child process!\n");

        // Communicate with the parent process using shared memory
        char *msg = "Hello from child process!";
        strcpy(shm_ptr, msg);

        // Wait for the parent process to read the message
        printf("Child process: Waiting for parent process to read message...\n");
        wait(NULL);

        // Print the message received from the parent process
        printf("Child process: Message received from parent process: %s\n", shm_ptr);
    } else {
        // Parent process
        printf("Parent process: Waiting for child process to send message...\n");

        // Read the message sent by the child process
        char *msg = shm_ptr;
        printf("Parent process: Message received from child process: %s\n", msg);
    }

    // Clean up
    printf("Parent process: Cleaning up shared memory...\n");
    shmctl(shmid, IPC_RMID, 0);

    return 0;
}