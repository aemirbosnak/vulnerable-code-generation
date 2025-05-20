//FormAI DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Defining shared memory struct
typedef struct{
    char message[100];
    int flag;     // Flag to indicate whether message has been read or not
} shared_mem;

// Error checking function
void error_checking(int check, char* error_message){
    if(check == -1){
        perror(error_message);
        exit(EXIT_FAILURE);
    }
}

int main(){

    int shm_id;
    key_t key = ftok("file_path", 'R');   // Key for shared memory creation
    shared_mem *shared_memory;

    // Creating the shared memory segment
    shm_id = shmget(key, sizeof(shared_mem), IPC_CREAT | 0666);
    error_checking(shm_id, "shmget");

    // Attaching the shared memory segment to the process
    shared_memory = (shared_mem*) shmat(shm_id, NULL, 0);
    error_checking(shared_memory, "shmat");

    // Initializing flag
    shared_memory->flag = 0;

    pid_t child_pid = fork();   // Creating child process

    if(child_pid < 0){
        error_checking(child_pid, "fork");
    }
    else if(child_pid == 0){
        // Child process

        while(1){

            // Waiting for parent to write message
            while(shared_memory->flag == 0);

            // Printing the received message
            printf("Child Process: Message Received - %s\n", shared_memory->message);

            // Setting flag back to 0
            shared_memory->flag = 0;
        }
    }
    else{
        // Parent process

        char message[100];
        while(1){
            // Reading input from user
            printf("Enter Message: ");
            fgets(message, 100, stdin);

            // Copying the message to shared memory
            strcpy(shared_memory->message, message);

            // Setting flag to indicate message has been written
            shared_memory->flag = 1;

            // Waiting for child to read message
            while(shared_memory->flag == 1);
        }
    }

    // Detaching the shared memory segment from the process
    shmdt(shared_memory);

    // Deleting the shared memory segment
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}