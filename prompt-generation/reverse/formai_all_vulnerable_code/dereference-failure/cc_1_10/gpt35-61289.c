//FormAI DATASET v1.0 Category: Interprocess communication ; Style: complex
// Interprocess communication example program
// This program demonstrates the use of shared memory and semaphores for interprocess communication
// Author: AI Chatbot

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_SIZE 1024
#define NUM_SEMS 2 

union semun {
    int val;                /* Value for SETVAL */
    struct semid_ds *buf;   /* Buffer for IPC_STAT, IPC_SET */
    unsigned short *array;  /* Array for GETALL, SETALL */
};

int main(int argc, char *argv[]) {
    key_t shm_key;
    int shm_id, sem_id;
    int sem_val, sem_flg;
    char *shm_addr;
    struct sembuf sem_buf;
    union semun sem_val_arg;
    time_t t;

    srand(time(NULL));
    
    // Generate the shared memory key
    if ((shm_key = ftok(".", 'S')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Attach to the shared memory segment
    if ((shm_id = shmget(shm_key, SHM_SIZE, IPC_CREAT|0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Map the shared memory segment into the address space
    if ((shm_addr = shmat(shm_id, NULL, SHM_RND)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize the shared memory to all 0's
    memset(shm_addr, 0, SHM_SIZE);

    // Initialize semaphore 0 to value 1
    sem_val_arg.val = 1;
    if ((sem_id = semget(shm_key, NUM_SEMS, IPC_CREAT|0666)) == -1) {
        perror("semget");
        exit(1);
    }
    semctl(sem_id, 0, SETVAL, sem_val_arg);

    // Enter critical section
    sem_buf.sem_num = 0;
    sem_buf.sem_op = -1;  // decrement semval by 1
    sem_buf.sem_flg = SEM_UNDO; // let the kernel undo this operation when the process exits

    semop(sem_id, &sem_buf, 1);

    // Write to the shared memory
    sprintf(shm_addr, "Hello, world!");

    // Leave critical section
    sem_buf.sem_num = 0;
    sem_buf.sem_op = 1; // increment semval by 1
    sem_buf.sem_flg = SEM_UNDO;

    semop(sem_id, &sem_buf, 1);

    // Wait for 5 to 10 seconds
    sleep(rand() % 6 + 5);

    // Enter critical section
    sem_buf.sem_num = 1;
    sem_buf.sem_op = -1;
    sem_buf.sem_flg = SEM_UNDO;

    semop(sem_id, &sem_buf, 1);

    // Read from the shared memory
    printf("Message from shared memory: %s\n", shm_addr);

    // Leave critical section
    sem_buf.sem_num = 1;
    sem_buf.sem_op = 1;
    sem_buf.sem_flg = SEM_UNDO;

    semop(sem_id, &sem_buf, 1);

    // Detach from the shared memory
    shmdt(shm_addr);

    // Delete the shared memory segment and semaphore
    shmctl(shm_id, IPC_RMID, NULL);
    semctl(sem_id, 0, IPC_RMID, sem_val_arg);

    return 0;
}