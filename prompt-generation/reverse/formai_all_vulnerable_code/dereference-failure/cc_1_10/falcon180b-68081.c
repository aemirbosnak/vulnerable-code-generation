//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 100

// Structure for shared memory segment
struct shm_struct {
    int num;
    char str[SIZE];
};

int main() {

    int shmid;
    key_t key;
    struct shm_struct *ptr;

    // Get unique key
    key = ftok("shm_example.c", 65);

    // Create shared memory segment
    shmid = shmget(key, sizeof(struct shm_struct), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        return 1;
    }

    // Attach to shared memory segment
    ptr = (struct shm_struct *) shmat(shmid, NULL, 0);
    if (ptr == (void *) -1) {
        printf("Error attaching to shared memory segment\n");
        return 1;
    }

    // Initialize shared memory segment
    ptr->num = 42;
    strcpy(ptr->str, "Hello, world!");

    // Fork a child process
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error forking process\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        sleep(2); // Wait for parent to update shared memory

        // Access shared memory segment
        printf("Child process:\n");
        printf("Number: %d\n", ptr->num);
        printf("String: %s\n", ptr->str);

        // Detach from shared memory segment
        if (shmdt(ptr) == -1) {
            printf("Error detaching from shared memory segment\n");
            return 1;
        }

        // Exit child process
        return 0;
    } else {
        // Parent process
        sleep(1); // Give child time to attach to shared memory

        // Update shared memory segment
        ptr->num = 43;
        strcpy(ptr->str, "Goodbye, world!");

        // Detach from shared memory segment
        if (shmdt(ptr) == -1) {
            printf("Error detaching from shared memory segment\n");
            return 1;
        }

        // Wait for child process to exit
        wait(NULL);

        // Remove shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            printf("Error removing shared memory segment\n");
            return 1;
        }
    }

    return 0;
}