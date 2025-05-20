//FormAI DATASET v1.0 Category: Interprocess communication ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSIZE 1024

int main(){
    // key generation
    key_t key = ftok("chatbot", 'C');
    int shmid;

    // shared memory mapping
    char *shmaddr, *s;
    if((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0){
        perror("shmget");
        exit(1);
    }
    if((shmaddr = shmat(shmid, NULL, 0)) == (char*)-1){
        perror("shmat");
        exit(1);
    }

    printf("Shared Memory Successfully created.\n\n");

    // fork system call
    pid_t pid;
    pid = fork();

    if(pid < 0){
        perror("fork");
        exit(1);
    }

    // child process
    else if(pid == 0){
        printf("*** Child process %d is executing. *** \n\n", getpid());
        sleep(2);

        // message to parent process
        strcpy(shmaddr, "Hi parent process, it's me, your child process.");

        printf("%d - Child Process sends a message to the parent process successfully!\n\n", getpid());

        exit(0);
    }

    // parent process
    else{
        printf("*** Parent process %d is executing. ***\n\n", getpid());
        printf("%d - Waiting for the child process to send a message...\n\n", getpid());
        wait(NULL);

        printf("%d - Received message: %s\n\n", getpid(), shmaddr);

        // message to child process
        strcpy(shmaddr, "Hi child process, it's me, your parent process.");

        printf("%d - Parent Process sends a message to the child process successfully!\n\n", getpid());

        // detach shared memory
        shmdt(shmaddr);

        // remove shared memory
        shmctl(shmid, IPC_RMID, NULL);

        printf("*** Shared Memory Successfully Removed ***\n\n");
    }

    return 0;
}