//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <time.h>
#include <errno.h>

#define SHM_SIZE 1024
#define SEM_KEY 0x12345678

int child(int shmid, int semid) {
    void *shmptr;
    struct sembuf sops[2];

    srand(time(NULL));
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void *)-1) {
        perror("shmat");
        return -1;
    }

    while (1) {
        sops[0].sem_num = 0;
        sops[0].sem_op = -1;
        sops[0].sem_flg = IPC_NOWAIT;
        sops[1].sem_num = 1;
        sops[1].sem_op = 1;
        sops[1].sem_flg = IPC_NOWAIT;
        if (semop(semid, sops, 2) == -1) {
            if (errno == EAGAIN) {
                continue;
            } else {
                perror("semop");
                return -1;
            }
        }

        printf("Child: %d\n", rand() % 100);

        usleep(100000);

        sops[0].sem_num = 0;
        sops[0].sem_op = 1;
        sops[0].sem_flg = IPC_NOWAIT;
        sops[1].sem_num = 1;
        sops[1].sem_op = -1;
        sops[1].sem_flg = IPC_NOWAIT;
        if (semop(semid, sops, 2) == -1) {
            perror("semop");
            return -1;
        }
    }

    return 0;
}

int parent(int shmid, int semid) {
    void *shmptr;
    struct sembuf sops[2];

    srand(time(NULL));
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void *)-1) {
        perror("shmat");
        return -1;
    }

    while (1) {
        sops[0].sem_num = 1;
        sops[0].sem_op = -1;
        sops[0].sem_flg = IPC_NOWAIT;
        sops[1].sem_num = 0;
        sops[1].sem_op = 1;
        sops[1].sem_flg = IPC_NOWAIT;
        if (semop(semid, sops, 2) == -1) {
            if (errno == EAGAIN) {
                continue;
            } else {
                perror("semop");
                return -1;
            }
        }

        printf("Parent: %d\n", rand() % 100);

        usleep(100000);

        sops[0].sem_num = 1;
        sops[0].sem_op = 1;
        sops[0].sem_flg = IPC_NOWAIT;
        sops[1].sem_num = 0;
        sops[1].sem_op = -1;
        sops[1].sem_flg = IPC_NOWAIT;
        if (semop(semid, sops, 2) == -1) {
            perror("semop");
            return -1;
        }
    }

    return 0;
}

int main() {
    int shmid, semid;
    pid_t pid;
    void *shmptr;

    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | IPC_EXCL | 0600);
    if (shmid == -1) {
        perror("shmget");
        return -1;
    }

    semid = semget(SEM_KEY, 2, IPC_CREAT | IPC_EXCL | 0600);
    if (semid == -1) {
        perror("semget");
        return -1;
    }

    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void *)-1) {
        perror("shmat");
        return -1;
    }

    if (semctl(semid, 0, SETVAL, 1) == -1) {
        perror("semctl");
        return -1;
    }

    if (semctl(semid, 1, SETVAL, 0) == -1) {
        perror("semctl");
        return -1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        return child(shmid, semid);
    } else {
        return parent(shmid, semid);
    }

    return 0;
}