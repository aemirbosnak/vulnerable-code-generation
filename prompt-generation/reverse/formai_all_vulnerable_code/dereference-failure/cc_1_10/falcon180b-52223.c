//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int fd[2];
    pid_t pid;
    char *shm;
    int shmid;

    if (pipe(fd) == -1) {
        printf("Pipe failed\n");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execlp("child", "child", NULL);
    } else {
        // Parent process
        close(fd[1]);
        shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
        if (shmid == -1) {
            printf("Shared memory failed\n");
            exit(1);
        }
        shm = shmat(shmid, NULL, 0);
        if (shm == (char *) -1) {
            printf("Shmat failed\n");
            exit(1);
        }
        for (int i = 0; i < SIZE; i++) {
            shm[i] = 0;
        }
        int status;
        waitpid(pid, &status, 0);
        close(fd[0]);
    }
    return 0;
}