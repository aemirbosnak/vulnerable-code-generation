//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <errno.h>

// Declare our shared memory segment and semaphore
int shmid, semid;
char *shm;
struct sembuf op;

// Initialize our shared memory and semaphore
void ipc_init() {
    // Create our shared memory segment
    if ((shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach our shared memory segment
    if ((shm = shmat(shmid, NULL, 0)) == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    // Create our semaphore
    if ((semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666)) == -1) {
        perror("semget");
        exit(1);
    }

    // Initialize our semaphore
    op.sem_num = 0;
    op.sem_op = 0;
    op.sem_flg = 0;
    if (semop(semid, &op, 1) == -1) {
        perror("semop");
        exit(1);
    }
}

// Detach and remove our shared memory and semaphore
void ipc_cleanup() {
    // Detach our shared memory segment
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Remove our shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    // Remove our semaphore
    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl");
        exit(1);
    }
}

// Write to our shared memory segment
void ipc_write(char *data) {
    // Wait for our semaphore
    if (semop(semid, &op, 1) == -1) {
        perror("semop");
        exit(1);
    }

    // Write our data to shared memory
    strcpy(shm, data);

    // Signal our semaphore
    op.sem_op = 1;
    if (semop(semid, &op, 1) == -1) {
        perror("semop");
        exit(1);
    }
}

// Read from our shared memory segment
char *ipc_read() {
    // Wait for our semaphore
    if (semop(semid, &op, 1) == -1) {
        perror("semop");
        exit(1);
    }

    // Read our data from shared memory
    char *data = shm;

    // Signal our semaphore
    op.sem_op = 1;
    if (semop(semid, &op, 1) == -1) {
        perror("semop");
        exit(1);
    }

    return data;
}

// Our main function
int main() {
    // Initialize our IPC
    ipc_init();

    // Create a child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    // Child process
    if (pid == 0) {
        // Write to our shared memory segment
        ipc_write("Hello from the child process!");

        // Sleep for 1 second
        sleep(1);

        // Read from our shared memory segment
        char *data = ipc_read();

        // Print our data
        printf("Child process received: %s\n", data);
    }
    // Parent process
    else {
        // Sleep for 1 second
        sleep(1);

        // Read from our shared memory segment
        char *data = ipc_read();

        // Print our data
        printf("Parent process received: %s\n", data);

        // Write to our shared memory segment
        ipc_write("Hello from the parent process!");
    }

    // Cleanup our IPC
    ipc_cleanup();

    return 0;
}