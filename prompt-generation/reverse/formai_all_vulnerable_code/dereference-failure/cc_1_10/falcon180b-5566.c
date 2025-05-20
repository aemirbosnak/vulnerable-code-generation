//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <string.h>

#define SEM_KEY 1234
#define SEM_ID 0

int main() {
    int semid, shmid;
    char *shmaddr;
    int i;
    pid_t childpid;

    semid = semget(SEM_KEY, 2, 0666 | IPC_CREAT);

    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    for (i = 0; i < 2; i++) {
        if (semctl(semid, i, SETVAL, 1) == -1) {
            perror("semctl");
            exit(1);
        }
    }

    shmid = shmget(IPC_PRIVATE, sizeof(int), 0666 | IPC_CREAT);

    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    shmaddr = shmat(shmid, 0, 0);

    if (shmaddr == (void *) - 1) {
        perror("shmat");
        exit(1);
    }

    *shmaddr = 0;

    childpid = fork();

    if (childpid == 0) {
        for (i = 0; i < 10; i++) {
            sleep(1);
            printf("Child: %d\n", i);
            if (i == 5) {
                shmctl(shmid, IPC_RMID, 0);
                exit(0);
            }
        }
    } else {
        wait(0);
        for (i = 0; i < 10; i++) {
            sleep(1);
            printf("Parent: %d\n", i);
        }
    }

    return 0;
}