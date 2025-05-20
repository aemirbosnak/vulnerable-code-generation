//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/shm.h>

#define SIZE 50
#define TRUE 1
#define FALSE 0

int main() {
    int id, fd;
    int *shm;
    char *name = "shape_shifter";
    int shm_size = sizeof(int) * SIZE;
    int index;

    // create shared memory segment
    id = shmget(IPC_PRIVATE, shm_size, IPC_CREAT | 0777);
    if (id == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // attach shared memory segment
    shm = shmat(id, NULL, 0);
    if (shm == (void*)-1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // initialize shared memory segment
    for (index = 0; index < SIZE; index++) {
        shm[index] = 0;
    }

    // create child process
    fd = fork();
    if (fd == 0) {
        // child process
        printf("Child process started\n");
        sleep(2);
        printf("Child process changing shared memory\n");
        for (index = 0; index < SIZE; index++) {
            shm[index] = index + 1;
        }
        sleep(2);
        printf("Child process exiting\n");
        exit(0);
    } else {
        // parent process
        printf("Parent process waiting for child\n");
        wait(NULL);
        printf("Child process exited\n");
        printf("Shared memory segment:\n");
        for (index = 0; index < SIZE; index++) {
            printf("%d ", shm[index]);
        }
        printf("\n");
    }

    // detach shared memory segment
    if (shmdt(shm) == -1) {
        printf("Error detaching shared memory segment\n");
        exit(1);
    }

    // destroy shared memory segment
    if (shmctl(id, IPC_RMID, NULL) == -1) {
        printf("Error destroying shared memory segment\n");
        exit(1);
    }

    return 0;
}