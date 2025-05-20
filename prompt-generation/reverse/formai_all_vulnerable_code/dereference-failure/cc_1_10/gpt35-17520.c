//FormAI DATASET v1.0 Category: Interprocess communication ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>

#define SHM_SIZE 100 // size of shared memory

int shmid; // shared memory id

void sig_handler(int signum) {
    printf("Received signal %d\n", signum);
    if (signum == SIGINT) {
        printf("Ctrl-C detected. Detaching from shared memory\n");
        if (shmdt(NULL) == -1) {
            perror("shmdt");
            exit(1);
        }
        printf("Exiting...\n");
        exit(0);
    }
}

int main() {
    key_t key = 1234; // shared memory key
    char *shm; // shared memory pointer
    char message[SHM_SIZE]; // buffer to hold message

    signal(SIGINT, sig_handler); // set up signal handler for Ctrl-C

    // create shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // attach shared memory segment to process address space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // loop to read messages from shared memory
    while (1) {
        printf("Waiting for message...\n");
        sleep(1); // simulate processing time

        if (strlen(shm) > 0) { // if shared memory has a message
            printf("Received message: %s\n", shm);
            memset(shm, 0, SHM_SIZE); // clear shared memory
        }

        // simulate sending a message to another process
        strcpy(message, "Hello from process A");
        printf("Sending message: %s\n", message);
        strncpy(shm, message, SHM_SIZE);
    }

    return 0;
}