//FormAI DATASET v1.0 Category: Database querying ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a player
typedef struct {
    int id;
    char name[30];
    int score;
} Player;

// Define a struct to represent a game
typedef struct {
    int id;
    char name[30];
    int num_players;
} Game;

// Define functions to populate the database with initial data
Player* create_players(int num_players);
Game* create_games(int num_games);

// Define functions for querying the database
void print_player(Player* player);
void print_game(Game* game);
void print_player_scores(Player* players, int num_players);
void print_game_info(Game* game, Player* players, int num_players);

int main() {
    int num_players = 4;
    int num_games = 2;

    // Create initial database data
    Player* players = create_players(num_players);
    Game* games = create_games(num_games);

    // Query the database for information
    printf("Players:\n");
    for (int i = 0; i < num_players; i++) {
        print_player(&players[i]);
    }
    printf("\nGames:\n");
    for (int i = 0; i < num_games; i++) {
        print_game(&games[i]);
    }

    // Simulate gameplay and update player scores
    for (int i = 0; i < num_players; i++) {
        players[i].score += rand() % 10;
        players[i].score += rand() % 10;
    }

    // Print updated player scores
    printf("\nPlayer Scores:\n");
    print_player_scores(players, num_players);

    // Print game information
    printf("\nGame Information:\n");
    for (int i = 0; i < num_games; i++) {
        print_game_info(&games[i], players, num_players);
    }

    // Free memory allocated for players and games
    free(players);
    free(games);

    return 0;
}

// Define function to create initial player data
Player* create_players(int num_players) {
    Player* players = malloc(num_players * sizeof(Player));
    for (int i = 0; i < num_players; i++) {
        players[i].id = i+1;
        sprintf(players[i].name, "Player %d", i+1);
        players[i].score = 0;
    }
    return players;
}

// Define function to create initial game data
Game* create_games(int num_games) {
    Game* games = malloc(num_games * sizeof(Game));
    for (int i = 0; i < num_games; i++) {
        games[i].id = i+1;
        sprintf(games[i].name, "Game %d", i+1);
        games[i].num_players = 2;
    }
    return games;
}

// Define function to print player information
void print_player(Player* player) {
    printf("Player %d - Name: %s - Score: %d\n", player->id, player->name, player->score);
}

// Define function to print game information
void print_game(Game* game) {
    printf("Game %d - Name: %s - Num Players: %d\n", game->id, game->name, game->num_players);
}

// Define function to print player scores
void print_player_scores(Player* players, int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("%s - Score: %d\n", players[i].name, players[i].score);
    }
}

// Define function to print game information with player scores
void print_game_info(Game* game, Player* players, int num_players) {
    printf("%s:\n", game->name);
    for (int i = 0; i < num_players; i++) {
        printf("%s - Score: %d\n", players[i].name, players[i].score);
    }
}