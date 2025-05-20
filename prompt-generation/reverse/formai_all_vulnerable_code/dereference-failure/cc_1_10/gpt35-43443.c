//FormAI DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define KEY 1234

void handler(int sig) {
    printf("Received signal %d\n", sig);
    exit(0);
}

int main() {

    int shmid;
    char* shared_memory;
    int* data;

    // Allocate shared memory
    shmid = shmget(KEY, sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach shared memory
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (char *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Convert shared memory to integer pointer
    data = (int *) shared_memory;

    // Set up signal handler
    signal(SIGINT, handler);

    // Loop until user quits with CTRL-C
    while (1) {
        // Read value from shared memory
        int value = *data;
        printf("Received: %d\n", value);

        // Increment value and write back to shared memory
        *data = value + 1;
        sleep(1);
    }

    return 0;
}