//FormAI DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;

    pid_t pid;

    // generate key for shared memory
    if ((key = ftok("progfile", 'A')) == -1) {
        perror("ftok");
        exit(1);
    }

    // create shared memory
    if ((shmid = shmget(key, SHM_SIZE, 0666|IPC_CREAT)) == -1) {
        perror("shmget");
        exit(1);
    }

    // get pointer to shared memory
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // write message to shared memory
    strcpy(shm, "Hello World!");

    // fork new process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    else if (pid == 0) { // child process

        // get pointer to shared memory
        if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
            perror("shmat");
            exit(1);
        }

        // read message from shared memory
        printf("%s\n", shm);

        // detach from shared memory
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        exit(0);
    }
    else { // parent process

        // wait for child to complete
        wait(NULL);

        // detach from shared memory
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // delete shared memory
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}