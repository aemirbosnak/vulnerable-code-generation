//FormAI DATASET v1.0 Category: Interprocess communication ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define SHM_SIZE 1024  // Define shared memory size
#define PIPE_BUF 1024  // Define pipe buffer size

int main() {
    int shmid, pipefd[2], status;
    char *shm_ptr, pipe_buf[PIPE_BUF];
    pid_t pid;

    // Creating shared memory segment
    key_t key = ftok("shmfile",64);

    // Get the segment id
    shmid = shmget(key, SHM_SIZE, 0666|IPC_CREAT);

    // Attach shared memory segment
    shm_ptr = (char*) shmat(shmid,(void*)0,0);

    // Forking child process
    pid = fork();

    // Parent process
    if (pid > 0) {
        char *parent_msg = "Hello there, I am your parent process!";
        printf("Parent process writing to shared memory segment\n");

        // Write to shared memory segment
        strcpy(shm_ptr,parent_msg);
        wait(&status); // Wait for child process to complete

        printf("Parent process received message from child process via pipe\n");
        close(pipefd[1]); // Close write end of pipe

        // Read from pipe
        read(pipefd[0], pipe_buf, PIPE_BUF);
        printf("Message from child process: %s\n", pipe_buf);
    }

    // Child process
    else if (pid == 0) {
        char *child_msg = "Hey there, I am your child process!";
        printf("Child process reading from shared memory segment\n");

        // Read from shared memory segment
        printf("Message from parent process: %s\n",shm_ptr);
        close(pipefd[0]); // Close read end of pipe

        printf("Child process writing to parent process via pipe\n");
        // Write to pipe
        write(pipefd[1], child_msg, strlen(child_msg)+1);
        exit(0);
    }
    else {
        printf("Failed to fork.");
    }

    // Detach shared memory segment
    shmdt(shm_ptr);

    // Delete shared memory segment
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
}