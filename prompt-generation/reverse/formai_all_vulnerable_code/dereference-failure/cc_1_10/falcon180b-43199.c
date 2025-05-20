//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>

#define BUFFER_SIZE 100
#define SEM_KEY 0x1234
#define SEM_ID 0x5678
#define SHM_KEY 0x8765
#define SHM_ID 0x4321

int main() {
    int shmid, semid, status;
    char *shmptr;
    pid_t childpid;

    semid = semget(SEM_KEY, 1, 0644 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    shmid = shmget(SHM_KEY, BUFFER_SIZE, 0644 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    childpid = fork();

    if (childpid == 0) {
        sleep(1);
        for (int i = 0; i < BUFFER_SIZE; i++) {
            shmptr[i] = 'a' + i;
        }
        for (int i = 0; i < BUFFER_SIZE; i++) {
            printf("%c", shmptr[i]);
        }
        exit(0);
    } else {
        waitpid(childpid, &status, 0);
        sleep(2);
        for (int i = 0; i < BUFFER_SIZE; i++) {
            shmptr[i] = 'A' + i;
        }
        semctl(semid, 0, SETVAL, 1);
        sleep(1);
        for (int i = 0; i < BUFFER_SIZE; i++) {
            printf("%c", shmptr[i]);
        }
    }

    return 0;
}