//FormAI DATASET v1.0 Category: Interprocess communication ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

/* Function to calculate the mean of a set of numbers */
double get_mean(int *array, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

/* Function to calculate the variance of a set of numbers */
double get_variance(int *array, int size, double mean) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += (array[i] - mean) * (array[i] - mean);
    }
    return sum / (size - 1);
}

/* Main function */
int main() {
    int size = 10;  // Size of the array
    int shmid;  // Shared memory ID
    int *array;  // Pointer to shared memory
    double mean, variance;  // Variables to hold the mean and variance

    // Allocate shared memory
    shmid = shmget(IPC_PRIVATE, size * sizeof(int), 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("Error creating shared memory");
        exit(1);
    }

    // Attach to shared memory
    array = (int *) shmat(shmid, NULL, 0);
    if (array == (int *) -1) {
        perror("Error attaching to shared memory");
        exit(1);
    }

    // Generate random data
    printf("Generating random data...\n");
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;
        printf("%d ", array[i]);
    }

    // Fork a new process to calculate the mean and variance
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        perror("Error forking process");
        exit(1);
    } else if (pid == 0) {
        // Child process
        mean = get_mean(array, size);
        exit(0);
    } else {
        // Parent process
        wait(NULL);
        variance = get_variance(array, size, mean);
        printf("\nMean: %lf\nVariance: %lf\n", mean, variance);
    }

    // Detach from shared memory
    if (shmdt(array) == -1) {
        perror("Error detaching from shared memory");
        exit(1);
    }

    // Deallocate shared memory
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("Error deallocating shared memory");
        exit(1);
    }

    return 0;
}