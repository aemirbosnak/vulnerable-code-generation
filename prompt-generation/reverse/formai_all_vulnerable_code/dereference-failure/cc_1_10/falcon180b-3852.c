//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100
#define SEM_KEY 0x1234
#define SHM_KEY 0x5678

typedef struct {
    int id;
    char name[MAX_SIZE];
    int age;
} person_t;

int main() {
    int shmid, semid;
    key_t key;
    person_t *shared_memory;
    int *semaphore;
    pid_t child_pid;
    int status;

    // Create shared memory segment
    key = SHM_KEY;
    shmid = shmget(key, sizeof(person_t), IPC_CREAT | IPC_EXCL | 0666);
    if (shmid < 0) {
        printf("Error: shmget failed\n");
        return 1;
    }

    // Attach shared memory segment to process
    shared_memory = (person_t *) shmat(shmid, NULL, 0);
    if (shared_memory == (void *) -1) {
        printf("Error: shmat failed\n");
        return 1;
    }

    // Initialize shared memory segment
    shared_memory->id = 0;
    strcpy(shared_memory->name, "John Doe");
    shared_memory->age = 30;

    // Create semaphore
    key = SEM_KEY;
    semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666);
    if (semid < 0) {
        printf("Error: semget failed\n");
        return 1;
    }

    // Initialize semaphore
    semaphore = (int *) semctl(semid, 0, SETVAL, 1);
    if (semaphore == (void *) -1) {
        printf("Error: semctl failed\n");
        return 1;
    }

    // Fork child process
    child_pid = fork();
    if (child_pid < 0) {
        printf("Error: fork failed\n");
        return 1;
    } else if (child_pid == 0) {
        // Child process
        sleep(2);
        semaphore = (int *) semctl(semid, 0, GETVAL);
        if (*semaphore == 0) {
            printf("Child: Semaphore is locked\n");
            exit(0);
        } else {
            shared_memory->id++;
            strcpy(shared_memory->name, "Jane Doe");
            shared_memory->age = 28;
            printf("Child: Shared memory updated\n");
            exit(0);
        }
    } else {
        // Parent process
        sleep(1);
        semaphore = (int *) semctl(semid, 0, GETVAL);
        if (*semaphore == 1) {
            printf("Parent: Semaphore is unlocked\n");
            exit(0);
        } else {
            wait(&status);
            printf("Parent: Child process terminated\n");
            exit(0);
        }
    }

    return 0;
}