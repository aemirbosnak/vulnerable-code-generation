//FormAI DATASET v1.0 Category: Interprocess communication ; Style: active
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/ipc.h> 
#include<sys/shm.h> 

// Structure for shared memory data
typedef struct shared_mem_data { 
    int value;
    int pid; 
} SharedMemData; 

int main() 
{ 
    // Dynamic allocation of SharedMemData structure
    SharedMemData *shared_data_ptr = (SharedMemData*) malloc(sizeof(SharedMemData));
    
    // Creating unique key for shared memory
    key_t key = ftok("shmfile",65); 
    
    // Requesting shared memory with the key
    int shared_mem_id = shmget(key,sizeof(SharedMemData),0666|IPC_CREAT); 

    // Attaching shared memory to this process
    shared_data_ptr = (SharedMemData*) shmat(shared_mem_id,(void*)0,0);

    // Setting default value to shared memory data
    shared_data_ptr->value = 0;
    shared_data_ptr->pid = 0;

    // Creating child process
    pid_t pid = fork();

    if(pid == 0) // child process
    {
        printf("Child process pid: %d\n", getpid());

        // Requesting shared memory with the same key
        int shared_mem_id = shmget(key,sizeof(SharedMemData),0666|IPC_CREAT); 

        // Attaching shared memory to this process
        shared_data_ptr = (SharedMemData*) shmat(shared_mem_id,(void*)0,0);

        int temp_value = 0;

        while(1)
        {
            if(shared_data_ptr->pid != 0 && shared_data_ptr->pid != getpid())
            {
                temp_value = shared_data_ptr->value - 1;
                printf("Updated value from parent: %d\n", temp_value);
                shared_data_ptr->pid = getpid();
            }
        }
    }
    
    else // Parent process
    {
        printf("Parent process pid: %d\n", getpid());

        int update_value = 1;

        while(1)
        {
            if(shared_data_ptr->pid == 0) // shared memory not updated by any process yet
            {
                shared_data_ptr->pid = getpid();
                shared_data_ptr->value = update_value;
                printf("Initial value of shared memory: %d\n", update_value);
            }

            else if(shared_data_ptr->pid == getpid()) // Shared memory updated by parent process
            {
                if(shared_data_ptr->value == 10) // Exit condition
                {
                    printf("Final value of shared memory: %d\n", shared_data_ptr->value);
                    break;
                }
                shared_data_ptr->value += update_value;
                printf("Updated value in parent process: %d\n", shared_data_ptr->value);
                shared_data_ptr->pid = 0; // Resetting pid to allow child to take over
            }

            else // Shared memory updated by child process
            {
                // Parent process will receive updated value when the child process updates the shared memory
                // We don't need to do anything here
            }

            sleep(1);
        }
    } 

    // Detaching shared memory from this process
    shmdt(shared_data_ptr);

    // Deallocating shared memory
    shmctl(shared_mem_id,IPC_RMID,NULL); 

    return 0; 
}