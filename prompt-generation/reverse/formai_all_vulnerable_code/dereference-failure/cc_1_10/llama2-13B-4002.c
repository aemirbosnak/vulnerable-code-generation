//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define SHM_KEY 0xdeadbeef
#define SHM_SIZE 1024

int main(int argc, char *argv[]) {
    // Create a shared memory segment
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Attach to the shared memory segment
    char *shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Write a message to the shared memory
    char message[] = "Hello from process 1!";
    strcpy(shm, message);

    // Fork a new process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        char *message = shm;
        printf("Received message: %s\n", message);

        // Modify the shared memory
        message[0] = 'H';
        message[1] = 'e';
        message[2] = 'l';
        message[3] = 'l';
        message[4] = 'o';
        message[5] = '!';

        // Write the modified message back to the shared memory
        strcpy(shm, message);

        // Exit the child process
        exit(0);
    } else {
        // Parent process
        wait(NULL);

        // Read the modified message from the shared memory
        char *message = shm;
        printf("Received modified message: %s\n", message);
    }

    // Unmap the shared memory
    munmap(shm, SHM_SIZE);

    // Detach from the shared memory segment
    shmctl(shmid, IPC_RMID, 0);

    return 0;
}