//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

// Player data structure
typedef struct player {
    int id;
    char name[32];
    int score;
} player_t;

// Shared memory segment
player_t *players;

// Semaphore to protect shared memory
sem_t players_lock;

// Thread function
void *player_thread(void *arg) {
    int id = *(int *)arg;
    char name[32];
    int score = 0;

    // Initialize player data
    sprintf(name, "Player %d", id);
    score = rand() % 100;

    // Acquire lock on shared memory
    sem_wait(&players_lock);

    // Update shared memory
    players[id].id = id;
    strcpy(players[id].name, name);
    players[id].score = score;

    // Release lock on shared memory
    sem_post(&players_lock);

    return NULL;
}

int main() {
    // Initialize shared memory
    players = (player_t *)malloc(sizeof(player_t) * 4);

    // Initialize semaphore
    sem_init(&players_lock, 0, 1);

    // Create player threads
    pthread_t threads[4];
    int ids[4] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, player_thread, &ids[i]);
    }

    // Join player threads
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print player data
    for (int i = 0; i < 4; i++) {
        printf("Player %d: %s (%d)\n", players[i].id, players[i].name, players[i].score);
    }

    // Cleanup
    sem_destroy(&players_lock);
    free(players);

    return 0;
}