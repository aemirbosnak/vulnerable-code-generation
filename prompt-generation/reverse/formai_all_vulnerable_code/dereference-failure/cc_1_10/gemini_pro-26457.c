//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

#define SHM_SIZE 1024  // size of shared memory segment

int main() {
    // create a shared memory segment
    int shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0600);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // attach the shared memory segment to our address space
    void *shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // set up a pipe for communication between processes
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    // fork a child process
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }

    if (child_pid == 0) {  // child process
        // close the write end of the pipe
        close(pipefd[1]);

        // read data from the shared memory segment
        char *data = (char *)shmptr;
        printf("Child process: %s\n", data);

        // send the data to the parent process via the pipe
        write(pipefd[0], data, strlen(data) + 1);

        // detach the shared memory segment from our address space
        shmdt(shmptr);

        // close the read end of the pipe
        close(pipefd[0]);

        // exit the child process
        exit(0);
    } else {  // parent process
        // close the read end of the pipe
        close(pipefd[0]);

        // write data to the shared memory segment
        char *data = "Hello from the parent process!";
        memcpy(shmptr, data, strlen(data) + 1);

        // wait for the child process to finish
        wait(NULL);

        // read data from the pipe
        char buf[SHM_SIZE];
        read(pipefd[1], buf, SHM_SIZE);

        // print the data
        printf("Parent process: %s\n", buf);

        // detach the shared memory segment from our address space
        shmdt(shmptr);

        // close the write end of the pipe
        close(pipefd[1]);

        // delete the shared memory segment
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}