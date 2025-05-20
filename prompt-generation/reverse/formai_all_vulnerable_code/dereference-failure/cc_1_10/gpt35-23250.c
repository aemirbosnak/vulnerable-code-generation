//FormAI DATASET v1.0 Category: Interprocess communication ; Style: happy
//This program demonstrates interprocess communication using shared memory between two processes, "sender" and "receiver"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHM_SIZE 1024

int main(){
    int shmid, pid;
    char *shm, *s;

    //create shared memory
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0){
        printf("Failed to create shared memory\n");
        exit(1);
    }

    //fork process
    pid = fork();
    if (pid == 0){
        //child process (receiver)

        //attach shared memory
        shm = shmat(shmid, NULL, 0);
        if (shm == (char *) -1){
            printf("Failed to attach shared memory\n");
            exit(1);
        }

        //wait for sender to write message
        while (*shm == ' '){
            sleep(1);
        }

        //print message received from sender
        for (s = shm; *s != ' '; s++){
            putchar(*s);
        }
        putchar('\n');

        //detach shared memory
        shmdt(shm);

        //delete shared memory
        shmctl(shmid, IPC_RMID, NULL);

        printf("Message received successfully!\n");
    }
    else if (pid > 0){
        //parent process (sender)

        //attach shared memory
        shm = shmat(shmid, NULL, 0);
        if (shm == (char *) -1){
            printf("Failed to attach shared memory\n");
            exit(1);
        }

        //write message to shared memory
        sprintf(shm, "Hello, World!");

        //detach shared memory
        shmdt(shm);

        printf("Message sent successfully!\n");
    }
    else {
        //failed to fork
        printf("Failed to fork process\n");
        exit(1);
    }

    return 0;
}