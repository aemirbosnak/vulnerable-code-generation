//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/sem.h>

#define SEM_KEY 456

int main(int argc, char *argv[]) {
    int shmid, semid;
    char *shmaddr;
    int i, n;
    pid_t pid;
    char input[1024];

    if (argc < 2) {
        printf("Usage: %s <message>\n", argv[0]);
        exit(1);
    }

    strcpy(input, argv[1]);
    n = strlen(input);

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, n + 1, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Create semaphore set
    semid = semget(SEM_KEY, 2, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    semctl(semid, 0, SETVAL, 1);
    semctl(semid, 1, SETVAL, 0);

    // Fork child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process writes message to shared memory
        strcpy(shmaddr, input);
        shmctl(shmid, IPC_RMID, NULL);
        exit(0);
    } else {
        // Parent process reads message from shared memory
        wait(NULL);
        semctl(semid, 0, GETVAL);
        while (semctl(semid, 1, GETVAL) == 0) {
            usleep(100);
        }
        strcpy(input, shmaddr);
        shmctl(shmid, IPC_RMID, NULL);
        printf("Message received: %s\n", input);
        exit(0);
    }

    return 0;
}