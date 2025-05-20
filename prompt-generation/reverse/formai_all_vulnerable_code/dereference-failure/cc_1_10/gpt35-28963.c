//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHMSZ 27
#define MSG_SZ 256

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    pid_t pid;
    int shmid;
    char *shm, *s;

    if (argc != 2) {
        fprintf(stderr, "usage: %s [message]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SHMSZ, IPC_CREAT | 0666);
    if (shmid < 0)
        error("shmget");

    // Attach segment to data space
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1)
        error("shmat");

    // Fork a child process
    pid = fork();
    if (pid < 0)
        error("fork");

    // Child process
    if (pid == 0) {
        printf("Child process writing to shared memory...\n");

        // Type cast shared memory segment to char pointer
        s = shm;

        // Copy message from argument to shared memory
        sprintf(s, "%s", argv[1]);

        // Wait for parent process to read shared memory
        while (*shm != '*')
            sleep(1);

        printf("Child process exiting...\n");

        // Detach shared memory segment from data space
        if (shmdt(shm) < 0)
            error("shmdt");

        // Delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) < 0)
            error("shmctl");
    }

    // Parent process
    else {
        printf("Parent process reading from shared memory...\n");

        // Type cast shared memory segment to char pointer
        s = shm;

        // Wait for child process to write to shared memory
        while (*shm == ' ')
            sleep(1);

        // Print message from shared memory
        printf("Message from child process: %s\n", s);

        // Indicate to child process that it can exit
        *shm = '*';

        // Wait for child process to exit
        wait(NULL);

        printf("Parent process exiting...\n");

        // Detach shared memory segment from data space
        if (shmdt(shm) < 0)
            error("shmdt");

        // Delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) < 0)
            error("shmctl");
    }

    return 0;
}