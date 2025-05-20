//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;
    const char *msg = "Hello world!";

    // Generate a unique key for the shared memory segment
    key = ftok("ipc_example.c", 'R');

    // Create the shared memory segment
    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("Error creating shared memory segment");
        exit(1);
    }

    // Attach the memory segment to our address space
    shm = (char *) shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("Error attaching shared memory segment");
        exit(1);
    }

    // Write the data to the memory segment
    s = shm;
    for (int i = 0; i < SHM_SIZE; i++) {
        *s++ = *msg++;
        if (*msg == '\0') {
            break;
        }
    }

    // Detach the memory segment
    shmdt(shm);

    // Create a new process
    pid_t pid = fork();

    if (pid < 0) {
        perror("Error forking process");
        exit(1);
    }
    else if (pid == 0) {
        // Child process

        // Attach the memory segment to the child's address space
        shm = (char *) shmat(shmid, NULL, 0);
        if (shm == (char *) -1) {
            perror("Error attaching shared memory segment in child process");
            exit(1);
        }

        // Read the data from the memory segment
        s = shm;
        while (*s != '\0') {
            putchar(*s++);
        }
        putchar('\n');

        // Detach the memory segment
        shmdt(shm);

        // Destroy the memory segment
        shmctl(shmid, IPC_RMID, NULL);

        // Exit the child process
        exit(0);
    }
    else {
        // Father process
        // Wait for the child process to finish
        wait(NULL);

        // Detach the memory segment
        shmdt(shm);

        // Destroy the memory segment
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}