//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of players
#define MAX_PLAYERS 10

// Define the structure of a player
typedef struct {
    char name[20];
    int rating;
} Player;

// Define the structure of the game
typedef struct {
    Player players[MAX_PLAYERS];
    int num_players;
} Game;

// Create a new game
Game *create_game() {
    Game *game = malloc(sizeof(Game));
    game->num_players = 0;
    return game;
}

// Add a player to the game
void add_player(Game *game, Player player) {
    game->players[game->num_players] = player;
    game->num_players++;
}

// Get the rating of a player
int get_rating(Game *game, char *name) {
    for (int i = 0; i < game->num_players; i++) {
        if (strcmp(game->players[i].name, name) == 0) {
            return game->players[i].rating;
        }
    }
    return -1;
}

// Set the rating of a player
void set_rating(Game *game, char *name, int rating) {
    for (int i = 0; i < game->num_players; i++) {
        if (strcmp(game->players[i].name, name) == 0) {
            game->players[i].rating = rating;
        }
    }
}

// Print the game
void print_game(Game *game) {
    printf("Players:\n");
    for (int i = 0; i < game->num_players; i++) {
        printf("%s: %d\n", game->players[i].name, game->players[i].rating);
    }
}

// Main function
int main() {
    // Create a new game
    Game *game = create_game();

    // Add some players to the game
    Player player1 = {"John", 1500};
    add_player(game, player1);
    Player player2 = {"Jane", 1200};
    add_player(game, player2);
    Player player3 = {"Bob", 1000};
    add_player(game, player3);

    // Print the game
    print_game(game);

    // Get the rating of a player
    int rating = get_rating(game, "John");
    printf("John's rating is: %d\n", rating);

    // Set the rating of a player
    set_rating(game, "John", 1600);

    // Print the game
    print_game(game);

    return 0;
}