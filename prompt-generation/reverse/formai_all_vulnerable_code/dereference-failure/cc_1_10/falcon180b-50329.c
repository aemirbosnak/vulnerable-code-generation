//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10
#define KEY 0x12345

typedef struct {
    int data[SIZE];
} shared_data;

int main() {
    int shmid;
    shared_data *ptr;

    // Create shared memory segment
    shmid = shmget(KEY, sizeof(shared_data), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach to shared memory segment
    ptr = (shared_data *) shmat(shmid, NULL, 0);
    if (ptr == (void *) -1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Initialize shared data
    for (int i = 0; i < SIZE; i++) {
        ptr->data[i] = 0;
    }

    // Create child process
    int pid = fork();
    if (pid == -1) {
        printf("Error creating child process\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        sleep(2);
        for (int i = 0; i < SIZE; i++) {
            ptr->data[i] = i;
        }
        printf("Child process complete\n");
        exit(0);
    } else {
        // Parent process
        sleep(1);
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", ptr->data[i]);
        }
        printf("\n");
        exit(0);
    }

    return 0;
}