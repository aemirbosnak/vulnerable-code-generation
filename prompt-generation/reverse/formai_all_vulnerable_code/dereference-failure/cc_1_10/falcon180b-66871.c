//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid;
    char *shmaddr;
    int i;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE*sizeof(int), IPC_CREAT|0777);
    if (shmid == -1) {
        printf("Shared memory creation failed\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char*)-1) {
        printf("Shared memory attachment failed\n");
        exit(1);
    }

    // Initialize shared memory with values
    for (i = 0; i < SIZE; i++) {
        ((int*)shmaddr)[i] = i;
    }

    // Fork child process
    pid_t child_pid = fork();
    if (child_pid == 0) {
        // Child process
        for (i = 0; i < SIZE; i++) {
            ((int*)shmaddr)[i] += 10;
        }
        printf("Child process completed\n");
        exit(0);
    } else {
        // Parent process
        wait(NULL);
        for (i = 0; i < SIZE; i++) {
            printf("%d ", ((int*)shmaddr)[i]);
        }
        printf("\n");
    }

    return 0;
}