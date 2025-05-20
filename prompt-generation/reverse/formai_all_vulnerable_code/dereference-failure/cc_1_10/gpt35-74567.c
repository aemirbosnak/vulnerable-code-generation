//FormAI DATASET v1.0 Category: Interprocess communication ; Style: modular
// modular IPC example program using shared memory and semaphores
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_SIZE 256 // size of shared memory buffer
#define SEM_KEY 9876 // semaphore key
#define SHM_KEY 5678 // shared memory key

// function to create and initialize semaphore
void init_semaphore(int semid) {
    union semun {
        int val;
        struct semid_ds *buf;
        ushort *array;
    } arg;
    arg.val = 1; // set semaphore value to 1
    semctl(semid, 0, SETVAL, arg); // set the initial semaphore value
}

// function to create and initialize shared memory
char *init_shared_memory(int shmid) {
    char *shmaddr;
    if ((shmaddr = (char *)shmat(shmid, 0, 0)) == (char *) -1) { // attach to shared memory segment
        perror("shmat");
        exit(1);
    }
    // initialize shared memory buffer to all zeros
    int i;
    for (i = 0; i < SHM_SIZE; i++) {
        shmaddr[i] = 0;
    }
    return shmaddr;
}

int main(void) {
    int semid, shmid;
    char *shmaddr;
    struct sembuf semlock = { 0, -1, SEM_UNDO }; // semaphore lock operation
    struct sembuf semunlock = { 0, 1, SEM_UNDO }; // semaphore unlock operation

    // create semaphore
    if ((semid = semget(SEM_KEY, 1, IPC_CREAT | 0666)) == -1) {
        perror("semget");
        exit(1);
    }
    init_semaphore(semid); // initialize semaphore

    // create shared memory segment
    if ((shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }
    shmaddr = init_shared_memory(shmid); // initialize shared memory

    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) { // child process
        int i;
        char ch = 'A';
        for (i = 0; i < SHM_SIZE; i++) {
            semop(semid, &semlock, 1); // acquire semaphore lock
            shmaddr[i] = ch; // write character to shared memory
            semop(semid, &semunlock, 1); // release semaphore lock
            ch++; // increment character
            sleep(1); // sleep for 1 second
        }
        printf("Child process completed.\n");
    } else { // parent process
        int i;
        for (i = 0; i < SHM_SIZE; i++) {
            semop(semid, &semlock, 1); // acquire semaphore lock
            printf("%c", shmaddr[i]); // read character from shared memory
            semop(semid, &semunlock, 1); // release semaphore lock
        }
        printf("\nParent process completed.\n");
    }

    // detach from shared memory segment
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }
    // remove shared memory segment
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl");
        exit(1);
    }
    // remove semaphore
    if (semctl(semid, 0, IPC_RMID, 0) == -1) {
        perror("semctl");
        exit(1);
    }

    return 0;
}