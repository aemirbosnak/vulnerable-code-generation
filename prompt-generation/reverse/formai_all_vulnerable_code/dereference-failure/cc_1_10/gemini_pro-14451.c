//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>

// Define the data structure to be shared between processes
typedef struct {
    int data;
    time_t timestamp;
} shared_data;

int main(int argc, char *argv[]) {
    // Get the shared memory segment
    int shmid = shmget(IPC_PRIVATE, sizeof(shared_data), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        return EXIT_FAILURE;
    }

    // Attach the shared memory segment to the current process
    shared_data *data = (shared_data *)shmat(shmid, NULL, 0);
    if (data == (void *)-1) {
        perror("shmat");
        return EXIT_FAILURE;
    }

    // Initialize the shared data
    data->data = 0;
    data->timestamp = time(NULL);

    // Fork a child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return EXIT_FAILURE;
    } else if (pid == 0) {
        // Child process increments the shared data every second
        while (1) {
            data->data++;
            data->timestamp = time(NULL);
            sleep(1);
        }
    } else {
        // Parent process prints the shared data every 5 seconds
        while (1) {
            printf("Data: %d\n", data->data);
            printf("Timestamp: %ld\n", data->timestamp);
            sleep(5);
        }
    }

    // Detach the shared memory segment from the current process
    if (shmdt(data) == -1) {
        perror("shmdt");
        return EXIT_FAILURE;
    }

    // Destroy the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}