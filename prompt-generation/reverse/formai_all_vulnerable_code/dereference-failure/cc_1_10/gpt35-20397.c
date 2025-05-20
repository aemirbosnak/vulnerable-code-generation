//FormAI DATASET v1.0 Category: Interprocess communication ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024 // Shared Memory Segment size

int main() {
    char* shared_memory; // pointer to shared memory segment
    char message[100]; // message to be written to shared memory segment
    int shmid;
    key_t key; // key to access shared memory segment

    /* Create a unique key for the shared memory segment */
    key = ftok("shared_memory_key", 'a');

    /* Create the shared memory segment */
    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);

    /* Attach to the shared memory segment */
    shared_memory = shmat(shmid, NULL, 0);

    /* Write to the shared memory segment */
    printf("Enter a message to write to the shared memory segment: ");
    fgets(message, sizeof(message), stdin);
    strncpy(shared_memory, message, SHM_SIZE);

     /* Detach from the shared memory segment */
    shmdt(shared_memory);

    /* Fork a child process to read from the shared memory segment */
    pid_t pid = fork();

    if(pid == 0) { // Child process: read from shared memory segment
        char* shared_memory_child;
        char message_child[100];

        /* Attach to the shared memory segment */
        shared_memory_child = shmat(shmid, NULL, SHM_RDONLY);

        /* Read from the shared memory segment */
        strncpy(message_child, shared_memory_child, SHM_SIZE);

        printf("Message read from the shared memory segment: %s", message_child);

        /* Detach from the shared memory segment */
        shmdt(shared_memory_child);

        /* Delete the shared memory segment */
        shmctl(shmid, IPC_RMID, NULL);
    }
    else { // Parent process: wait for child process to complete
        wait(NULL);
    }

    return 0;
}