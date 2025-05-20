//FormAI DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_KEY 0x1234

typedef struct {
    char message[100];
} shared_data;

int main() {
    int shmid;
    shared_data *shared_memory;
    char buffer[100];

    // create a shared memory segment
    if ((shmid = shmget(SHM_KEY, sizeof(shared_data), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // attach the shared memory segment to the process's address space
    if ((shared_memory = shmat(shmid, NULL, 0)) == (shared_data *) -1) {
        perror("shmat");
        exit(1);
    }

    // loop to get user input and write it to shared memory
    while (1) {
        printf("Enter a message: ");
        fgets(buffer, sizeof(buffer), stdin);

        // remove newline character from input
        buffer[strcspn(buffer, "\n")] = 0;

        // copy input to shared memory
        strcpy(shared_memory->message, buffer);

        // check for exit command
        if (strcmp(buffer, "exit") == 0) {
            break;
        }
    }

    // detach the shared memory segment from the process's address space
    if (shmdt(shared_memory) == -1) {
        perror("shmdt");
        exit(1);
    }

    // delete the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}