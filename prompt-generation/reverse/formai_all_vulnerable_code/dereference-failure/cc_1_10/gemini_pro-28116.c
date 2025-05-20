//GEMINI-pro DATASET v1.0 Category: Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

struct player {
    char *name;
    int score;
};

struct game {
    struct player *players;
    int num_players;
    int current_player;
    int round;
};

struct game *create_game(int num_players) {
    struct game *game = malloc(sizeof(struct game));
    game->num_players = num_players;
    game->players = malloc(sizeof(struct player) * num_players);
    for (int i = 0; i < num_players; i++) {
        game->players[i].name = NULL;
        game->players[i].score = 0;
    }
    game->current_player = 0;
    game->round = 1;
    return game;
}

void free_game(struct game *game) {
    for (int i = 0; i < game->num_players; i++) {
        free(game->players[i].name);
    }
    free(game->players);
    free(game);
}

void add_player(struct game *game, char *name) {
    game->players[game->num_players].name = strdup(name);
    game->num_players++;
}

void start_game(struct game *game) {
    while (1) {
        // Get the current player's input
        char input[100];
        printf("%s's turn: ", game->players[game->current_player].name);
        scanf("%s", input);

        // Check if the player entered a valid move
        if (strcmp(input, "rock") == 0 || strcmp(input, "paper") == 0 || strcmp(input, "scissors") == 0) {
            // Process the player's move
            int player_move;
            if (strcmp(input, "rock") == 0) {
                player_move = 0;
            } else if (strcmp(input, "paper") == 0) {
                player_move = 1;
            } else {
                player_move = 2;
            }

            // Get the next player's move
            int next_player_move;
            int next_player = (game->current_player + 1) % game->num_players;
            printf("%s's turn: ", game->players[next_player].name);
            scanf("%s", input);
            if (strcmp(input, "rock") == 0) {
                next_player_move = 0;
            } else if (strcmp(input, "paper") == 0) {
                next_player_move = 1;
            } else {
                next_player_move = 2;
            }

            // Determine the winner of the round
            int winner = (player_move - next_player_move + 3) % 3;
            if (winner == 0) {
                printf("Tie!\n");
            } else if (winner == 1) {
                printf("%s wins!\n", game->players[game->current_player].name);
                game->players[game->current_player].score++;
            } else {
                printf("%s wins!\n", game->players[next_player].name);
                game->players[next_player].score++;
            }

            // Advance to the next round
            game->current_player = next_player;
            game->round++;
        } else {
            printf("Invalid move. Please enter rock, paper, or scissors.\n");
        }

        // Check if the game is over
        int winning_score = game->num_players / 2 + 1;
        for (int i = 0; i < game->num_players; i++) {
            if (game->players[i].score >= winning_score) {
                printf("%s wins the game!\n", game->players[i].name);
                return;
            }
        }
    }
}

int main() {
    // Create a new game
    struct game *game = create_game(2);

    // Add players to the game
    add_player(game, "Player 1");
    add_player(game, "Player 2");

    // Start the game
    start_game(game);

    // Free the game
    free_game(game);

    return 0;
}