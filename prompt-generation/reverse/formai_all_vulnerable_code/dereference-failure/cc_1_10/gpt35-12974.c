//FormAI DATASET v1.0 Category: Interprocess communication ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    printf("Hello everyone, welcome to the IPC program!\n");

    // creating a shared memory segment
    int shmid = shmget(IPC_PRIVATE, sizeof(char) * 100, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Oh no! Shared memory segment creation has failed!\n");
        exit(1);
    }

    printf("Great! Shared memory segment has been created! Its ID is: %d\n", shmid);

    char *shmaddr = (char*) shmat(shmid, 0, 0);
    if (shmaddr == (char*)-1) {
        printf("Uh oh! There was an error attaching to the shared memory segment!\n");
        exit(1);
    }

    printf("Hooray! Attached to the shared memory segment. Here we go!\n");

    pid_t pid;
    pid = fork();

    if (pid < 0) {
        printf("Oops! There was an error creating a child process.\n");
        exit(1);
    }

    if (pid == 0) {
        // child process writes to the shared memory segment
        printf("I'm the child process and I'm writing to the shared memory segment!\n");
        char *msg = "Hello from the child process!";

        // copy the message into the shared memory segment
        strncpy(shmaddr, msg, strlen(msg));

        printf("Success! Sent %s to the parent process through shared memory.\n", msg);
        exit(0);
    } else {
        // parent process reads from the shared memory segment
        printf("I'm the parent process and I'm reading from the shared memory segment.\n");
        wait(NULL);

        char buffer[100];

        // copy the message into the buffer
        strncpy(buffer, shmaddr, strlen(shmaddr));

        printf("Yay! Received \"%s\" from the child process through shared memory.\n", buffer);

        // detach from shared memory
        shmdt(shmaddr);

        printf("Shared memory segment has been detached from the parent process.\n");

        // delete the shared memory segment
        shmctl(shmid, IPC_RMID, NULL);

        printf("Shared memory segment has been deleted successfully! Finishing up...\n");
        exit(0);
    }

    return 0;
}