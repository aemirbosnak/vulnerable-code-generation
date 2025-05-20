//FormAI DATASET v1.0 Category: Interprocess communication ; Style: calm
//This interprocess communication program demonstrates the use of shared memory
//The parent process creates a shared memory segment and writes a message into it
//The child process reads the message from the shared memory segment and displays it
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    pid_t pid;
    char *msg = "Hello World!\n";

    //Create a shared memory segment
    int shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);

    if (shmid < 0) {
        perror("Failed to create shared memory segment");
        exit(1);
    }

    //Fork the process
    pid = fork();
    if (pid < 0) {
        perror("Failed to fork process");
        exit(1);
    }

    if (pid > 0) { //Parent process
        char *shm = (char *) shmat(shmid, NULL, 0); //Attach the shared memory segment to parent process

        if (shm == (char *) -1) {
            perror("Failed to attach shared memory segment to parent process");
            exit(1);
        }

        strcpy(shm, msg); //Write the message into shared memory

        printf("Parent process wrote \"%s\" to shared memory\n", msg);

        wait(NULL); //Wait for child process to finish
        shmdt(shm); //Detach the shared memory segment from parent process
        shmctl(shmid, IPC_RMID, NULL); //Remove (delete) the shared memory segment
        exit(0);
    } else { //Child process
        char *shm = (char *) shmat(shmid, NULL, 0); //Attach the shared memory segment to child process

        if (shm == (char *) -1) {
            perror("Failed to attach shared memory segment to child process");
            exit(1);
        }

        printf("Child process read \"%s\" from shared memory\n", shm);

        shmdt(shm); //Detach the shared memory segment from child process
        exit(0);
    }
}