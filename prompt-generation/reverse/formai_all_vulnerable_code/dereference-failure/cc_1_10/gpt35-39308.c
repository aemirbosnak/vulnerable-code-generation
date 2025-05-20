//FormAI DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;
    int num;

    // Get a key using ftok()
    if ((key = ftok("/dev/null", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Create a shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to our data space
    shm = (char *) shmat(shmid, (void *) 0, 0);
    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Read a number from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Write the number to shared memory
    sprintf(shm, "%d", num);

    // Fork a child process
    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) { // Child process
        int num = atoi(shm);
        num++;
        sprintf(shm, "%d", num);
        exit(0);
    }

    else { // Parent process
        wait(NULL);
        int num = atoi(shm);
        printf("The incremented number is: %d\n", num);
    }

    // Detach the shared memory segment
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Delete the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}