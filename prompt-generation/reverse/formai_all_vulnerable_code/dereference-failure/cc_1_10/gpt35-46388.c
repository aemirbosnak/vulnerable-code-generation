//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Ada Lovelace
//Weaving memories of processes, Ada Lovelace created a program
//To communicate between them, a masterpiece was made 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSIZE 27

//Creating the shared memory key
const char *shared_memory_key = "Ada";

int main(int argc, char const *argv[])
{
    //Declaring variable
    char data[SHMSIZE];
    void *shared_memory = (void *) 0;
    int shmid;
    pid_t pid;
    
    //Checking if memory exists and creating it if needed
    shmid = shmget((key_t) shared_memory_key, SHMSIZE, 0666|IPC_CREAT);
    
    //Checking for errors during the memory creation
    if (shmid == -1)
    {
        perror("Error with shared memory creation");
        exit(EXIT_FAILURE);
    }
    
    //Attaching shared memory to process
    shared_memory = shmat(shmid, (void *)0, 0);
    
    //Checking for errors during attaching process
    if (shared_memory == (void *)-1 )
    {
        perror("Error attaching shared memory to process");
        exit(EXIT_FAILURE);
    }
    
    printf("Shared memory attached at %p\n", shared_memory);
    
    //Forking process
    pid = fork();
    
    //Checking for errors during forking process
    if (pid == -1) {
        perror("Failed to fork process");
        exit(EXIT_FAILURE);
    }
    
    //Child process functions
    if (pid == 0) {
        printf("Enter message to be sent to parent process:\n");
        fgets(data, SHMSIZE, stdin);
        
        //Copying data into shared memory
        strcpy(shared_memory, data);
        exit(EXIT_SUCCESS);
    }
    
    //Waiting for child process to finish
    wait(&pid);
    
    //Parent process functions
    if (pid > 0) {
        printf("Message received from child process: %s\n", (char*) shared_memory);
    }
    
    //Detaching shared memory
    if (shmdt(shared_memory) == -1)
    {
        perror("Error detaching shared memory");
        exit(EXIT_FAILURE);
    }
    
    //Deleting shared memory
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("Error deleting shared memory");
        exit(EXIT_FAILURE);
    }
    
    exit(EXIT_SUCCESS);
}