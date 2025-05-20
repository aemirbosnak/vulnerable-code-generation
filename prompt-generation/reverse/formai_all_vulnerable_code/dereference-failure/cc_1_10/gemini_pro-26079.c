//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main(void) {
    int shmid;
    char *shm;
    key_t key;

    // Create a shared memory segment
    key = ftok("ram_usage_monitor.c", 'R');
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to this process
    shm = shmat(shmid, NULL, 0);
    if (shm == (void *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Initialize the shared memory segment
    *shm = 0;

    // Create a team of players
    int num_players = 5;
    int pids[num_players];
    for (int i = 0; i < num_players; i++) {
        pids[i] = fork();
        if (pids[i] == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pids[i] == 0) {
            // Child process
            while (1) {
                // Allocate a random amount of memory
                int size = rand() % SHM_SIZE;
                void *ptr = malloc(size);
                if (ptr == NULL) {
                    perror("malloc");
                    exit(EXIT_FAILURE);
                }

                // Store the memory usage in the shared memory segment
                *shm += size;

                // Sleep for a random amount of time
                sleep(rand() % 10);

                // Free the allocated memory
                free(ptr);

                // Store the memory usage in the shared memory segment
                *shm -= size;
            }
        }
    }

    // Parent process
    while (1) {
        // Print the current memory usage
        printf("Current memory usage: %d\n", *shm);

        // Sleep for a second
        sleep(1);
    }

    // Wait for all child processes to finish
    for (int i = 0; i < num_players; i++) {
        waitpid(pids[i], NULL, 0);
    }

    // Detach the shared memory segment from this process
    shmdt(shm);

    // Destroy the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return EXIT_SUCCESS;
}