//FormAI DATASET v1.0 Category: Table Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_PLAYERS 6

int num_players = 0;
int current_turn = 0;
int* player_scores;

void* play_game(void* arg) {
    int player_num = *(int*)arg;
    printf("Player %d: Joined the game!\n", player_num);

    while(1) {
        if(current_turn == player_num) {
            // Player's turn
            printf("Player %d: It's my turn!\n", player_num);

            // Simulate dice roll
            int dice_roll = rand() % 6 + 1;

            // Update player's score
            player_scores[player_num] += dice_roll;

            printf("Player %d: Rolled a %d! Current score: %d\n", player_num, dice_roll, player_scores[player_num]);

            // Check if player has won
            if(player_scores[player_num] >= 100) {
                printf("Player %d: WINS!\n", player_num);
                exit(0);
            }

            // Update current_turn for next player
            current_turn = (current_turn + 1) % num_players;
        }
    }
}

int main() {
    // Initialize player_scores
    player_scores = (int*)malloc(sizeof(int) * MAX_PLAYERS);
    for(int i=0; i<MAX_PLAYERS; i++) {
        player_scores[i] = 0;
    }

    // Get number of players
    printf("Enter number of players (2-6): ");
    scanf("%d", &num_players);

    // Error check for num_players
    if(num_players < 2 || num_players > 6) {
        printf("Invalid number of players. Must be between 2-6.\n");
        exit(1);
    }

    // Create threads for each player
    pthread_t threads[num_players];
    for(int i=0; i<num_players; i++) {
        pthread_create(&threads[i], NULL, play_game, &i);
    }

    // Wait for all threads to finish
    for(int i=0; i<num_players; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}