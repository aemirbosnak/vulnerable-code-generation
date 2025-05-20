//FormAI DATASET v1.0 Category: Interprocess communication ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <semaphore.h>

#define SHM_SIZE 1024

int main() {
    pid_t pid;
    sem_t *semaphore;
    char *shared_mem;
    int shmid;
    key_t key;

    // Create a semaphore
    semaphore = sem_open("my_semaphore", O_CREAT, 0644, 1);

    // Create shared memory segment
    key = ftok("/dev/null", 125);
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    shared_mem = shmat(shmid, NULL, 0);

    // Fork a child process
    pid = fork();
    if (pid < 0) {
        perror("Error forking");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        sem_wait(semaphore);
        printf("Child Process Writing to Shared Memory: ");
        strcpy(shared_mem, "Hello, World!");
        sem_post(semaphore);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        sem_wait(semaphore);
        printf("Parent Process Reading from Shared Memory: %s\n", shared_mem);
        sem_post(semaphore);
        wait(NULL);

        // Detach and remove shared memory segment
        shmdt(shared_mem);
        shmctl(shmid, IPC_RMID, NULL);

        // Close and unlink semaphore
        sem_close(semaphore);
        sem_unlink("my_semaphore");

        exit(EXIT_SUCCESS);
    }
}