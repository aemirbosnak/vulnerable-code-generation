//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>

#define MAX_MSG_SIZE 100
#define SEM_ID 0
#define SHM_ID 1

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() {
    int shmid, semid;
    char *shmaddr;
    char *msg;
    int i, num_procs = 3;
    pid_t childpid;

    key_t key = ftok("shm.c", 65);

    if ((shmid = shmget(key, sizeof(char) * MAX_MSG_SIZE, IPC_CREAT | IPC_EXCL | 0666)) < 0) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    if ((shmaddr = shmat(shmid, NULL, 0)) == (void *) -1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    if ((semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666)) < 0) {
        printf("Error creating semaphore\n");
        exit(1);
    }

    semctl(semid, SEM_ID, SETVAL, 0);

    for (i = 0; i < num_procs; i++) {
        if ((childpid = fork()) < 0) {
            printf("Error forking process\n");
            exit(1);
        } else if (childpid == 0) {
            break;
        }
    }

    if (childpid == 0) {
        char *msg = "Hello, world!";
        strcpy(shmaddr, msg);
        sleep(1);
        semctl(semid, SEM_ID, SETVAL, 1);
        exit(0);
    } else {
        wait(NULL);
        printf("Received message: %s\n", shmaddr);
    }

    return 0;
}