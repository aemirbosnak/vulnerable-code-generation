//FormAI DATASET v1.0 Category: Interprocess communication ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <sys/wait.h>

#define SHM_KEY 1234
#define SHM_SIZE 1024

int main() {
    pid_t pid; 
    int shmid, status; 
    char *shm_ptr;

    // create a shared memory segment
    if ((shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // attach the shared memory segment to the process
    if ((shm_ptr = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // fork a child process
    pid = fork();

    if (pid == 0) {
        // child process
        printf("Child process waiting for input...\n");
        fflush(stdout);
        if (fgets(shm_ptr, SHM_SIZE, stdin) == NULL) {
            perror("fgets");
            exit(1);
        }

        // write message to shared memory
        shm_ptr[strlen(shm_ptr) - 1] = '\0';
        printf("Child process writing message: %s\n", shm_ptr);
        fflush(stdout);
        strcpy(shm_ptr, "Hello parent process!");

        // detach shared memory segment from child process
        if (shmdt(shm_ptr) == -1) {
            perror("shmdt");
            exit(1);
        }

        // exit child process
        exit(0);
    } else if (pid > 0) {
        // parent process
        printf("Enter a message for the child process: ");
        fflush(stdout);

        // wait for child process to write message to shared memory
        wait(&status);
        printf("Parent process reading message: %s\n", shm_ptr);
        fflush(stdout);

        // detach shared memory segment from parent process
        if (shmdt(shm_ptr) == -1) {
            perror("shmdt");
            exit(1);
        }

        // delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
        
        // exit parent process
        exit(0);
    } else {
        // fork error
        perror("fork");
        exit(1);
    }
}