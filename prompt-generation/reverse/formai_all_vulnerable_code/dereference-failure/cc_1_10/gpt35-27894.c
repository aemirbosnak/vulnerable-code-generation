//FormAI DATASET v1.0 Category: Interprocess communication ; Style: decentralized
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<signal.h>

#define MAX 50

// Defining the structure of the shared memory
struct shared{
    int number; // Data to be shared
    int flag; // Flag to indicate access to shared memory
};

// Signal handler for CTRL+C
void handle_ctrl_c(int sig){
    printf("\nCTRL+C detected, program terminated\n");
    exit(0);
}

int main(){
    // Registering signal handler for CTRL+C
    signal(SIGINT, handle_ctrl_c);
    
    // Getting the key for shared memory
    key_t key = ftok("shared_memory_example", 'M');
    if(key==-1){
        perror("ftok");
        exit(1);
    }

    // Creating the shared memory segment
    int segment_id = shmget(key, sizeof(struct shared), IPC_CREAT | 0666);
    if(segment_id==-1){
        perror("shmget");
        exit(1);
    }

    // Attaching the shared memory segment
    struct shared *shared_data = (struct shared*)shmat(segment_id, NULL, 0);
    if(shared_data==(struct shared*)-1){
        perror("shmat");
        exit(1);
    }

    // Initializing shared data
    shared_data->number = -1;
    shared_data->flag = 0;

    printf("Shared memory created with ID %d\n", segment_id);
    printf("Number to be shared: %d\n", shared_data->number);

    // Forking the program into two processes
    int pid = fork();

    if(pid==0){
        // Child process
        printf("\nChild Process\n\n");
        while(1){
            // Waiting for access to shared memory
            while(shared_data->flag!=0){
                sleep(1);
            }

            // Updating the shared data
            shared_data->number++;
            printf("Child process incremented number to %d\n", shared_data->number);

            // Indicating that shared memory is available
            shared_data->flag = 1;
        }
    }
    else{
        // Parent process
        printf("\nParent Process\n\n");
        while(1){
            // Waiting for access to shared memory
            while(shared_data->flag!=1){
                sleep(1);
            }

            // Reading the shared data
            printf("Parent process read number as %d\n", shared_data->number);

            // Indicating that shared memory is available
            shared_data->flag = 0;
        }
    }

    // Detaching the shared memory segment
    if(shmdt(shared_data)==-1){
        perror("shmdt");
        exit(1);
    }

    // Removing the shared memory segment
    if(shmctl(segment_id, IPC_RMID, NULL)==-1){
        perror("shmctl");
        exit(1);
    }

    return 0;
}