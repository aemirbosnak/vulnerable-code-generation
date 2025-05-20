//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 100
#define SHM_KEY 1234

int main() {
    int shmid;
    char *shm;
    pid_t pid;

    shmid = shmget(SHM_KEY, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error: shmget failed\n");
        exit(1);
    }

    shm = shmat(shmid, (void *)0, 0);
    if ((int)shm == -1) {
        printf("Error: shmat failed\n");
        exit(1);
    }

    pid = fork();

    if (pid == 0) { // child
        char *message = "Hello from child process!";
        memcpy(shm, message, strlen(message)+1);
        sleep(2);
        printf("Child process: sent message to shared memory\n");
        exit(0);
    }
    else if (pid > 0) { // parent
        memset(shm, 0, SIZE);
        sleep(1);
        printf("Parent process: received message from shared memory: %s\n", shm);
        wait(NULL);
        exit(0);
    }
    else { // error
        printf("Error: fork failed\n");
        exit(1);
    }

    return 0;
}