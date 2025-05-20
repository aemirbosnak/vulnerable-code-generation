//FormAI DATASET v1.0 Category: Interprocess communication ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024 // size of shared memory segment

int main() {
    int shmid; // shared memory ID
    key_t key; // shared memory key
    char *shm; // pointer to shared memory segment
    char buf[SHM_SIZE]; // buffer for user input
    pid_t pid; // process ID
    int running = 1; // flag for whether program should continue running

    // generate shared memory key
    if ((key = ftok(".", 'a')) == -1) {
        perror("ftok");
        exit(1);
    }

    // create shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // attach shared memory segment to process's address space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // fork a child process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) { // child process
        char *message = "Hello, parent!";
        memcpy(shm, message, strlen(message) + 1); // write message to shared memory
        exit(0);
    } else { // parent process
        while (running) {
            printf("Enter a message for the child: ");
            fgets(buf, SHM_SIZE, stdin);
            buf[strcspn(buf, "\n")] = '\0'; // remove newline character from input
            if (strncmp(buf, "quit", strlen("quit")) == 0) {
                running = 0;
            } else {
                memcpy(shm, buf, strlen(buf) + 1); // write user input to shared memory
                printf("Message sent to child: %s\n", buf);
                sleep(1); // wait for child to read message
                printf("Response from child: %s\n", shm);
            }
        }
        wait(NULL); // wait for child process to exit
    }

    // detach shared memory segment from process's address space
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}