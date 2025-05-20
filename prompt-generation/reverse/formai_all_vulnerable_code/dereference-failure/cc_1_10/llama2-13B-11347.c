//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_NAME "stat_share"
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    // Create a shared memory segment
    int shmid = shmget(SHM_NAME, BUF_SIZE, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget");
        return 1;
    }

    // Attach to the shared memory segment
    void *shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat");
        return 1;
    }

    // Create a statistic object in the shared memory
    struct stat_s {
        int count;
        double mean;
        double variance;
    } stat;
    memset(&stat, 0, sizeof(stat));
    strcpy(shm, "Hello, world!");

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        // Child process
        close(shmid);
        char *message = "Hello, parent!";
        write(1, message, strlen(message));
        exit(0);
    } else {
        // Parent process
        close(shmid);
        char *message = "Hello, child!";
        read(0, message, strlen(message));
        printf("Received message: %s\n", message);
    }

    // Use the shared memory to store and calculate statistics
    while (1) {
        // Read data from the shared memory
        char *data = shm;
        int count = 0;
        double sum = 0;
        double square_sum = 0;
        for (int i = 0; i < BUF_SIZE; i++) {
            if (data[i] == ',') {
                count++;
                sum += atof(data + i + 1);
                square_sum += (atof(data + i + 1) * atof(data + i + 1));
            }
        }
        stat.count = count;
        stat.mean = sum / count;
        stat.variance = square_sum / (count - 1);

        // Print the statistics
        printf("Statistics:\n");
        printf("  Count: %d\n", stat.count);
        printf("  Mean: %f\n", stat.mean);
        printf("  Variance: %f\n", stat.variance);

        // Sleep for a bit before reading more data
        sleep(1);
    }

    return 0;
}