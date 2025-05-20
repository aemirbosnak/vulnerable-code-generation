//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

#define SHM_KEY 1234
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shm;
    pid_t pid;

    // create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // attach shared memory segment to process
    shm = (char *)shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // initialize shared memory
    strcpy(shm, "Hello, world!");

    // fork child process
    pid = fork();
    if (pid == -1) {
        printf("Error forking child process\n");
        exit(1);
    } else if (pid == 0) {
        // child process
        sleep(1); // give parent time to write to shared memory

        // read from shared memory
        printf("Child: %s\n", shm);

        // detach shared memory segment
        if (shmdt(shm) == -1) {
            printf("Error detaching shared memory segment\n");
            exit(1);
        }

        // exit child process
        exit(0);
    } else {
        // parent process
        sleep(1); // give child time to read from shared memory

        // write to shared memory
        strcpy(shm, "Goodbye, child!");

        // detach shared memory segment
        if (shmdt(shm) == -1) {
            printf("Error detaching shared memory segment\n");
            exit(1);
        }

        // wait for child process to exit
        wait(NULL);

        // delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            printf("Error deleting shared memory segment\n");
            exit(1);
        }
    }

    return 0;
}