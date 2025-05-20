//FormAI DATASET v1.0 Category: Interprocess communication ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<string.h>

#define SHMSIZE 1024 // size of shared memory

struct sharedMemory { // structure for shared memory
    int counter;
    char message[SHMSIZE];
    pid_t processID;
};

int main() {
    int shmid;
    pid_t childPID;

    char messageToSend[SHMSIZE];
    printf("Enter message to send: ");
    scanf("%s", messageToSend);

    // key generation
    key_t key = ftok("sharedMemoryExample.c", 'R');

    // shared memory creation
    shmid = shmget(key, sizeof(struct sharedMemory), 0666 | IPC_CREAT);

    if(shmid == -1) { // shared memory failed to create
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    struct sharedMemory *shmPTR = (struct sharedMemory *) shmat(shmid, NULL, 0);

    if(shmPTR == (void *) -1) { // shared memory failed to attach
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // write counter, message and process id to shared memory
    
    shmPTR->counter = 0;
    strcpy(shmPTR->message, messageToSend);
    shmPTR->processID = getpid();

    childPID = fork();

    if(childPID == -1) { // fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(childPID == 0) { // child process
        printf("In child process...\n");
        sleep(2);
        printf("Counter Changed by Child Process: %d \n", ++shmPTR->counter);

        printf("Message Sent by Child Process: %s \n", shmPTR->message);

        printf("Process ID of Child Process: %d \n", getpid());

        exit(0);
    }
    else { // parent process
        printf("In parent process...\n");
        wait(NULL);

        printf("Counter Changed by Parent Process: %d \n", ++shmPTR->counter);

        printf("Message Sent by Parent Process: %s \n", shmPTR->message);

        printf("Process ID of Parent Process: %d \n", getpid());
    }

    shmdt(shmPTR);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}