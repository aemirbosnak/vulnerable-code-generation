//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 100

typedef struct {
    int id;
    int value;
} shared_data;

int main() {
    int shmid, shm_fd;
    shared_data *shm_ptr;

    // create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error: shared memory segment creation failed\n");
        exit(1);
    }

    // attach shared memory segment to process address space
    shm_ptr = (shared_data *) shmat(shmid, NULL, 0);
    if (shm_ptr == (void *) -1) {
        printf("Error: shared memory segment attachment failed\n");
        exit(1);
    }

    // initialize shared data
    shm_ptr->id = 1;
    shm_ptr->value = 10;

    // fork child process
    int pid = fork();
    if (pid == 0) {
        // child process
        printf("Child process started with PID %d\n", getpid());

        // update shared data
        shm_ptr->value = 20;

        // detach shared memory segment from process address space
        if (shmdt(shm_ptr) == -1) {
            printf("Error: shared memory segment detachment failed\n");
            exit(1);
        }

        // exit child process
        exit(0);
    } else if (pid > 0) {
        // parent process
        printf("Parent process started with PID %d\n", getpid());

        // wait for child process to finish
        wait(NULL);

        // update shared data
        shm_ptr->value = 30;

        // detach shared memory segment from process address space
        if (shmdt(shm_ptr) == -1) {
            printf("Error: shared memory segment detachment failed\n");
            exit(1);
        }

        // delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            printf("Error: shared memory segment deletion failed\n");
            exit(1);
        }

        // exit parent process
        exit(0);
    } else {
        // error occurred
        printf("Error: fork() failed\n");
        exit(1);
    }

    return 0;
}