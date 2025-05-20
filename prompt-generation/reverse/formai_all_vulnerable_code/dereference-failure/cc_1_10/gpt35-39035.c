//FormAI DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>

#define KEY 1234
#define SIZE 1024

int main()
{
    int shmid;
    void *shared_memory;
    int *shared_data;

    // create the shared memory
    shmid = shmget(KEY, SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // attach the shared memory to our process
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    // set the shared data
    shared_data = (int *) shared_memory;
    *shared_data = 0;

    // fork the process
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) { // child process
        int i;

        for (i = 1; i <= 10; i++) {
            *shared_data = i;
            printf("Child wrote to shared memory: %d\n", *shared_data);

            sleep(1);
        }

        exit(0);
    } else { // parent process
        int status;
        wait(&status);

        printf("\nChild exited with status %d\n", WEXITSTATUS(status));
        printf("Parent read from shared memory: %d\n", *shared_data);

        // detach the shared memory
        shmdt(shared_memory);

        // destroy the shared memory
        shmctl(shmid, IPC_RMID, NULL);

        exit(0);
    }

    return 0;
}