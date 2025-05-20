//FormAI DATASET v1.0 Category: Interprocess communication ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHMSIZE 1000

// create a struct that holds all necessary data
struct shared_data {
    char message[SHMSIZE];
    int flag;
};

int main() {
    key_t key = 0;
    int shmid = 0;
    struct shared_data *data;
    pid_t pid;

    // generate a unique key for the shared memory segment
    key = ftok(".", 'a');
    if (key == -1) {
        perror("ftok error");
        exit(1);
    }

    // create the shared memory segment
    shmid = shmget(key, sizeof(struct shared_data), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget error");
        exit(1);
    }

    // attach the shared memory segment to the current process's address space
    data = (struct shared_data *) shmat(shmid, NULL, 0);
    if (data == (struct shared_data *) -1) {
        perror("shmat error");
        exit(1);
    }

    // initialize the shared data
    strcpy(data->message, "Hello there!");
    data->flag = 0;

    // fork a child process
    pid = fork();
    if (pid == -1) {
        perror("fork error");
        exit(1);
    }

    if (pid == 0) {
        // child process reads from the shared memory segment
        while (1) {
            if (data->flag == 1) {
                printf("[CHILD] Received message: %s\n", data->message);

                // reset flag
                data->flag = 0;

                // exit child process
                exit(0);
            }
        }
    } else {
        // parent process writes to the shared memory segment
        printf("[PARENT] Sending message...\n");

        // write to the shared memory segment
        strcpy(data->message, "General Kenobi!");
        data->flag = 1;

        // wait for the child process to finish
        wait(NULL);

        // detach and remove the shared memory segment
        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);

        printf("[PARENT] Exiting...\n");
    }

    return 0;
}