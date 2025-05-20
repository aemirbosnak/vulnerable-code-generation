//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 1024

// create a shared memory segment
int shmid;
char *shmaddr;

void init_shm() {
    int shmflg = IPC_CREAT | 0666;
    key_t key = ftok("/dev/tty", 65);
    shmid = shmget(key, SIZE, shmflg);
    if (shmid == -1) {
        printf("Error: could not create shared memory segment\n");
        exit(1);
    }
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) - 1) {
        printf("Error: could not attach to shared memory segment\n");
        exit(1);
    }
    memset(shmaddr, 0, SIZE);
}

// fork a child process
int child_pid;

void fork_child() {
    child_pid = fork();
    if (child_pid == -1) {
        printf("Error: could not fork child process\n");
        exit(1);
    } else if (child_pid == 0) {
        // child process
        printf("Child process started\n");
        sleep(1);
        printf("Child process exiting\n");
        exit(0);
    } else {
        // parent process
        printf("Child process ID: %d\n", child_pid);
        wait(NULL);
        printf("Child process exited\n");
    }
}

// main function
int main() {
    init_shm();
    printf("Shared memory segment created\n");
    printf("Enter a string (max %d characters): ", SIZE - 1);
    scanf("%s", shmaddr);
    printf("String entered: %s\n", shmaddr);
    fork_child();
    return 0;
}