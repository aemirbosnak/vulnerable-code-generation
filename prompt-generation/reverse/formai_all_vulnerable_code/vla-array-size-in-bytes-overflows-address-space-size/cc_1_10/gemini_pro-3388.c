//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <semaphore.h>

// Global variables
sem_t mutex;
int num_players;
int num_rounds;
int turn;
int scores[100];

// Function to simulate a player playing a round
void *player_round(void *arg) {
    int player_id = (int) arg;

    // Acquire the lock
    sem_wait(&mutex);

    // Check if it's the player's turn
    if (player_id == turn) {
        // Increment the player's score
        scores[player_id]++;

        // Advance the turn
        turn = (turn + 1) % num_players;
    }

    // Release the lock
    sem_post(&mutex);

    return NULL;
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Get the number of players and rounds from the user
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    printf("Enter the number of rounds: ");
    scanf("%d", &num_rounds);

    // Create the semaphore
    sem_init(&mutex, 0, 1);

    // Create the player threads
    pthread_t players[num_players];
    for (int i = 0; i < num_players; i++) {
        pthread_create(&players[i], NULL, player_round, (void *) i);
    }

    // Join the player threads
    for (int i = 0; i < num_players; i++) {
        pthread_join(players[i], NULL);
    }

    // Destroy the semaphore
    sem_destroy(&mutex);

    // Print the player scores
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: %d\n", i, scores[i]);
    }

    return 0;
}