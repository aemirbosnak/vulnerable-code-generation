//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <time.h>

#define MAX_POINTS 100
#define NUM_PLAYERS 3
#define SHM_SIZE sizeof(int)

struct sembuf sem_wait = {0, -1, 0};
struct sembuf sem_signal = {0, 1, 0};

void player(int player_id, int *points, int sem_id) {
    srand(time(NULL) + player_id); // Different seed for each player
    int collected_points = 0;

    for (int i = 0; i < 5; i++) {
        // Simulate thinking and random delay
        sleep(rand() % 2 + 1); // Sleep for 1 to 2 seconds

        // Wait on semaphore
        semop(sem_id, &sem_wait, 1);
        
        if (*points > 0) {
            int take = rand() % 10 + 1; // Random points to take (1-10)
            if (*points >= take) {
                *points -= take;
                collected_points += take;
                printf("Player %d collected %d points! Total points: %d\n", player_id, take, collected_points);
            } else {
                printf("Player %d could not collect points, not enough points left!\n", player_id);
            }
        }
        
        // Signal semaphore
        semop(sem_id, &sem_signal, 1);
    }
    
    printf("Player %d finished with a total of %d points collected.\n", player_id, collected_points);
}

int main() {
    int shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    int *points = shmat(shmid, NULL, 0);
    if (points == (int *) -1) {
        perror("shmat");
        exit(1);
    }

    *points = MAX_POINTS; // Initial points

    // Semaphore for synchronization
    int sem_id = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    semctl(sem_id, 0, SETVAL, 1); // Initialize semaphore to 1

    pid_t pid;
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if ((pid = fork()) == 0) {
            player(i + 1, points, sem_id);
            exit(0); // Terminate child process
        }
    }

    // Wait for all player processes to finish
    for (int i = 0; i < NUM_PLAYERS; i++) {
        wait(NULL);
    }

    printf("Game Over! Points left in the game: %d\n", *points);

    // Cleanup shared memory and semaphore
    shmdt(points);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(sem_id, 0, IPC_RMID);

    return 0;
}