//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_KEY 12345
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shm;
    pid_t pid;

    //Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    //Attach to shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        printf("Error attaching to shared memory segment\n");
        exit(2);
    }

    //Initialize shared memory
    strcpy(shm, "Hello, World!");

    //Create child process
    pid = fork();
    if (pid == -1) {
        printf("Error forking\n");
        exit(3);
    } else if (pid == 0) {
        //Child process
        printf("Child process started\n");

        //Detach from shared memory segment
        if (shmdt(shm) == -1) {
            printf("Error detaching from shared memory segment\n");
            exit(4);
        }

        //Exit child process
        exit(0);
    } else {
        //Parent process
        wait(NULL);

        //Detach from shared memory segment
        if (shmdt(shm) == -1) {
            printf("Error detaching from shared memory segment\n");
            exit(5);
        }

        //Delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            printf("Error deleting shared memory segment\n");
            exit(6);
        }

        exit(0);
    }

    return 0;
}