//FormAI DATASET v1.0 Category: Interprocess communication ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main()
{
    pid_t pid;
    int shmid;
    char *shm, *s;

    // create shared memory
    if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // attach the shared memory segment
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // fork a child process
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }

    // child process
    if (pid == 0) {
        char message[SHM_SIZE] = "Hello, parent process!";

        // write the message to the shared memory segment
        strcpy(shm, message);

        // exit child process
        exit(0);
    }

    // parent process
    if (pid > 0) {
        // wait for child to finish
        wait(NULL);

        // read the message from the shared memory segment
        for (s = shm; *s != '\0'; s++) {
            putchar(*s);
        }
        putchar('\n');

        // detach the shared memory segment
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // delete the shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}