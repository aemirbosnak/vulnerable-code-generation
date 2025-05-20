//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <string.h>

#define SHM_SIZE 1024  // size of shared memory segment

int main() {
    // create and initialize shared memory segment
    int shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    if (shm_id == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // attach shared memory segment to process's address space
    char *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // initialize shared memory segment with a message
    strcpy(shm_ptr, "Hello from parent process!");

    // create a child process
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // child process reads and prints the message from shared memory segment
    if (child_pid == 0) {
        printf("Child process: %s\n", shm_ptr);
        exit(EXIT_SUCCESS);
    }

    // parent process waits for child process to finish
    int status;
    waitpid(child_pid, &status, 0);

    // detach shared memory segment from process's address space
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    // destroy shared memory segment
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}