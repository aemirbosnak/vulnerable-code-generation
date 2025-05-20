//FormAI DATASET v1.0 Category: Interprocess communication ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

/* Function to handle child process */
void child_process(int shmid) {
    char *data = (char*) shmat(shmid, NULL, 0);
    sleep(2);
    printf("\nChild process received the message: %s\n", data);
    strcpy(data, "Hello Parent, I am your child!");
    shmdt(data);
    exit(0);
}

/* Function to handle parent process */
void parent_process(int shmid) {
    char *data = (char*) shmat(shmid, NULL, 0);
    strcpy(data, "Hello Child, I am your parent!");
    printf("\nParent process sent the message: %s\n", data);
    sleep(2);
    printf("\nWaiting for child process to respond...\n");
    wait(NULL);
    printf("\nParent process received the message: %s\n", data);
    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);
}

int main() {
    /* Shared memory key */
    key_t key = ftok("shmfile",65);

    /* Shared memory id */
    int shmid = shmget(key,SHM_SIZE,0666|IPC_CREAT);

    /* Handling errors while getting Shared Memory ID */
    if (shmid < 0) {
        printf("\nFailed to create shared memory segment\n");
        return 1;
    }
    
    /* Forking a child process */
    pid_t pid = fork();

    /* Handling errors while forking */
    if (pid < 0) {
        printf("\nFailed to Fork Child Process\n");
        return 1;
    }
    
    /* Child process */
    if (pid == 0) {
        child_process(shmid);
    }

    /* Parent process */
    else {
        parent_process(shmid);
    }

    return 0;
}