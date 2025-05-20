//FormAI DATASET v1.0 Category: Memory management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_PLAYERS 10
#define MAX_ROUND 5

typedef struct {
    int player_id;
    int points;
} player_t;

player_t* players[MAX_PLAYERS];
pthread_t threads[MAX_PLAYERS];
pthread_mutex_t lock;

int active_players = 0;

void* play_game(void* arg){
    player_t* player = (player_t*) arg;
    int i, round_score;
    for(i = 0; i < MAX_ROUND; i++){
        round_score = (rand() % 20) + 1;
        pthread_mutex_lock(&lock);
        player->points += round_score;
        printf("Player %d scored %d in round %d\n", player->player_id, round_score, i+1);
        printf("Player %d's total score: %d\n", player->player_id, player->points);
        pthread_mutex_unlock(&lock);
        sleep(1); // simulate processing time
    }
    active_players--;
    pthread_exit(NULL);
}

int main(){
    int i;
    srand(time(NULL)); // initialize random seed
    pthread_mutex_init(&lock, NULL); // initialize mutex

    // create players
    for(i = 0; i < MAX_PLAYERS; i++){
        players[i] = (player_t*) malloc(sizeof(player_t));
        players[i]->player_id = i+1;
        players[i]->points = 0;
    }

    // start game
    printf("Game starting with %d players\n", MAX_PLAYERS);
    active_players = MAX_PLAYERS;

    for(i = 0; i < MAX_PLAYERS; i++){
        pthread_create(&threads[i], NULL, play_game, (void*) players[i]);
        sleep(1); // delay to prevent race conditions
    }

    // wait for all players to finish
    while(active_players > 0){
        sleep(1);
    }

    // display final scores
    printf("Game finished!\n");
    for(i = 0; i < MAX_PLAYERS; i++){
        printf("Player %d score: %d\n", players[i]->player_id, players[i]->points);
        free(players[i]); // free memory allocated to players
    }

    pthread_mutex_destroy(&lock); // free mutex
    return 0;
}