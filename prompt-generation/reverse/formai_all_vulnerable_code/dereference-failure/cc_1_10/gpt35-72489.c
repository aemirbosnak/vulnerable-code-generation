//FormAI DATASET v1.0 Category: Memory management ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Structure to hold player information
typedef struct {
    int id;
    int score;
} Player;

// Function to dynamically create an array of players
Player* create_players(int num_players) {
    Player* players = (Player*) malloc(num_players * sizeof(Player));
    for(int i=0; i<num_players; i++) {
        players[i].id = i+1;
        players[i].score = 0;
    }
    return players;
}

// Function to display the scores of all players
void display_scores(Player* players, int num_players) {
    printf("\nPlayer Scores:\n");
    for(int i=0; i<num_players; i++) {
        printf("Player %d: %d\n", players[i].id, players[i].score);
    }
}

// Function to simulate a game round for a single player
int play_game(Player* player) {
    int score = rand() % 100;
    player->score += score;
    printf("Player %d scored %d points!\n", player->id, score);
    return score;
}

// Function to simulate a round for all players
void play_round(Player* players, int num_players) {
    printf("\nPlaying Round:\n");
    for(int i=0; i<num_players; i++) {
        play_game(&players[i]);
    }
}

int main() {
    srand(time(NULL));
    int num_players = 4;
    Player* players = create_players(num_players);

    int num_rounds = 3;
    for(int i=0; i<num_rounds; i++) {
        printf("\nRound %d\n", i+1);
        play_round(players, num_players);
        display_scores(players, num_players);
    }

    free(players);
    return 0;
}