//FormAI DATASET v1.0 Category: Interprocess communication ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>

#define SHM_SIZE 1024  // Shared Memory size

int main()
{
    key_t key = ftok("example", 'R');
    int shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT); // Create shared memory
    char *shared_memory = shmat(shmid, (void *)0, 0); // Attach shared memory segment

    if (shmid == -1) { // Error handling
        perror("shmget");
        exit(EXIT_FAILURE);
    } 
    
    if (shared_memory == (char *)(-1)) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    memcpy(shared_memory, "Hello, World!", 14); // Write to shared memory

    printf("Waiting for child process...\n");

    pid_t pid = fork(); // Forking a child process

    if (pid == -1) { // Error handling
        perror("fork");
        shmdt(shared_memory); // Detach shared memory segment
        shmctl(shmid, IPC_RMID, NULL); // Remove shared memory segment
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process reads from shared memory
        sleep(3); // Wait for parent process to write to shared memory
        printf("Child process reading from shared memory: %s\n", shared_memory);
        shmdt(shared_memory); // Detach shared memory segment
        exit(EXIT_SUCCESS);
    }
    else { // Parent process waits for child process
        wait(NULL);
        printf("Parent process finished\n");
        shmdt(shared_memory); // Detach shared memory segment
        shmctl(shmid, IPC_RMID, NULL); // Remove shared memory segment
        exit(EXIT_SUCCESS);
    }

    return 0;
}