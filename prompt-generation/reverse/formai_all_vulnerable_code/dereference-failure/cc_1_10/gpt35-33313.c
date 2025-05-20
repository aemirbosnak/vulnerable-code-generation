//FormAI DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    int id;
    char *shm, *s;

    // create shared memory segment
    id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (id < 0) {
        perror("shmget");
        exit(1);
    }

    // attach to shared memory segment
    shm = shmat(id, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // write to shared memory
    s = shm;
    sprintf(s, "Hello, World!");

    // fork child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // child process

        // read from shared memory
        s = shm;
        while (*s != '\0')
            putchar(*s++);

        putchar('\n');

        // detach from shared memory segment
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // delete shared memory segment
        if (shmctl(id, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }

        exit(0);
    } else {
        // parent process
        wait(NULL);

        // detach from shared memory segment
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // delete shared memory segment
        if (shmctl(id, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}