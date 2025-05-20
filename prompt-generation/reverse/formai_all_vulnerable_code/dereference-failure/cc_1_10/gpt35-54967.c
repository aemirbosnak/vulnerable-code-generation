//FormAI DATASET v1.0 Category: Interprocess communication ; Style: puzzling
/* 
A puzzle program for interprocess communication between two processes
Purpose: To make the two processes communicate each other by passing a message using shared memory
*/

#include <stdio.h>  
#include <stdlib.h>
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/ipc.h>  
#include <sys/shm.h>  

#define SHM_SIZE 1024  //size of the shared memory segment

int main()
{
    int shmid;  //shared memory id
    key_t key = 5678; //a unique key to identify the shared memory segment
    
    //creating the shared memory segment
    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if(shmid == -1)
    {
        printf("Error creating the shared memory segment!\n");
        exit(1);
    }

    printf("Shared memory segment created successfully, shmid=%d\n", shmid);
    
    //attaching the shared memory segment to the current process address space
    char *shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (char *) -1)
    {
        printf("Error attaching the shared memory segment!\n");
        exit(1);
    }

    printf("Shared memory segment attached successfully, shm_ptr=%p\n", shm_ptr);

    //putting a message in the shared memory segment
    char message[20] = "Hello World!";
    sprintf(shm_ptr, message);

    printf("Message '%s' put in shared memory segment, waiting for other process to read...\n", message);

    //forking a new process
    pid_t pid = fork();
    if (pid < 0) //error occurred
    {
        printf("Fork failed!\n");
        exit(1);
    }
    else if (pid == 0) //child process
    {
        while (*shm_ptr != '*') //waiting for the message indicator to be set
        {
            sleep(1);
        }

        printf("Message received from the parent process: %s\n", shm_ptr+1);
        sprintf(shm_ptr, "*done*"); //confirming the message has been received
        
        //detaching the shared memory segment from the child process address space
        if(shmdt(shm_ptr) == -1)
        {
            printf("Error detaching the shared memory segment from the child process!\n");
            exit(1);
        }
        
        printf("Shared memory segment detached from the child process successfully.\n");
    }
    else //parent process
    {
        sleep(5); //waiting a bit before checking if the message has been read
        if (*shm_ptr == '*')
        {
            printf("Message received confirmation received from the child process.\n");
        }
        else
        {
            printf("Error: message not received by the child process!\n");
            exit(1);
        }

        //putting a message indicator in the shared memory segment
        sprintf(shm_ptr, "*%s", "done");

        //detaching the shared memory segment from the parent process address space
        if(shmdt(shm_ptr) == -1)
        {
            printf("Error detaching the shared memory segment from the parent process!\n");
            exit(1);
        }
        
        printf("Shared memory segment detached from the parent process successfully.\n");
        
        //deleting the shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1)
        {
            printf("Error deleting the shared memory segment!\n");
            exit(1);
        }
        
        printf("Shared memory segment deleted successfully.\n");
    }

    return 0;
}