//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 4096
#define SHM_KEY 0x12345678

int main(int argc, char *argv[]) {
    key_t key = SHM_KEY;
    int shmid;
    char *shm;
    int status;

    // Create a shared memory segment
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget() failed");
        exit(1);
    }

    // Attach to the shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat() failed");
        exit(1);
    }

    // Write a message to the shared memory
    strcpy(shm, "Hello from process 1!");

    // Fork a new process to read the message
    pid_t pid = fork();
    if (pid == 0) {
        // In the new process, read the message from the shared memory
        char *message = shm;
        printf("Received message: %s\n", message);

        // Exit the new process
        exit(0);
    } else {
        // In the parent process, wait for the new process to finish
        wait(NULL);
    }

    // Remove the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}