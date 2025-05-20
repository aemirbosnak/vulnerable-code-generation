//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SHM_KEY 12345
#define SHM_SIZE 1024

int main(int argc, char *argv[]) {
    int shmid;
    void *shmaddr;
    int pid, status;
    char *message = "Hello from parent process!";

    // Create shared memory segment
    if ((shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
        fprintf(stderr, "shmget failed\n");
        exit(1);
    }

    // Attach shared memory segment to process address space
    if ((shmaddr = shmat(shmid, NULL, 0)) == (void *) -1) {
        fprintf(stderr, "shmat failed\n");
        exit(1);
    }

    // Write message to shared memory
    strcpy(shmaddr, message);

    // Fork child process
    if ((pid = fork()) == -1) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }

    // Parent process waits for child to finish
    if (pid > 0) {
        waitpid(pid, &status, 0);
    }

    // Detach shared memory segment from process address space
    if (shmdt(shmaddr) == -1) {
        fprintf(stderr, "shmdt failed\n");
        exit(1);
    }

    // Destroy shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        fprintf(stderr, "shmctl failed\n");
        exit(1);
    }

    return 0;
}