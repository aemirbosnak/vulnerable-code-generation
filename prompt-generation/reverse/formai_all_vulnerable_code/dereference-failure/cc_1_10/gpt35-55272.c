//FormAI DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main()
{
    pid_t pid;
    int status;
    char *msg;

    // create shared memory
    int shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // fork a child process
    pid = fork();

    if (pid < 0) { // error occurred
        perror("fork");
        exit(1);
    }
    else if (pid == 0) { // child process
        msg = shmat(shmid, NULL, 0);

        if (msg == (char *) -1) {
            perror("shmat");
            exit(1);
        }

        strcpy(msg, "Hello from the child process!\n");

        exit(0);
    }
    else { // parent process
        msg = shmat(shmid, NULL, 0);

        if (msg == (char *) -1) {
            perror("shmat");
            exit(1);
        }

        waitpid(pid, &status, 0);
        printf("%s", msg);

        if (shmdt(msg) == -1) {
            perror("shmdt");
            exit(1);
        }

        if (shmctl(shmid, IPC_RMID, 0) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}