//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int shmid;
    char *shmaddr;
    int pid;
    int status;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        fprintf(stderr, "shmget failed\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        fprintf(stderr, "shmat failed\n");
        exit(1);
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        *shmaddr = 42;
        printf("Child wrote 42 to shared memory\n");
    } else {
        // Parent process
        waitpid(pid, &status, 0);
        printf("Parent read %d from shared memory\n", *shmaddr);
    }

    // Detach shared memory segment from process
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