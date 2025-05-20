//FormAI DATASET v1.0 Category: Interprocess communication ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main()
{
    printf("Welcome to the Interprocess Communication festival!\n");
    printf("We've got some mad skills in this joint!\n\n");

    pid_t pid;
    key_t key;
    int shmid;
    char* shared_memory;
    int* data;

    // Let's create the shared memory segment

    key = ftok("communication.c", 'R');
    shmid = shmget(key, sizeof(int), 0644 | IPC_CREAT);

    if (shmid == -1) {
        printf("Oops! Something went wrong while trying to create the shared memory segment...\n");
        exit(EXIT_FAILURE);
    }

    // Time for the parent process to fork

    pid = fork();

    if (pid == -1) {
        printf("Uh-oh! Fork failed...\n");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // The child process gets down to work

        shared_memory = (char*) shmat(shmid, NULL, 0);

        if (shared_memory == (void*) -1) {
            printf("Huh, we couldn't get the memory attached...\n");
            exit(EXIT_FAILURE);
        }

        printf("Child process: I've attached the shared memory! Let's write something.\n");
        printf("Child process: I'm writing 'Hello' to the shared memory segment.\n");

        data = (int*) shared_memory;
        *data = 42; // Because why not?

        printf("Child process: Writing complete! Time to detach...\n");

        shmdt(shared_memory); // Detach from the shared memory segment

        printf("Child process: Detached from the shared memory segment! Bye bye!\n");

        exit(EXIT_SUCCESS);

    } else { // The parent process waits for the child to finish

        wait(NULL); // Wait for the child to die

        printf("\nParent process: The child is dead, Jim...\n");
        printf("Parent process: Let me just attach to the shared memory segment...\n");

        shared_memory = (char*) shmat(shmid, NULL, 0);

        if (shared_memory == (void*) -1) {
            printf("Gah! Couldn't attach to the shared memory segment...Maybe the child didn't create it?\n");
            exit(EXIT_FAILURE);
        }

        printf("Parent process: I see that the child wrote '%d' in the shared memory segment! Pretty cool!\n", *data);

        printf("Parent process: Detaching from the shared memory segment...\n");

        shmdt(shared_memory);

        printf("Parent process: Detached! Time to destroy the shared memory segment.\n");

        shmctl(shmid, IPC_RMID, NULL);

        printf("Parent process: Done! That was fun!\n");
    }

    return 0;
}