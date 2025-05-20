//FormAI DATASET v1.0 Category: Interprocess communication ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;
    char message[] = "Hello, World!";
    pid_t pid;

    // create shared memory
    key = ftok(".", 'a');
    if ((shmid = shmget(key, sizeof(message), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // fork child process
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) { // child process
        // attach to shared memory segment
        if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
            perror("shmat");
            exit(1);
        }
        // read from shared memory and print to stdout
        for (s = shm; *s != '\0'; s++)
            putchar(*s);
        putchar('\n');
        // detach from shared memory segment
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }
        exit(0);
    }
    else { // parent process
        wait(NULL);
        // attach to shared memory segment
        if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
            perror("shmat");
            exit(1);
        }
        // write to shared memory
        memcpy(shm, message, sizeof(message));
        // wait for child process to finish
        wait(NULL);
        // detach from shared memory segment
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }
        // destroy shared memory segment
        if (shmctl(shmid, IPC_RMID, 0) == -1) {
            perror("shmctl");
            exit(1);
        }
        exit(0);
    }

    return 0;
}