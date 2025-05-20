//FormAI DATASET v1.0 Category: Interprocess communication ; Style: immersive
/*WELCOME TO INTERPROCESS COMMUNICATION PROGRAM

In this program, there are two processes: sender and receiver.

Sender sends a message to receiver using Shared Memory.

Sender will take user input and store that in shared memory.

Receiver will read the message from the shared memory and print it on the console.

Let's get started!*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//including required header files

#include <sys/ipc.h>
#include <sys/shm.h>
//header files for Shared Memory

#define SHMSIZE 100 //Size of Shared Memory

int main() {

    int shmid; //Shared Memory ID

    key_t key = 1234; //Key for Shared Memory. You can use any key you want.

    char *shm; //Pointer to Shared Memory

    char message[SHMSIZE]; //To hold the message

    //Creating Shared Memory
    shmid = shmget(key, SHMSIZE, 0666 | IPC_CREAT);
    //Key, Size of Shared Memory, Permissions

    if (shmid == -1) { //Error handling
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    //Attaching Shared Memory with the current process
    shm = shmat(shmid, NULL, 0);
    //Shared Memory ID, Address(NULL means system chooses its own), Flags(0)

    if (shm == (char *) -1) { //Error handling
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    //Getting user input
    printf("Enter your message: "); 
    fgets(message, SHMSIZE, stdin);

    //Writing user input to Shared Memory
    strncpy(shm, message, SHMSIZE);

    //Detaching Shared Memory from current process
    shmdt(shm);

    printf("\nMessage sent!\n");

    //Creating child process
    pid_t pid = fork();

    if (pid < 0) { //Error handling
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { //Child process(receiver)

        sleep(2); //Waiting for sender to finish writing to Shared Memory

        //Attaching Shared Memory with the current process
        shm = shmat(shmid, NULL, 0);
        //Shared Memory ID, Address(NULL means system chooses its own), Flags(0)

        if (shm == (char *) -1) { //Error handling
            perror("shmat");
            exit(EXIT_FAILURE);
        }

        printf("\nReceived message: %s", shm); //Printing the message

        //Detaching Shared Memory from current process
        shmdt(shm);

        //Removing Shared Memory
        shmctl(shmid, IPC_RMID, NULL);

        printf("\nShared Memory removed!\n");

        exit(EXIT_SUCCESS);

    } else { //Parent process(sender)

        wait(NULL); //Waiting for child process to finish

        //Removing Shared Memory
        shmctl(shmid, IPC_RMID, NULL);

        printf("\nShared Memory removed!\n");

        exit(EXIT_SUCCESS);
    }

}