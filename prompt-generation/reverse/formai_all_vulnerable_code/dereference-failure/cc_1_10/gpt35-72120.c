//FormAI DATASET v1.0 Category: Interprocess communication ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    // Create the shared memory segment
    key_t key = ftok("ipcdemo", 'R');
    int memid = shmget(key, 1024, 0666|IPC_CREAT);

    if(memid == -1) {
        perror("Unable to create shared memory segment");
        exit(1);
    }

    // Attach to the shared memory segment
    char *sharedMem = (char*)shmat(memid, NULL, 0);

    if(sharedMem == (char*)-1) {
        perror("Unable to attach to shared memory segment");
        exit(1);
    }

    // Write a message to the shared memory segment
    strcpy(sharedMem, "Hello, Interprocess Communication!");

    printf("Wrote the following message to the shared memory segment: \n%s\n", sharedMem);

    // Detach from the shared memory segment
    shmdt(sharedMem);

    // Create a child process to read the message
    pid_t childPid = fork();

    if(childPid == -1) {
        perror("Unable to fork child process");
        exit(1);
    }

    if(childPid == 0) { // Child process
        // Attach to the shared memory segment
        char *sharedMem = (char*)shmat(memid, NULL, 0);

        printf("\nChild Process read the following message from the shared memory segment:\n%s\n", sharedMem);

        // Detach from the shared memory segment
        shmdt(sharedMem);

        // Clean up the shared memory segment
        shmctl(memid, IPC_RMID, NULL);

        printf("\nChild Process finished cleaning up the shared memory segment and terminating!\n");

        exit(0);
    }
    else { // Parent process
        printf("\nParent Process created Child Process with PID %d to read the message from the shared memory segment!\n", childPid);
    }

    return 0;
}