//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_PLAYERS 4
#define TARGET_SCORE 20

typedef struct {
    int player_id;
    int score;
} Player;

Player players[NUM_PLAYERS];

void* roll_dice(void* arg) {
    int player_id = *(int*)arg;

    while (players[player_id].score < TARGET_SCORE) {
        int roll = (rand() % 6) + 1; // Roll a dice (1-6)
        players[player_id].score += roll;

        printf("Player %d rolled a %d! Total Score: %d\n", player_id + 1, roll, players[player_id].score);

        // Simulate some delay
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_PLAYERS];
    srand(time(NULL));

    // Initialize players
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].player_id = i;
        players[i].score = 0;
    }

    // Create a thread for each player to roll the dice
    for (int i = 0; i < NUM_PLAYERS; i++) {
        int* player_id = malloc(sizeof(int));
        *player_id = i;
        pthread_create(&threads[i], NULL, roll_dice, player_id);
    }

    // Wait for all players to finish
    for (int i = 0; i < NUM_PLAYERS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Find the winner
    int winner = -1;
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (players[i].score >= TARGET_SCORE) {
            winner = i;
            break;
        }
    }

    if (winner != -1) {
        printf("Player %d wins with a score of %d!\n", winner + 1, players[winner].score);
    } else {
        printf("No player reached the target score.\n");
    }

    return 0;
}