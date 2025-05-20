//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/wait.h>

#define SHM_SIZE 1024
#define SEM_KEY 1234
#define SHM_KEY 5678

struct sembuf sem_op;

// Function to perform semaphore wait (P operation)
void sem_wait(int semid) {
    sem_op.sem_num = 0;
    sem_op.sem_op = -1;
    sem_op.sem_flg = 0;
    if (semop(semid, &sem_op, 1) == -1) {
        perror("Semaphore wait failed");
        exit(EXIT_FAILURE);
    }
}

// Function to perform semaphore signal (V operation)
void sem_signal(int semid) {
    sem_op.sem_num = 0;
    sem_op.sem_op = 1;
    sem_op.sem_flg = 0;
    if (semop(semid, &sem_op, 1) == -1) {
        perror("Semaphore signal failed");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Create a shared memory segment
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("Failed to create shared memory");
        exit(EXIT_FAILURE);
    }

    // Create a semaphore for synchronization
    int semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid < 0) {
        perror("Failed to create semaphore");
        exit(EXIT_FAILURE);
    }

    // Initialize the semaphore
    if (semctl(semid, 0, SETVAL, 1) == -1) {
        perror("Failed to initialize semaphore");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment
    char *shm_data = (char *)shmat(shmid, NULL, 0);
    if (shm_data == (char *)(-1)) {
        perror("Failed to attach shared memory");
        exit(EXIT_FAILURE);
    }

    // Fork to create a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  // Child process
        // Read messages from the parent
        for (int i = 0; i < 5; i++) {
            sem_wait(semid);  // Wait for the parent to signal
            printf("Child received: %s\n", shm_data);
            sem_signal(semid); // Signal the parent to write again
            sleep(1);
        }
    } else {  // Parent process
        // Write messages to the child
        const char *messages[5] = {
            "Hello from parent 1!",
            "Hello from parent 2!",
            "Hello from parent 3!",
            "Hello from parent 4!",
            "Hello from parent 5!"
        };

        for (int i = 0; i < 5; i++) {
            sem_wait(semid);  // Wait for the child to read
            strcpy(shm_data, messages[i]);  // Write a message to shared memory
            printf("Parent sent: %s\n", messages[i]);
            sem_signal(semid); // Signal the child to read
            sleep(1);
        }

        // Wait for the child process to finish
        wait(NULL);
    }

    // Detach and remove shared memory and semaphore
    shmdt(shm_data);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);

    printf("IPC communication completed successfully!\n");
    return 0;
}