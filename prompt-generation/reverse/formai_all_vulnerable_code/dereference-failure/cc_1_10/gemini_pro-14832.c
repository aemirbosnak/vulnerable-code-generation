//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: Sherlock Holmes
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SHM_KEY 12345
#define SEM_KEY 54321

#define ELEMENTARY 0
#define WATSON 1
#define SHERLOCK 2

typedef struct {
    int pid;
    char message[1024];
} Message;

int main() {
    int shmid, semid;
    Message *shared_memory;
    struct sembuf semaphore;

    // Create a shared memory segment.
    if((shmid = shmget(SHM_KEY, sizeof(Message), IPC_CREAT|0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the current process.
    if((shared_memory = (Message *)shmat(shmid, NULL, 0)) == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Create a semaphore.
    if((semid = semget(SEM_KEY, 1, IPC_CREAT|0666)) == -1) {
        perror("semget");
        exit(1);
    }

    // Initialize the semaphore.
    semaphore.sem_num = 0;
    semaphore.sem_op = 1;
    semaphore.sem_flg = 0;
    if(semop(semid, &semaphore, 1) == -1) {
        perror("semop");
        exit(1);
    }

    // Wait for Watson to post a message.
    semaphore.sem_op = -1;
    if(semop(semid, &semaphore, 1) == -1) {
        perror("semop");
        exit(1);
    }

    // Read the message from Watson.
    printf("Sherlock: \"%s\"\n", shared_memory->message);

    // Reply to Watson.
    strcpy(shared_memory->message, "Elementary, my dear Watson.");
    shared_memory->pid = getpid();

    // Signal Watson that the reply is ready.
    semaphore.sem_op = 1;
    if(semop(semid, &semaphore, 1) == -1) {
        perror("semop");
        exit(1);
    }

    // Detach the shared memory segment from the current process.
    if(shmdt(shared_memory) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Delete the shared memory segment.
    if(shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    // Delete the semaphore.
    if(semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl");
        exit(1);
    }

    return 0;
}