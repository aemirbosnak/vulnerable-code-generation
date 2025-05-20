//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid;
    key_t key;
    char *shm;
    int i = 0;

    // create key for shared memory
    key = ftok("shared_memory.c", 65);

    // create shared memory segment
    shmid = shmget(key, SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment.\n");
        exit(1);
    }

    // attach to shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (void*) -1) {
        printf("Error attaching to shared memory segment.\n");
        exit(1);
    }

    // initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        *(shm + i) = 0;
    }

    // fork child process
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error forking child process.\n");
        exit(1);
    } else if (pid > 0) {
        // parent process
        int status;
        waitpid(pid, &status, 0);
        printf("Child process terminated.\n");
    } else {
        // child process
        sleep(2);
        for (i = 0; i < SIZE; i++) {
            *(shm + i) = i;
        }
        printf("Child process terminated.\n");
        exit(0);
    }

    return 0;
}