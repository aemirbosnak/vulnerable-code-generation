//FormAI DATASET v1.0 Category: Interprocess communication ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MEM_SIZE 1024

int main() {
    key_t key;
    int shmid, status;
    char *shmaddr;

    // Create a shared memory segment with a key value of 1234
    key = 1234;
    shmid = shmget(key, MEM_SIZE, IPC_CREAT|0666);
    if (shmid < 0) {
        perror("shmget error");
        exit(1);
    }

    // Attach the shared memory segment to this process
    shmaddr = shmat(shmid, NULL, 0);
    if (*shmaddr == -1) {
        perror("shmat error");
        exit(1);
    }

    // Write a mathematical equation to the shared memory segment
    sprintf(shmaddr, "2 + 2 = 4");

    // Detach the shared memory segment from this process
    status = shmdt(shmaddr);
    if (status == -1) {
        perror("shmdt error");
        exit(1);
    }

    // Wait for 5 seconds to simulate another process
    printf("Waiting for the result...\n");
    sleep(5);

    // Attach the shared memory segment to this process again
    shmaddr = shmat(shmid, NULL, 0);
    if (*shmaddr == -1) {
        perror("shmat error");
        exit(1);
    }

    // Read the result from the shared memory segment
    printf("The result is: %s\n", shmaddr);

    // Detach the shared memory segment from this process again
    status = shmdt(shmaddr);
    if (status == -1) {
        perror("shmdt error");
        exit(1);
    }

    // Delete the shared memory segment
    status = shmctl(shmid, IPC_RMID, NULL);
    if (status == -1) {
        perror("shmctl error");
        exit(1);
    }
    return 0;
}