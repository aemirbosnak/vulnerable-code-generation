//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 1234
#define CHILD_COUNT 3

typedef struct {
    int id;
    char name[20];
} ChildData;

int main(void) {
    int i, shmid, pid;
    int status;
    ChildData *child_data;
    char *shm_addr;

    // Create a shared memory segment
    shmid = shmget(SHM_KEY, sizeof(ChildData) * CHILD_COUNT, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget failed");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment
    shm_addr = shmat(shmid, NULL, 0);
    if (shm_addr == (void *)-1) {
        perror("shmat failed");
        exit(EXIT_FAILURE);
    }

    // Fork three children
    for (i = 0; i < CHILD_COUNT; ++i) {
        pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
        if (pid > 0) {
            // Parent process stores child data in the shared memory
            strcpy(child_data[i].name, "Child");
            child_data[i].id = i + 1;
        } else {
            // Child process reads data from the shared memory
            child_data = (ChildData *)shm_addr;
            printf("Child %d: My name is %s\n", child_data[i].id, child_data[i].name);
            exit(EXIT_SUCCESS);
        }
    }

    // Wait for all children to finish
    for (i = 0; i < CHILD_COUNT; ++i) {
        waitpid(child_data[i].id, &status, 0);
    }

    // Detach and destroy the shared memory segment
    shmdt(shm_addr);
    shmctl(shmid, IPC_RMID, 0);

    return EXIT_SUCCESS;
}