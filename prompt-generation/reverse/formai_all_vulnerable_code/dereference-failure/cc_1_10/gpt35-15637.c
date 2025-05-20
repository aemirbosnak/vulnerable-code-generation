//FormAI DATASET v1.0 Category: Interprocess communication ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHMSIZE 27
#define MSGSIZE 20

int main() {
    pid_t pid;
    int shmid;
    char *shm, *s;

    //creating a shared memory segment
    if ((shmid = shmget(IPC_PRIVATE, SHMSIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    //attaching the shared memory segment to our data space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    //writing a message to the shared memory segment
    strcpy(shm, "Hello, world!");

    //creating a child process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {  /* child process */
        //reading the message from the shared memory segment
        printf("Child process reads: ");
        for (s = shm; *s != '\0'; s++) {
            putchar(*s);
        }
        putchar('\n');

        //writing a new message to the shared memory segment
        char newmsg[MSGSIZE] = "Goodbye!";
        strcpy(shm, newmsg);

        exit(0);
    }
    else { /* parent process */
        wait(NULL);

        //reading the message from the shared memory segment again
        printf("Parent process reads: ");
        for (s = shm; *s != '\0'; s++) {
            putchar(*s);
        }
        putchar('\n');

        //detaching the shared memory segment from our data space
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        //deleting the shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}