//FormAI DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHMSIZE 1024

int main() {

    int shmid;
    key_t key;
    char *shm, *s;

    // generate a unique key
    key = ftok("shmfile", 65);

    // allocate shared memory
    shmid = shmget(key, SHMSIZE, 0666|IPC_CREAT);

    if (shmid == -1) {
        perror("shmget failed!");
        exit(1);
    }

    // attach shared memory
    shm = shmat(shmid, NULL, 0);

    if (shm == (char*)-1) {
        perror("shmat failed!");
        exit(1);
    }

    memset(shm, 0, SHMSIZE);

    // create child process
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed!");
        exit(1);
    }

    // child process
    if (pid == 0) {

        char message[256] = "Hello from child process!";
        
        // write to shared memory
        strncpy(shm, message, 256);

        // detach from shared memory
        shmdt(shm);

        // exit child process
        exit(0);
    }

    // parent process
    if (pid > 0) {

        // wait for child process to finish
        wait(NULL);
        
        printf("Child wrote to shared memory: %s\n", shm);

        // detach from shared memory
        shmdt(shm);

        // remove shared memory
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}