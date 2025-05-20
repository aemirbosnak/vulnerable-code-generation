//FormAI DATASET v1.0 Category: Interprocess communication ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main(){

    char parent_msg[SHM_SIZE], child_msg[SHM_SIZE];
    int shmid, pid;

    shmid = shmget(IPC_PRIVATE, SHM_SIZE, 0666);

    if(shmid < 0){
        printf("Error creating shared memory segment");
        exit(-1);
    }

    pid = fork();   //Create a child process

    if(pid < 0){
        printf("Error creating child process");
        exit(-1);
    }

    if(pid > 0){    //Parent
        printf("Enter a message for the child process:\n");
        fgets(parent_msg, SHM_SIZE, stdin);

        char *shared_mem = (char *)shmat(shmid, NULL, 0);    //Attach shared memory

        if(shared_mem == (char *)-1){
            printf("Error attaching shared memory segment");
            exit(-1);
        }

        strcpy(shared_mem, parent_msg); //Copy message to shared memory

        sleep(2);   //Wait for child to read the message

        printf("Parent: Received message from child: \"%s\"\n", shared_mem);

        shmdt(shared_mem);  //Detach shared memory

        shmctl(shmid, IPC_RMID, NULL);  //Delete shared memory segment
    }

    else{   //Child
        char *shared_mem = (char *)shmat(shmid, NULL, 0);    //Attach shared memory

        if(shared_mem == (char *)-1){
            printf("Error attaching shared memory segment");
            exit(-1);
        }

        sleep(1);   //Wait for parent to write to shared memory

        printf("Child: Received message from parent: \"%s\"\n", shared_mem);

        printf("Enter a message for the parent process:\n");
        fgets(child_msg, SHM_SIZE, stdin);

        strcpy(shared_mem, child_msg);  //Copy message to shared memory

        shmdt(shared_mem);  //Detach shared memory
    }

    return 0;
}