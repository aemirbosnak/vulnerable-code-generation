//FormAI DATASET v1.0 Category: Interprocess communication ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define KEY 7890
#define SIZE 1024

int main() {
    int shmid, message_count=0;
    char message[SIZE], *shared_memory;

    // create shared memory
    if ((shmid = shmget(KEY, SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // attach shared memory
    if ((shared_memory = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // wait for messages
    while (1) {
        if (strcmp(shared_memory, "exit") == 0)
            break;
        if (strcmp(shared_memory, "") != 0) {
            printf("Received message %d: %s\n", ++message_count, shared_memory);
            memset(shared_memory, 0, SIZE);
        }
    }

    // detach shared memory
    if (shmdt(shared_memory) == -1) {
        perror("shmdt");
        exit(1);
    }

    // delete shared memory
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}