//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x1234
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shm;
    pid_t pid;

    /* Create shared memory segment */
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error: shmget failed\n");
        exit(1);
    }

    /* Attach shared memory segment */
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        printf("Error: shmat failed\n");
        exit(1);
    }

    /* Fork child process */
    pid = fork();
    if (pid == -1) {
        printf("Error: fork failed\n");
        exit(1);
    } else if (pid == 0) {
        /* Child process */
        char *child_shm = shmat(shmid, NULL, 0);
        if (child_shm == (char *)-1) {
            printf("Error: shmat failed in child process\n");
            exit(1);
        }

        /* Modify shared memory in child process */
        strcpy(child_shm, "Child process modified shared memory");

        /* Detach shared memory segment */
        if (shmdt(child_shm) == -1) {
            printf("Error: shmdt failed in child process\n");
            exit(1);
        }

        /* Exit child process */
        exit(0);
    } else {
        /* Parent process */
        sleep(1);

        /* Modify shared memory in parent process */
        strcpy(shm, "Parent process modified shared memory");

        /* Detach shared memory segment */
        if (shmdt(shm) == -1) {
            printf("Error: shmdt failed in parent process\n");
            exit(1);
        }

        /* Wait for child process to exit */
        waitpid(pid, NULL, 0);

        /* Detach shared memory segment */
        if (shmdt(shm) == -1) {
            printf("Error: shmdt failed in parent process\n");
            exit(1);
        }
    }

    return 0;
}