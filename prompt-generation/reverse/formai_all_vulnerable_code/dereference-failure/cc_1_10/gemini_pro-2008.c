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
Game* new_game() {
    Game* game = malloc(sizeof(Game));
    game->num_players = 0;
    return game;
}

// Add a player to the game
void add_player(Game* game, char* name, int rating) {
    if (game->num_players < MAX_PLAYERS) {
        strcpy(game->players[game->num_players].name, name);
        game->players[game->num_players].rating = rating;
        game->num_players++;
    }
}

// Get the average rating of the players in the game
int get_average_rating(Game* game) {
    int sum_rating = 0;
    for (int i = 0; i < game->num_players; i++) {
        sum_rating += game->players[i].rating;
    }
    return sum_rating / game->num_players;
}

// Get the player with the highest rating in the game
Player* get_highest_rated_player(Game* game) {
    Player* highest_rated_player = NULL;
    int highest_rating = -1;
    for (int i = 0; i < game->num_players; i++) {
        if (game->players[i].rating > highest_rating) {
            highest_rating = game->players[i].rating;
            highest_rated_player = &game->players[i];
        }
    }
    return highest_rated_player;
}

// Get the player with the lowest rating in the game
Player* get_lowest_rated_player(Game* game) {
    Player* lowest_rated_player = NULL;
    int lowest_rating = 101;
    for (int i = 0; i < game->num_players; i++) {
        if (game->players[i].rating < lowest_rating) {
            lowest_rating = game->players[i].rating;
            lowest_rated_player = &game->players[i];
        }
    }
    return lowest_rated_player;
}

// Print the game summary
void print_game_summary(Game* game) {
    printf("Game Summary\n");
    printf("Number of players: %d\n", game->num_players);
    printf("Average rating: %d\n", get_average_rating(game));
    printf("Highest rated player: %s (%d)\n", get_highest_rated_player(game)->name, get_highest_rated_player(game)->rating);
    printf("Lowest rated player: %s (%d)\n", get_lowest_rated_player(game)->name, get_lowest_rated_player(game)->rating);
}

// Free the game memory
void free_game(Game* game) {
    free(game);
}

// Main function
int main() {
    // Create a new game
    Game* game = new_game();

    // Add some players to the game
    add_player(game, "John", 100);
    add_player(game, "Mary", 90);
    add_player(game, "Bob", 80);
    add_player(game, "Alice", 70);

    // Print the game summary
    print_game_summary(game);

    // Free the game memory
    free_game(game);

    return 0;
}