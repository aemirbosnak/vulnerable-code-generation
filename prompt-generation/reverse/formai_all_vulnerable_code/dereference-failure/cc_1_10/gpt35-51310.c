//FormAI DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 100

int main(void) {
    pid_t pid;
    int shmid;
    char *shm, *s;
    key_t key = 88888;
    char message[SHM_SIZE];

    // create shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // attach the shared memory segment to our data space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // fork a child process
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    } else if (pid > 0) {
        // parent process
        printf("Enter a message: ");
        fgets(message, SHM_SIZE, stdin);

        // write the message to shared memory
        memcpy(shm, message, strlen(message));
        printf("Message sent to child process.\n");

        // wait for child process to exit
        wait(NULL);

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

        printf("Shared memory segment deleted.\n");
    } else {
        // child process
        printf("Child process waiting for message...\n");

        // read the message from shared memory
        for (s = shm; *s == NULL; s++)
            ;
        printf("Message received: %s", s);

        // detach the shared memory segment
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        exit(0);
    }

    return 0;
}