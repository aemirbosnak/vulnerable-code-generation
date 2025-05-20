//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>
#include <errno.h>

#define SIZE 1000
#define SEM_ID 0x1234
#define SHM_ID 0x5678

int main(int argc, char *argv[]) {
    int shmid;
    int semid;
    int *shm;
    struct sembuf sembuf;
    char *shm_ptr;
    int i;

    // Create shared memory segment
    shmid = shmget(SHM_ID, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment: %s\n", strerror(errno));
        exit(1);
    }

    // Attach to shared memory segment
    shm = (int *) shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        printf("Error attaching to shared memory segment: %s\n", strerror(errno));
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        shm[i] = i;
    }

    // Create semaphore set
    semid = semget(SEM_ID, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        printf("Error creating semaphore set: %s\n", strerror(errno));
        exit(1);
    }

    // Initialize semaphore set
    sembuf.sem_num = 0;
    sembuf.sem_op = 0;
    sembuf.sem_flg = SEM_UNDO;
    semop(semid, &sembuf, 1);

    // Start child process
    int pid = fork();
    if (pid == 0) {
        // Child process
        // Wait for semaphore to be unlocked
        semop(semid, &sembuf, 1);

        // Modify shared memory segment
        for (i = 0; i < SIZE; i++) {
            shm[i] *= 2;
        }

        // Unlock semaphore
        sembuf.sem_op = 1;
        semop(semid, &sembuf, 1);
        exit(0);
    } else {
        // Parent process
        // Wait for child process to modify shared memory segment
        sleep(1);

        // Print modified shared memory segment
        for (i = 0; i < SIZE; i++) {
            printf("%d ", shm[i]);
        }
        printf("\n");

        // Unlock semaphore
        sembuf.sem_op = 1;
        semop(semid, &sembuf, 1);
        exit(0);
    }
}