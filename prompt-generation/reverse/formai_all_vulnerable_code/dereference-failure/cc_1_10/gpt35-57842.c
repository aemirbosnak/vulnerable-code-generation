//FormAI DATASET v1.0 Category: Interprocess communication ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHMSIZE 100

int main(){

  /* Declaring Variables */
    pid_t pid;
    int shmid;
    key_t key;
    char *shm;
    char *message = "Hello, World!";

    /* Creating a shared memory segment using a key */
    key = 1234;
    shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666);
    if(shmid < 0){
        perror("shmget");
        exit(1);
    }

    /* Attaching to shared memory segment */
    shm = shmat(shmid, NULL, 0);
    if(shm == (char *)-1){
        perror("shmat");
        exit(1);
    }

    /* Coping message to shared memory segment */
    memcpy(shm, message, strlen(message));
    printf("Message written to shared memory: %s\n", shm);

    /* Forking a child process */
    pid = fork();

    /* Error handling */
    if(pid < 0){
        perror("fork");
        exit(1);
    }

    /* In the child process */
    if(pid == 0){
        /* Waiting for parent process to write message to shared memory */
        sleep(2);
        printf("Message read from shared memory: %s\n", shm);
        /* Detaching from shared memory segment */
        if(shmdt(shm) == -1){
            perror("shmdt");
            exit(1);
        }
        /* Removing shared memory segment */
        if(shmctl(shmid, IPC_RMID, NULL) == -1){
            perror("shmctl");
            exit(1);
        }
        exit(0);
    }

    /* In the parent process */
    else{
        wait(NULL);
        /* Detaching from shared memory segment */
        if(shmdt(shm) == -1){
            perror("shmdt");
            exit(1);
        }
        /* Removing shared memory segment */
        if(shmctl(shmid, IPC_RMID, NULL) == -1){
            perror("shmctl");
            exit(1);
        }
        exit(0);
    } 

    return 0;
}