//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MIN_PLAYERS 2
#define MAX_PLAYERS 8

int num_players = 0;

pthread_mutex_t lock;

void* play_game(void *arg) {
    int player_num = *((int*)arg);
    printf("Player %d joined the game!\n", player_num);
    
    pthread_mutex_lock(&lock);
    num_players++;
    pthread_mutex_unlock(&lock);
    
    // Play game logic here
    
    printf("Player %d left the game!\n", player_num);
    
    pthread_mutex_lock(&lock);
    num_players--;
    pthread_mutex_unlock(&lock);
    
    pthread_exit(NULL);
}

int main(int argc, char** argv) {    
    if(argc < 2) {
        printf("Usage: ./multiplayer_game n (where n is number of players)\n");
        return -1;
    }
    
    int num_requested_players = atoi(argv[1]);
    if(num_requested_players < MIN_PLAYERS || num_requested_players > MAX_PLAYERS) {
        printf("Number of players should be between %d and %d.\n", MIN_PLAYERS, MAX_PLAYERS);
        return -1;
    }
    
    pthread_t* threads = (pthread_t*)malloc(num_requested_players * sizeof(pthread_t));    
    pthread_mutex_init(&lock, NULL);
    
    for(int i=0; i<num_requested_players; i++) {
        int* arg = (int*)malloc(sizeof(int));
        *arg = i+1;
        pthread_create(&threads[i], NULL, play_game, arg);
    }
    
    for(int i=0; i<num_requested_players; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("Game is over.\n");
    
    free(threads);
    pthread_mutex_destroy(&lock);
    
    return 0;
}