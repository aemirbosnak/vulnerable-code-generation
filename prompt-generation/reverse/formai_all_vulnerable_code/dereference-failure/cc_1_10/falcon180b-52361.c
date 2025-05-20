//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 10

// Structure for shared memory
struct data {
    int count;
    char buffer[SIZE];
};

int main() {
    int shmid;
    key_t key;
    int i, j, n;
    pid_t pid;
    struct data *data;

    // Create a shared memory segment
    key = ftok("shared_file", 'a');
    shmid = shmget(key, sizeof(struct data), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Shared memory creation failed.\n");
        exit(1);
    }

    // Attach to the shared memory segment
    data = (struct data *) shmat(shmid, NULL, 0);
    if ((long) data == -1) {
        printf("Shared memory attachment failed.\n");
        exit(1);
    }

    // Initialize the data
    data->count = 0;
    for (i = 0; i < SIZE; i++) {
        data->buffer[i] = '\0';
    }

    // Fork a child process
    pid = fork();
    if (pid == 0) {
        // Child process
        for (i = 0; i < 3; i++) {
            sleep(1);
            sprintf(data->buffer, "Child %d wrote this.\n", i+1);
            data->count++;
        }
        exit(0);
    } else {
        // Parent process
        wait(NULL);
        for (j = 0; j < 3; j++) {
            sleep(1);
            printf("Parent %d read: %s\n", j+1, data->buffer);
        }
    }

    // Detach from the shared memory segment
    if (shmdt(data) == -1) {
        printf("Shared memory detachment failed.\n");
        exit(1);
    }

    // Remove the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Shared memory removal failed.\n");
        exit(1);
    }

    return 0;
}