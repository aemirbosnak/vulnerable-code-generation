//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

// Number of players
#define NUM_PLAYERS 5

// Player struct
typedef struct player {
    char name[20];
    int score;
} Player;

// Shared memory for player data
Player* players;

// Mutex to protect shared memory
pthread_mutex_t mutex;

// Initialize players
void initPlayers() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        sprintf(players[i].name, "Player%d", i);
        players[i].score = 0;
    }
}

// Get a random score
int getRandomScore() {
    return rand() % 100;
}

// Player thread
void* playerThread(void* args) {
    int playerIndex = *(int*)args;
    while (1) {
        // Acquire mutex
        pthread_mutex_lock(&mutex);

        // Get a random score
        int score = getRandomScore();

        // Update player score
        players[playerIndex].score += score;

        // Print player score
        printf("%s: %d\n", players[playerIndex].name, players[playerIndex].score);

        // Release mutex
        pthread_mutex_unlock(&mutex);

        // Sleep for a random amount of time
        usleep(rand() % 100000);
    }
}

// Main function
int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Allocate shared memory for player data
    players = (Player*)malloc(sizeof(Player) * NUM_PLAYERS);

    // Initialize players
    initPlayers();

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create player threads
    pthread_t playerThreads[NUM_PLAYERS];
    int playerIndices[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        playerIndices[i] = i;
        pthread_create(&playerThreads[i], NULL, playerThread, &playerIndices[i]);
    }

    // Join player threads
    for (int i = 0; i < NUM_PLAYERS; i++) {
        pthread_join(playerThreads[i], NULL);
    }

    // Free shared memory
    free(players);

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}