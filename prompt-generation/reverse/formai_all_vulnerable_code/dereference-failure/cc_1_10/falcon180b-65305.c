//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024

int main() {
    int shm_id;
    void *shm_ptr;
    pid_t child_pid;

    // Create shared memory segment
    shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        printf("Error: shmget failed\n");
        return 1;
    }

    // Attach to shared memory segment
    shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *) - 1) {
        printf("Error: shmat failed\n");
        return 1;
    }

    // Initialize shared memory
    memset(shm_ptr, 0, SHM_SIZE);

    // Fork child process
    child_pid = fork();
    if (child_pid == -1) {
        printf("Error: fork failed\n");
        return 1;
    } else if (child_pid == 0) {
        // Child process
        sleep(1); // Allow parent to initialize shared memory

        // Write to shared memory
        char *message = "Hello, world!";
        strcpy(shm_ptr, message);

        // Detach from shared memory
        if (shmdt(shm_ptr) == -1) {
            printf("Error: shmdt failed\n");
            return 1;
        }

        // Exit child process
        return 0;
    } else {
        // Parent process
        sleep(2); // Allow child to write to shared memory

        // Read from shared memory
        char message[SHM_SIZE];
        memcpy(message, shm_ptr, SHM_SIZE);
        printf("Message from child: %s\n", message);

        // Detach from shared memory
        if (shmdt(shm_ptr) == -1) {
            printf("Error: shmdt failed\n");
            return 1;
        }

        // Wait for child process to exit
        wait(NULL);

        // Delete shared memory segment
        if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
            printf("Error: shmctl failed\n");
            return 1;
        }
    }

    return 0;
}