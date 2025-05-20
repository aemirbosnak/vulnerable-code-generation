//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>

#define SIZE 1024
#define KEY 123456

int main() {
    int shmid, semid;
    int *shared_memory;
    int *semaphore;
    int i;

    // create shared memory segment
    shmid = shmget(KEY, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("shmget failed\n");
        exit(1);
    }

    // attach shared memory to process
    shared_memory = (int *) shmat(shmid, NULL, 0);
    if ((int) shared_memory == -1) {
        printf("shmat failed\n");
        exit(1);
    }

    // initialize shared memory
    for (i = 0; i < SIZE; i++) {
        shared_memory[i] = 0;
    }

    // create semaphore
    semid = semget(KEY, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        printf("semget failed\n");
        exit(1);
    }

    // initialize semaphore
    semaphore = (int *) mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, semid, 0);
    if ((int) semaphore == -1) {
        printf("mmap failed\n");
        exit(1);
    }

    semaphore[0] = 1;

    // fork child process
    int pid = fork();

    if (pid == -1) {
        printf("fork failed\n");
        exit(1);
    } else if (pid == 0) {
        // child process

        // wait for semaphore
        sem_wait(semaphore);

        // access shared memory
        for (i = 0; i < SIZE; i++) {
            shared_memory[i] = i;
        }

        // release semaphore
        sem_post(semaphore);

        // exit child process
        exit(0);
    } else {
        // parent process

        // wait for child process
        wait(NULL);

        // access shared memory
        for (i = 0; i < SIZE; i++) {
            if (shared_memory[i]!= i) {
                printf("shared memory corrupted\n");
                exit(1);
            }
        }

        // remove shared memory and semaphore
        shmctl(shmid, IPC_RMID, NULL);
        semctl(semid, 0, IPC_RMID);
    }

    return 0;
}