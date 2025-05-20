//FormAI DATASET v1.0 Category: Interprocess communication ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    printf("OMG!!!! Interprocess Communication is such an amazing feature of C!!!!\n");
    printf("I'm so excited to show you a unique program using it!!\n");

    int shmid;
    key_t key;
    char *shm, *s;

    if ((key = ftok(".", 'A')) == -1) {
        printf("Oh no! Unable to create key\n");
        exit(1);
    }

    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
        printf("Oh no! Unable to create shared memory space\n");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        printf("Oh no! Unable to access shared memory space\n");
        exit(1);
    }

    printf("Yay! Successfully created shared memory space with ID %d\n", shmid);

    s = shm;

    printf("Please enter a message into the shared memory:\n");

    fgets(s, SHM_SIZE, stdin);

    printf("Sending message to the other process....\n");

    pid_t pid = fork();

    if (pid < 0) {
        printf("Oh no! Unable to create child process\n");
        exit(1);
    } else if (pid == 0) {
        printf("This is the child process. Receiving message....\n");
        s = shm;
        printf("Received message: %s\n", s);
        exit(0);
    } else {
        printf("This is the parent process. Waiting for child to complete...\n");
        wait(NULL); // wait for child process to complete 
    }

    printf("Yay! Successfully communicated message between processes using shared memory!!\n");

    if (shmdt(shm) == -1) {
        printf("Oh no! Error detaching shared memory\n");
        exit(1);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Oh no! Error removing shared memory\n");
        exit(1);
    }

    printf("Shared memory successfully detached and removed!!!!\n");

    return 0;
}