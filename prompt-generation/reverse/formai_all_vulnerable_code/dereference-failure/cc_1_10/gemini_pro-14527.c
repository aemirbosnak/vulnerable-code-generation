//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <fcntl.h>

#define SHM_SIZE 1024
#define SEM_KEY 1234

int main() {
    // Create a shared memory segment
    int shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the current process
    char *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Create a semaphore set
    int sem_id = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (sem_id == -1) {
        perror("semget");
        exit(1);
    }

    // Initialize the semaphore to 1
    semctl(sem_id, 0, SETVAL, 1);

    // Create a child process
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }

    if (child_pid == 0) {  // Child process
        // Write to the shared memory segment
        strcpy(shm_ptr, "Hello from the child process!");

        // Signal the parent process that the data is ready
        semop(sem_id, &(struct sembuf){0, -1, 0}, 1);

        // Wait for the parent process to finish reading the data
        semop(sem_id, &(struct sembuf){0, 1, 0}, 1);

        // Detach the shared memory segment from the current process
        shmdt(shm_ptr);

        exit(0);
    } else {  // Parent process
        // Wait for the child process to signal that the data is ready
        semop(sem_id, &(struct sembuf){0, -1, 0}, 1);

        // Read from the shared memory segment
        printf("%s\n", shm_ptr);

        // Signal the child process that the data has been read
        semop(sem_id, &(struct sembuf){0, 1, 0}, 1);

        // Detach the shared memory segment from the current process
        shmdt(shm_ptr);

        // Wait for the child process to finish
        waitpid(child_pid, NULL, 0);

        // Remove the shared memory segment
        shmctl(shm_id, IPC_RMID, NULL);

        // Remove the semaphore set
        semctl(sem_id, 0, IPC_RMID);
    }

    return 0;
}