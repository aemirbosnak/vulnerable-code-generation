//FormAI DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SHM_SIZE 1024  // shared memory size

int main(int argc, char *argv[]) {
    pid_t pid;
    key_t key;
    int shmid, status;
    char *shm, *s;

    key = 5678;

    // create shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // attach shared memory segment to process' address space
    if ((shm = shmat(shmid, NULL, 0)) == (char*) -1) {
        perror("shmat");
        exit(1);
    }

    // fork a child process to send and receive message
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }

    // child process sends message to parent process through shared memory
    if (pid == 0) {
        while (*shm != '*')
            sleep(1);
        for (s = shm + 1; *s != 0; s++)
            putchar(*s);
        putchar('\n');
        *shm = '#';
        exit(0);
    }

    // parent process receives message from child process through shared memory
    else {
        printf("Enter a message: ");
        fgets(s, SHM_SIZE, stdin);
        for (s = shm + 1; *s != 0; s++)
            *s = getchar();
        *s = 0;
        *shm = '*';
        wait(&status);
        printf("Message received: %s\n", shm+1);
    }

    // detach shared memory segment from process' address space
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // remove shared memory segment from system
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}