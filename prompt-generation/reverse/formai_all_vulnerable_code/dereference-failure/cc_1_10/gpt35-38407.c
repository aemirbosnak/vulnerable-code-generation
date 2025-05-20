//FormAI DATASET v1.0 Category: Interprocess communication ; Style: statistical
/* Statistical Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 100 // Shared memory size

int main(int argc, char **argv) {
    int shmid;
    int *shared_data;
    key_t key = 1234; // Shared memory key
    int data[SHM_SIZE]; // Initialize data array
    int sum = 0, avg = 0, min = 0, max = 0;

    /* Allocate shared memory */
    if ((shmid = shmget(key, SHM_SIZE*sizeof(int), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /* Attach shared memory */
    if ((shared_data = shmat(shmid, NULL, 0)) == (int *) -1) {
        perror("shmat");
        exit(1);
    }

    /* Copy data to shared memory */
    for (int i=0; i<SHM_SIZE; i++) {
        shared_data[i] = data[i];
        sum += data[i]; // Calculate sum
        if (i == 0 || data[i] < min) min = data[i]; // Calculate min
        if (i == 0 || data[i] > max) max = data[i]; // Calculate max
    }
    avg = sum/SHM_SIZE; // Calculate average

    /* Print statistics */
    printf("Sum: %d\n", sum);
    printf("Average: %d\n", avg);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    /* Detach shared memory */
    shmdt((void *) shared_data);

    /* Remove shared memory */
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}