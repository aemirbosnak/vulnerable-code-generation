//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of players
#define MAX_PLAYERS 4

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
Game* create_game() {
    Game* game = malloc(sizeof(Game));
    game->num_players = 0;
    return game;
}

// Add a player to the game
void add_player(Game* game, Player* player) {
    if (game->num_players < MAX_PLAYERS) {
        game->players[game->num_players++] = *player;
    } else {
        printf("Cannot add more players to the game.\n");
    }
}

// Get the rating of a player
int get_rating(Game* game, char* name) {
    for (int i = 0; i < game->num_players; i++) {
        if (strcmp(game->players[i].name, name) == 0) {
            return game->players[i].rating;
        }
    }
    return -1;
}

// Set the rating of a player
void set_rating(Game* game, char* name, int rating) {
    for (int i = 0; i < game->num_players; i++) {
        if (strcmp(game->players[i].name, name) == 0) {
            game->players[i].rating = rating;
            return;
        }
    }
    printf("Cannot find player with name %s.\n", name);
}

// Print the ratings of all players
void print_ratings(Game* game) {
    for (int i = 0; i < game->num_players; i++) {
        printf("%s: %d\n", game->players[i].name, game->players[i].rating);
    }
}

// Main function
int main() {
    // Create a new game
    Game* game = create_game();

    // Add some players to the game
    Player player1 = {"Player 1", 1000};
    Player player2 = {"Player 2", 1200};
    Player player3 = {"Player 3", 1100};
    Player player4 = {"Player 4", 1300};
    add_player(game, &player1);
    add_player(game, &player2);
    add_player(game, &player3);
    add_player(game, &player4);

    // Print the ratings of all players
    print_ratings(game);

    // Get the rating of a player
    int rating = get_rating(game, "Player 2");
    printf("The rating of Player 2 is %d.\n", rating);

    // Set the rating of a player
    set_rating(game, "Player 2", 1250);

    // Print the ratings of all players
    print_ratings(game);

    // Free the memory allocated for the game
    free(game);

    return 0;
}