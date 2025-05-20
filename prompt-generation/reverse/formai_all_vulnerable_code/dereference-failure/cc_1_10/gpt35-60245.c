//FormAI DATASET v1.0 Category: Interprocess communication ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h> 

#define BUFFER_SIZE 1024
#define SHM_SIZE 1024

int main(){

    key_t key;
    int shmid;
    char *str;
    char buffer[BUFFER_SIZE];

    // generate a unique key
    key = ftok(".", 'a');

    // create a shared memory segment with read and write access
    shmid = shmget(key, SHM_SIZE, 0666|IPC_CREAT);

    // attach to the shared memory segment
    str = shmat(shmid, NULL, 0);

    // loop until "quit" is entered on the command line
    while(1){

        // read input from the user
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // copy the input into the shared memory segment
        strncpy(str, buffer, SHM_SIZE);

        // if "quit" is entered on the command line, break out of the loop
        if(strncmp(str, "quit", 4) == 0){
            printf("Exiting...\n");
            break;
        }

        // wait for the other process to read from the shared memory segment
        while(*str != '*'){
            sleep(1);
        }

        // reset the shared memory segment
        memset(str, '*', SHM_SIZE);
    }

    // detach from the shared memory segment
    shmdt(str);

    // delete the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}