//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define TRUE 1
#define FALSE 0
#define SHM_KEY 1234
#define SHM_SIZE 1024

int shmid;
char *shmaddr;

int main() {
    int i;
    pid_t pid;
    int status;

    // create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // attach shared memory segment to process address space
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // initialize shared memory segment
    for (i = 0; i < SHM_SIZE; i++) {
        *(shmaddr + i) = 0;
    }

    // fork child process
    pid = fork();
    if (pid == -1) {
        printf("Error forking child process\n");
        exit(1);
    } else if (pid == 0) {
        // child process writes to shared memory segment
        for (i = 0; i < SHM_SIZE; i++) {
            *(shmaddr + i) = i;
        }
        printf("Child process completed\n");
        exit(0);
    } else {
        // parent process reads from shared memory segment
        waitpid(pid, &status, 0);
        for (i = 0; i < SHM_SIZE; i++) {
            printf("%d ", *(shmaddr + i));
        }
        printf("\n");

        // detach shared memory segment from process address space
        if (shmdt(shmaddr) == -1) {
            printf("Error detaching shared memory segment\n");
            exit(1);
        }

        // delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            printf("Error deleting shared memory segment\n");
            exit(1);
        }
    }

    return 0;
}