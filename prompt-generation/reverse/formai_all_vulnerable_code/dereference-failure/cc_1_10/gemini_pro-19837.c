//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the bingo card
#define CARD_SIZE 5

// Define the number of rows and columns on the bingo card
#define ROWS 5
#define COLS 5

// Define the number of balls to draw
#define NUM_BALLS 75

// Define the maximum number of players
#define MAX_PLAYERS 10

// Define the bingo card type
typedef struct {
    int numbers[CARD_SIZE][CARD_SIZE];
    int marked[CARD_SIZE][CARD_SIZE];
} BingoCard;

// Define the player type
typedef struct {
    BingoCard card;
    int score;
} Player;

// Define the bingo game type
typedef struct {
    Player players[MAX_PLAYERS];
    int num_players;
    int balls[NUM_BALLS];
    int balls_drawn;
} BingoGame;

// Create a new bingo game
BingoGame *new_bingo_game() {
    BingoGame *game = malloc(sizeof(BingoGame));
    game->num_players = 0;
    game->balls_drawn = 0;
    for (int i = 0; i < NUM_BALLS; i++) {
        game->balls[i] = i + 1;
    }
    return game;
}

// Add a player to the game
void add_player(BingoGame *game, Player player) {
    game->players[game->num_players++] = player;
}

// Draw a ball from the bag
int draw_ball(BingoGame *game) {
    int ball_index = rand() % (NUM_BALLS - game->balls_drawn);
    int ball = game->balls[ball_index];
    game->balls[ball_index] = game->balls[NUM_BALLS - game->balls_drawn - 1];
    game->balls_drawn++;
    return ball;
}

// Mark a number on a player's card
void mark_number(Player *player, int number) {
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            if (player->card.numbers[i][j] == number) {
                player->card.marked[i][j] = 1;
            }
        }
    }
}

// Check if a player has won
int check_for_win(Player *player) {
    // Check for horizontal wins
    for (int i = 0; i < CARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < CARD_SIZE; j++) {
            count += player->card.marked[i][j];
        }
        if (count == CARD_SIZE) {
            return 1;
        }
    }

    // Check for vertical wins
    for (int j = 0; j < CARD_SIZE; j++) {
        int count = 0;
        for (int i = 0; i < CARD_SIZE; i++) {
            count += player->card.marked[i][j];
        }
        if (count == CARD_SIZE) {
            return 1;
        }
    }

    // Check for diagonal wins
    int count1 = 0;
    for (int i = 0; i < CARD_SIZE; i++) {
        count1 += player->card.marked[i][i];
    }
    if (count1 == CARD_SIZE) {
        return 1;
    }

    int count2 = 0;
    for (int i = 0; i < CARD_SIZE; i++) {
        count2 += player->card.marked[i][CARD_SIZE - i - 1];
    }
    if (count2 == CARD_SIZE) {
        return 1;
    }

    return 0;
}

// Print a bingo card
void print_card(BingoCard card) {
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            printf("%2d ", card.numbers[i][j]);
        }
        printf("\n");
    }
}

// Play a bingo game
void play_bingo(BingoGame *game) {
    // Draw balls until a player wins
    while (1) {
        // Draw a ball
        int ball = draw_ball(game);

        // Mark the ball on each player's card
        for (int i = 0; i < game->num_players; i++) {
            mark_number(&game->players[i], ball);
        }

        // Check if any players have won
        for (int i = 0; i < game->num_players; i++) {
            if (check_for_win(&game->players[i])) {
                // The player has won!
                printf("Player %d has won!\n", i + 1);
                return;
            }
        }
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new bingo game
    BingoGame *game = new_bingo_game();

    // Add some players to the game
    Player player1 = {
        .card = {
            .numbers = {
                {1, 2, 3, 4, 5},
                {6, 7, 8, 9, 10},
                {11, 12, 13, 14, 15},
                {16, 17, 18, 19, 20},
                {21, 22, 23, 24, 25},
            },
            .marked = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
            },
        },
        .score = 0,
    };
    add_player(game, player1);

    Player player2 = {
        .card = {
            .numbers = {
                {26, 27, 28, 29, 30},
                {31, 32, 33, 34, 35},
                {36, 37, 38, 39, 40},
                {41, 42, 43, 44, 45},
                {46, 47, 48, 49, 50},
            },
            .marked = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
            },
        },
        .score = 0,
    };
    add_player(game, player2);

    // Play the bingo game
    play_bingo(game);

    return 0;
}