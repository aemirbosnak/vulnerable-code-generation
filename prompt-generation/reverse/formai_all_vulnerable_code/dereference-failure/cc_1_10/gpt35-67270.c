//FormAI DATASET v1.0 Category: Interprocess communication ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <errno.h>

#define CHILD_PROCESS 0
#define SHM_SIZE 1024

int main() {
    pid_t pid;
    key_t key = ftok("shared_memory", 'X');

    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    char *shm_pointer = shmat(shmid, NULL, 0);
    if (*shm_pointer == -1) {
        perror("shmat");
        exit(1);
    }

    printf("Enter a message: ");
    fgets(shm_pointer, SHM_SIZE, stdin);
    *shm_pointer = '*';

    pid = fork();

    if (pid < CHILD_PROCESS) {
        perror("fork");
        exit(1);
    }

    if (pid == CHILD_PROCESS) {
        while (*shm_pointer != '*')
            sleep(1);

        printf("Child got the message: %s", shm_pointer + 1);
        *shm_pointer = '%';
        exit(0);
    }

    else {
        while (*shm_pointer != '%')
            sleep(1);

        printf("Parent got the message: %s", shm_pointer + 1);

        if (shmdt(&shm_pointer) == -1) {
            perror("shmdt");
            exit(1);
        }

        if (shmctl(shmid, IPC_RMID, 0) == -1) {
            perror("shmctl");
            exit(1);
        }

        printf("Shared memory memory detached and destroyed. Exiting program.\n");
        exit(0);
    }

    return 0;
}