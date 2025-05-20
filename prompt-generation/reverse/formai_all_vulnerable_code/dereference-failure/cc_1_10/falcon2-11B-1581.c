//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>

#define MAX_MSG_SIZE 1000

int main() {
    // Create a shared memory segment
    key_t key = ftok("ipc-example", 'a');
    shmget(key, MAX_MSG_SIZE, 0666 | IPC_CREAT);

    // Get the ID of the shared memory segment
    int shmid = shmget(key, MAX_MSG_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Get a pointer to the shared memory segment
    char *shmptr = (char*) shmat(shmid, NULL, 0);
    if (shmptr == (char*)-1) {
        perror("shmat");
        return 1;
    }

    // Initialize the shared memory segment
    memset(shmptr, 0, MAX_MSG_SIZE);

    // Set up a server process
    pid_t server_pid = fork();
    if (server_pid == 0) {
        // Child process: Wait for a client to connect
        while (1) {
            msgrcv(shmid, shmptr, MAX_MSG_SIZE, 1, 0);
        }
    }

    // Set up a client process
    pid_t client_pid = fork();
    if (client_pid == 0) {
        // Child process: Connect to the server and send a message
        while (1) {
            printf("Enter a message: ");
            fflush(stdout);
            fgets(shmptr, MAX_MSG_SIZE, stdin);
            msgsnd(shmid, shmptr, MAX_MSG_SIZE, 0);
        }
    }

    // Wait for both processes to exit
    wait(NULL);
    return 0;
}