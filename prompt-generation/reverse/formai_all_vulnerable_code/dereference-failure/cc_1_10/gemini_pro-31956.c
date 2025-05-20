//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum number of players
#define MAX_PLAYERS 4

// Define the maximum number of dice per player
#define MAX_DICE_PER_PLAYER 5

// Define the maximum number of sides per die
#define MAX_SIDES_PER_DIE 6

// Define the minimum number of sides per die
#define MIN_SIDES_PER_DIE 4

// Define the player struct
typedef struct {
    char name[20];
    int num_dice;
    int dice_sides[MAX_DICE_PER_PLAYER];
    int rolls[MAX_DICE_PER_PLAYER];
} player_t;

// Define the game struct
typedef struct {
    int num_players;
    player_t players[MAX_PLAYERS];
} game_t;

// Function to create a new game
game_t* create_game() {
    game_t* game = malloc(sizeof(game_t));
    game->num_players = 0;
    return game;
}

// Function to add a player to the game
void add_player(game_t* game, char* name, int num_dice, int* dice_sides) {
    strcpy(game->players[game->num_players].name, name);
    game->players[game->num_players].num_dice = num_dice;
    for (int i = 0; i < num_dice; i++) {
        game->players[game->num_players].dice_sides[i] = dice_sides[i];
    }
    game->num_players++;
}

// Function to roll the dice for a player
void roll_dice(player_t* player) {
    for (int i = 0; i < player->num_dice; i++) {
        player->rolls[i] = rand() % player->dice_sides[i] + 1;
    }
}

// Function to print the results of the game
void print_results(game_t* game) {
    for (int i = 0; i < game->num_players; i++) {
        printf("%s rolled:\n", game->players[i].name);
        for (int j = 0; j < game->players[i].num_dice; j++) {
            printf("%d ", game->players[i].rolls[j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new game
    game_t* game = create_game();

    // Add players to the game
    add_player(game, "Player 1", 2, (int[]){6, 6});
    add_player(game, "Player 2", 3, (int[]){4, 6, 8});
    add_player(game, "Player 3", 4, (int[]){4, 6, 8, 10});
    add_player(game, "Player 4", 5, (int[]){4, 6, 8, 10, 12});

    // Roll the dice for each player
    for (int i = 0; i < game->num_players; i++) {
        roll_dice(&game->players[i]);
    }

    // Print the results of the game
    print_results(game);

    return 0;
}