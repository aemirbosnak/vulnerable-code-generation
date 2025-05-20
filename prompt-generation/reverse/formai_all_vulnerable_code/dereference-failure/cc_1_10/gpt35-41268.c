//FormAI DATASET v1.0 Category: Interprocess communication ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>

#define SHM_KEY 1234
#define SHM_SIZE 1024

void parent_process(int *buffer){
    printf("Enter a message for the child process: ");
    char message[SHM_SIZE];
    fgets(message, SHM_SIZE, stdin);
    memcpy(buffer, message, SHM_SIZE);
    wait(NULL);
    printf("The message received from the child process is: %s\n", (char*)buffer);
}

void child_process(int *buffer){
    sleep(1); //wait for parent to write to memory buffer
    printf("The message received from the parent process is: %s\n", (char*)buffer);

    char response[SHM_SIZE] = "Message received from parent process.";
    memcpy(buffer, response, SHM_SIZE);
}

int main(){
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if(shmid == -1){
        perror("Error in creating shared memory segment.\n");
        exit(1);
    }

    void* memory = shmat(shmid, NULL, 0);
    if(memory == (void*) -1){
        perror("Error in attaching shared memory segment.\n");
        exit(2);
    }

    int *buffer = (int*) memory;

    pid_t pid = fork();
    if(pid == -1){
        perror("Error in forking processes.\n");
        exit(3);
    }
    else if(pid == 0){ //child process
        child_process(buffer);
    }
    else{ //parent process
        parent_process(buffer);
    }

    if(shmdt(memory) == -1){
        perror("Error in detaching shared memory segment.\n");
        exit(4);
    }

    if(shmctl(shmid, IPC_RMID, NULL) == -1){
        perror("Error in removing shared memory segment.\n");
        exit(5);
    }

    return 0;
}