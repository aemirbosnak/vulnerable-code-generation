//FormAI DATASET v1.0 Category: Interprocess communication ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHMSIZE 1024

int main(int argc, char *argv[]) {

    // Create shared memory segment
    int shmid;
    char *shmaddr;
    key_t keyval;

    keyval = 1234;

    if ((shmid = shmget(keyval, SHMSIZE, IPC_CREAT | 0666)) < 0) {
        fprintf(stderr, "Error creating shared memory\n");
        exit(1);
    }

    // Attach shared memory segment
    if ((shmaddr = shmat(shmid, NULL, 0)) == (char *) -1) {
        fprintf(stderr, "Error attaching shared memory\n");
        exit(1);
    }

    // Write data to shared memory
    printf("Enter data to write to shared memory: ");
    fgets(shmaddr, SHMSIZE, stdin);
    
    // Create child process
    pid_t pid;
    pid = fork();

    if (pid == 0) { // Child process
        printf("Child process reading from shared memory\n");

        // Read data from shared memory
        printf("Data read from shared memory: %s", shmaddr);

        // Detach shared memory segment
        if (shmdt(shmaddr) == -1) {
            fprintf(stderr, "Error detaching shared memory\n");
            exit(1);
        }
        exit(0);
    } else if (pid > 0) { // Parent process
        printf("Waiting for child process to terminate\n");

        // Wait for child process to terminate
        int status;
        waitpid(pid, &status, 0);

        // Delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            fprintf(stderr, "Error deleting shared memory\n");
            exit(1);
        }
    } else { // Error forking
        fprintf(stderr, "Error forking\n");
        exit(1);
    }

    return 0;
}