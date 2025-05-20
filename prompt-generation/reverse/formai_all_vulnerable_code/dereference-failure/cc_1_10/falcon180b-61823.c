//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x12345
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shm;

    // create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Failed to create shared memory segment\n");
        exit(1);
    }

    // attach to shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        printf("Failed to attach to shared memory segment\n");
        exit(1);
    }

    // write to shared memory
    strcpy(shm, "Hello, World!");

    // fork a child process
    pid_t pid = fork();
    if (pid == -1) {
        printf("Failed to fork process\n");
        exit(1);
    }

    // if child process
    if (pid == 0) {
        // read from shared memory
        printf("Child: %s\n", shm);

        // detach from shared memory
        if (shmdt(shm) == -1) {
            printf("Failed to detach from shared memory segment\n");
            exit(1);
        }

        // exit child process
        exit(0);
    }

    // if parent process
    else {
        // wait for child process to exit
        wait(NULL);

        // detach from shared memory
        if (shmdt(shm) == -1) {
            printf("Failed to detach from shared memory segment\n");
            exit(1);
        }

        // delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            printf("Failed to delete shared memory segment\n");
            exit(1);
        }
    }

    return 0;
}