//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

// Structure for shared memory
struct shared_memory {
    int count;
    char message[SIZE];
};

int main() {
    int shmid;
    key_t key = 12345;
    struct shared_memory *shmptr;

    // Create shared memory segment
    shmid = shmget(key, sizeof(struct shared_memory), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Could not create shared memory segment.\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shmptr = (struct shared_memory *) shmat(shmid, NULL, 0);
    if (shmptr == (void *) -1) {
        printf("Could not attach shared memory segment.\n");
        exit(2);
    }

    // Initialize shared memory
    shmptr->count = 0;
    strcpy(shmptr->message, "Hail, brave knight!");

    // Fork child process
    pid_t childpid = fork();
    if (childpid == -1) {
        printf("Could not fork child process.\n");
        exit(3);
    } else if (childpid == 0) {
        // Child process
        sleep(1);

        // Increment count and change message
        shmptr->count++;
        strcpy(shmptr->message, "Thou art a worthy opponent!");

        // Detach shared memory segment
        if (shmdt(shmptr) == -1) {
            printf("Could not detach shared memory segment.\n");
            exit(4);
        }

        // Exit child process
        exit(0);
    } else {
        // Parent process
        sleep(2);

        // Print updated message from child process
        shmptr = (struct shared_memory *) shmat(shmid, NULL, 0);
        printf("The message from the child process is: %s\n", shmptr->message);

        // Detach shared memory segment
        if (shmdt(shmptr) == -1) {
            printf("Could not detach shared memory segment.\n");
            exit(5);
        }

        // Delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            printf("Could not delete shared memory segment.\n");
            exit(6);
        }

        // Exit parent process
        exit(0);
    }
}