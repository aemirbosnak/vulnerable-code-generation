//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BOARD_SIZE 8

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char** board;
    int turn;
} Game;

// Create a new game
Game* new_game() {
    Game* game = (Game*)malloc(sizeof(Game));
    game->board = (char**)malloc(BOARD_SIZE * sizeof(char*));
    for (int i = 0; i < BOARD_SIZE; i++) {
        game->board[i] = (char*)malloc(BOARD_SIZE * sizeof(char));
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                game->board[i][j] = ' ';
            } else if (i < 3) {
                game->board[i][j] = 'b';
            } else if (i > 4) {
                game->board[i][j] = 'w';
            } else {
                game->board[i][j] = ' ';
            }
        }
    }
    game->turn = 'b';
    return game;
}

// Free the memory allocated for the game
void free_game(Game* game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(game->board[i]);
    }
    free(game->board);
    free(game);
}

// Print the game board
void print_board(Game* game) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'a' + i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

// Get the player's move
Position get_move(Game* game, char player) {
    Position move;
    while (1) {
        printf("%c's move: ", player);
        char input[3];
        scanf("%s", input);
        if (strlen(input) != 2) {
            printf("Invalid move. Please enter a move in the format \"a1\".\n");
            continue;
        }
        move.x = input[0] - 'a';
        move.y = input[1] - '1';
        if (move.x < 0 || move.x >= BOARD_SIZE || move.y < 0 || move.y >= BOARD_SIZE) {
            printf("Invalid move. Please enter a move within the bounds of the board.\n");
            continue;
        }
        if (game->board[move.y][move.x] != player) {
            printf("Invalid move. Please enter a move that is your own piece.\n");
            continue;
        }
        break;
    }
    return move;
}

// Check if the game is over
int is_game_over(Game* game) {
    int black_count = 0;
    int white_count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == 'b') {
                black_count++;
            } else if (game->board[i][j] == 'w') {
                white_count++;
            }
        }
    }
    if (black_count == 0) {
        return 1;
    } else if (white_count == 0) {
        return 2;
    } else {
        return 0;
    }
}

// Play the game
void play_game() {
    Game* game = new_game();
    while (1) {
        print_board(game);
        Position move = get_move(game, game->turn);
        if (is_game_over(game) != 0) {
            break;
        }
        game->board[move.y][move.x] = toupper(game->board[move.y][move.x]);
        if (game->turn == 'b') {
            game->turn = 'w';
        } else {
            game->turn = 'b';
        }
    }
    print_board(game);
    if (is_game_over(game) == 1) {
        printf("Black wins!\n");
    } else {
        printf("White wins!\n");
    }
    free_game(game);
}

int main() {
    play_game();
    return 0;
}