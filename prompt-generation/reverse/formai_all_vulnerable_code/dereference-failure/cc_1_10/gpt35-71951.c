//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_SIZE 1024
#define SEM_OP -1
#define SEM_START 0
#define PLAYER_AMOUNT 4

void sem_init(int sem_id, int sem_num) {
    struct sembuf sem_op;
    sem_op.sem_num = sem_num;
    sem_op.sem_op = SEM_OP;
    sem_op.sem_flg = SEM_UNDO;
    semop(sem_id, &sem_op, 1);
}

int main() {

    int shmid;
    key_t key = IPC_PRIVATE;
    char *shm, separ[25] = "==================================\n";
    int sem_set_id, sem_id, i;
    int *players_ready;
    int *player_turn, *player_scores;

    // Shared memory creation with key
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("Error in memory creation");
        exit(1);
    }

    // Attach the shared memory segment
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("Error in memory attachment");
        exit(1);
    }
    memset(shm, 0, SHM_SIZE);

    // Semaphores
    sem_set_id = semget(key, 2, IPC_CREAT | 0666);
    if (sem_set_id == -1) {
        perror("Error in semaphore creation");
        exit(1);
    }

    // First semaphore : PLAYER_AMOUNT, indicating that players are ready
    sem_id = semget(key, PLAYER_AMOUNT, IPC_CREAT | 0666);
    if (sem_id == -1) {
        perror("Error in semaphore creation");
        exit(1);
    }

    // Intialize semaphore to blocking mode
    for (i = SEM_START; i < PLAYER_AMOUNT; i++) {
        sem_init(sem_id, i);
    }

    // Intialize first semaphore to non-blocking mode
    semctl(sem_set_id, SEM_START, SETVAL, PLAYER_AMOUNT);

    // Map the shared memory
    players_ready = (int *) shm;
    player_turn = players_ready + PLAYER_AMOUNT;
    player_scores = player_turn + 1;

    // Initialize scores
    for (i = 0; i < PLAYER_AMOUNT; i++) {
        player_scores[i] = 0;
    }

    // Player registration
    printf("Waiting for %d players...\n", PLAYER_AMOUNT);
    for (i = 0; i < PLAYER_AMOUNT; i++) {
        sem_wait(&sem_id, i);

        printf("%d. Player entered the game\n", i + 1);
        players_ready[i] = 1;

        if ((i + 1) == PLAYER_AMOUNT) {
            semctl(sem_set_id, SEM_START, SETVAL, SEM_OP);
        } else {
            sem_post(&sem_id, i + 1);
        }
    }
    printf("%d Players ready!!\n", PLAYER_AMOUNT);

    // Start the game!
    while (1) {
        sem_wait(&sem_set_id, SEM_START);
        printf(separ);
        printf("Starting a new round...\n");

        // Reset the turn variable
        *player_turn = 0;

        // Send turn to first player
        sem_post(&sem_id, *player_turn);

        // Play the game
        while (*player_turn != PLAYER_AMOUNT) {
            sem_wait(&sem_id, *player_turn);

            // Do stuff here

            // Increase player's score
            player_scores[*player_turn] += 1;

            // Check if all players played
            if (*player_turn == (PLAYER_AMOUNT - 1)) {
                semctl(sem_set_id, SEM_START, SETVAL, PLAYER_AMOUNT);
            } else {
                sem_post(&sem_id, *player_turn + 1);
            }
        }

        // Determining the game result
        int max_score = -1, winner = -1;
        printf("\n");
        printf("Game over! Scores:\n");
        for (i = 0; i < PLAYER_AMOUNT; i++) {
            printf("Player %d: %d\n", i, player_scores[i]);

            if (player_scores[i] > max_score) {
                max_score = player_scores[i];
                winner = i;
            }
        }

        printf("Winner of the round: Player %d with %d points\n", winner, max_score);

        // Cleanup variables and start a new round
        memset(shm, 0, SHM_SIZE);
        *player_turn = PLAYER_AMOUNT;
    }

    // Detach the shared memory segment
    if (shmdt(shm) == -1) {
        perror("Error in memory detachment");
        exit(1);
    }

    return 0;
}