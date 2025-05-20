//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define KEY 0x12345678
#define SHM_SIZE 1024

int main() {
    int shmid;
    void *shmptr;

    // Create shared memory segment
    shmid = shmget(KEY, SHM_SIZE, IPC_CREAT | 0660);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    memset(shmptr, 0, SHM_SIZE);

    // Fork a child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        // Wait for parent to write to shared memory
        sleep(1);

        // Read from shared memory
        char *message = (char *) shmptr;
        printf("Child received message: %s\n", message);

        // Detach from shared memory
        if (shmdt(shmptr) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Exit child process
        exit(0);
    } else {
        // Parent process
        // Write to shared memory
        char *message = "Hello from parent!";
        strcpy((char *) shmptr, message);

        // Detach from shared memory
        if (shmdt(shmptr) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Wait for child to exit
        wait(NULL);
    }

    return 0;
}