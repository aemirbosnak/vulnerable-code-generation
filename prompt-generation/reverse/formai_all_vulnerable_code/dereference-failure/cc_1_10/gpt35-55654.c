//FormAI DATASET v1.0 Category: Interprocess communication ; Style: happy
// Let's have some fun with interprocess communication in C!
// These processes are gonna be the happiest!

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main()
{
    key_t key;
    char *shm, *s;

    // Generate a key for shared memory
    if ((key = ftok("happy_program", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Create the shared memory segment
    int shmid;
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the program's address space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write a happy message to the shared memory
    strcpy(shm, "Hello from the happiest process!");

    // Spawn a child process
    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }

    // In the child process, read from the shared memory and print out the message
    if (pid == 0) {
        s = shm;
        while (*s != '\0')
            putchar(*s++);
        putchar('\n');
        exit(0);
    }

    // Wait for the child process to exit
    int status;
    if (wait(&status) == -1) {
        perror("wait");
        exit(1);
    }

    // Detach and remove the shared memory segment
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    printf("All processes completed successfully! Happy coding!\n");

    return 0;
}