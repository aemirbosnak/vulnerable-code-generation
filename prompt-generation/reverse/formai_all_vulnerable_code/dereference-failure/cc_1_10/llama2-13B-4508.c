//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <fcntl.h>

#define SHM_KEY 0xdeadbeef
#define SHM_SIZE 1024

// Structure to store data shared between processes
struct shared_data {
    char name[10];
    int age;
};

int main(int argc, char *argv[]) {
    // Create a shared memory segment
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory segment
    struct shared_data *shdata = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shdata == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // Fill the shared data structure with some data
    strcpy(shdata->name, "John");
    shdata->age = 30;

    // Create a new process and have it communicate with the parent process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        char *message = "Hello from the child!";
        // Write the message to the shared memory segment
        if (msync(message, strlen(message), MS_ASYNC) == -1) {
            perror("msync");
            exit(1);
        }
        // Wait for the parent process to read the message
        wait(NULL);
    } else {
        // Parent process
        char *message = NULL;
        // Read the message from the shared memory segment
        if (msync(shdata->name, strlen(shdata->name), MS_ASYNC) == -1) {
            perror("msync");
            exit(1);
        }
        message = shdata->name;
        // Print the message
        printf("%s\n", message);
    }

    // Unmap the shared memory segment
    munmap(shdata, SHM_SIZE);

    return 0;
}