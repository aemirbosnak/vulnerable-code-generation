//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define MAX_PLAYERS 5
#define TIME_PERIODS 5

const char* time_periods[TIME_PERIODS] = {
    "The Dinosaur Age: Meet T-Rex and Stegosaurus!",
    "Ancient Rome: Explore the Colosseum and meet gladiators!",
    "The Renaissance: Encounter artists like Leonardo da Vinci!",
    "The Wild West: Meet outlaws and cowboys!",
    "The Future: Experience flying cars and robots!"
};

typedef struct {
    int player_id;
    int time_period;
} Player;

pthread_mutex_t mutex;

void* time_travel(void* arg) {
    Player* player = (Player*)arg;
    pthread_mutex_lock(&mutex);
    
    printf("Player %d is traveling to: %s\n", player->player_id + 1, time_periods[player->time_period]);
    
    // Simulating time travel duration
    sleep(2);
    
    printf("Player %d has returned from: %s\n", player->player_id + 1, time_periods[player->time_period]);
    pthread_mutex_unlock(&mutex);
    
    free(player);
    return NULL;
}

int main() {
    pthread_t threads[MAX_PLAYERS];
    int player_count = 0;

    pthread_mutex_init(&mutex, NULL);
    
    while (player_count < MAX_PLAYERS) {
        Player* player = (Player*)malloc(sizeof(Player));
        player->player_id = player_count;
        player->time_period = rand() % TIME_PERIODS;  // Randomly choose a time period

        printf("Player %d is ready to time travel!\n", player_count + 1);
        
        pthread_create(&threads[player_count], NULL, time_travel, (void*)player);
        player_count++;

        // Simulating some delay before next player joins
        sleep(1);
    }
    
    // Wait for all threads to finish
    for (int i = 0; i < player_count; i++) {
        pthread_join(threads[i], NULL);
    }
    
    pthread_mutex_destroy(&mutex);
    
    printf("All players have finished their time travel adventures!\n");
    
    return 0;
}