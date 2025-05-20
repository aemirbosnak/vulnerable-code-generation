//FormAI DATASET v1.0 Category: Interprocess communication ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {

    printf("Oh my goodness, I never thought I would be able to witness interprocess communication in action!\n");
    printf("Let me show you a unique example program that will blow your mind off!\n");

    char* parent_message = "Hello there kiddo! I'm your parent process!";
    char* child_message = "Hey! I'm your child process!";

    int shmid = shmget(IPC_PRIVATE, 128, 0666 | IPC_CREAT); // creating a shared memory segment
    if (shmid < 0) {
        printf("Oops, something went wrong while creating the shared memory segment :(\n");
        exit(1);
    }

    int pid = fork(); // creating a new process
    if (pid < 0) {
        printf("Oops, something went wrong while forking the child process :(\n");
        exit(1);
    }

    if (pid > 0) { // parent process

        char* shared_memory = (char*)shmat(shmid, NULL, 0); // attaching the shared memory segment

        strcpy(shared_memory, parent_message); // writing the message to the shared memory segment

        printf("Parent process wrote \"%s\" to the shared memory segment!\n", parent_message);
        printf("Parent process is waiting for the child process to read from the shared memory segment...\n");

        sleep(5); // giving the child process enough time to read from the shared memory segment

        printf("Parent process is detaching from the shared memory segment and deleting it...\n");

        shmdt(shared_memory); // detaching from the shared memory segment
        shmctl(shmid, IPC_RMID, NULL); // deleting the shared memory segment

        printf("Parent process has successfully completed interprocess communication with the child process!\n");
        printf("This is so cool!\n");
    }

    else { // child process

        char* shared_memory = (char*)shmat(shmid, NULL, 0); // attaching the shared memory segment

        printf("Child process is waiting for the parent process to write to the shared memory segment...\n");

        sleep(2); // giving the parent process enough time to write to the shared memory segment

        printf("Child process read \"%s\" from the shared memory segment!\n", shared_memory);
        printf("Child process is writing \"%s\" to the shared memory segment...\n", child_message);

        strcpy(shared_memory, child_message); // writing the message to the shared memory segment

        printf("Child process has successfully sent the message to the parent process!\n");
        printf("This is so exciting!\n");

        shmdt(shared_memory); // detaching from the shared memory segment

        exit(0); // exiting the child process
    }

    return 0; // exiting the parent process
}