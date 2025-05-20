//FormAI DATASET v1.0 Category: Checkers Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum {EMPTY, RED, BLACK} piece_t;

typedef struct {
    piece_t **board;
    int turn;
    int red_pieces;
    int black_pieces;
} game_t;

typedef struct {
    int x;
    int y;
} move_t;

// Function to allocate memory for the board
piece_t **create_board() {
    piece_t **board = (piece_t**) malloc(sizeof(piece_t*) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (piece_t*) malloc(sizeof(piece_t) * BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
    return board;
}

// Function to initialize the board with pieces
void initialize_board(game_t *game) {
    int mid = BOARD_SIZE / 2 - 1;

    for (int i = mid - 1; i >= 0; i--) {
        for (int j = (i+1) % 2; j < BOARD_SIZE; j += 2) {
            game->board[i][j] = RED;
            game->red_pieces++;
        }
    }

    for (int i = mid + 1; i < BOARD_SIZE; i++) {
        for (int j = (i+1) % 2; j < BOARD_SIZE; j += 2) {
            game->board[i][j] = BLACK;
            game->black_pieces++;
        }
    }
}

// Function to print the board
void print_board(game_t *game) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (game->board[i][j]) {
                case EMPTY:
                    printf("- ");
                    break;
                case RED:
                    printf("r ");
                    break;
                case BLACK:
                    printf("b ");
                    break;
            }
        }
        printf("\n");
    }
}

// Function to make a move
void make_move(game_t *game, move_t move) {
    int x = move.x;
    int y = move.y;
    int direction = game->board[x][y] == RED ? -1 : 1;

    // Check if capture is possible
    if ((x+2) < BOARD_SIZE && (y+2) < BOARD_SIZE && game->board[x+1][y+1]*direction < 0 && game->board[x+2][y+2] == EMPTY) {
        game->board[x+1][y+1] = EMPTY;
        game->board[x+2][y+2] = game->board[x][y];
        game->board[x][y] = EMPTY;
        if (game->board[x+2][y+2] == RED) {
            game->black_pieces--;
        } else {
            game->red_pieces--;
        }
    } else if ((x+2) < BOARD_SIZE && (y-2) >= 0 && game->board[x+1][y-1]*direction < 0 && game->board[x+2][y-2] == EMPTY) {
        game->board[x+1][y-1] = EMPTY;
        game->board[x+2][y-2] = game->board[x][y];
        game->board[x][y] = EMPTY;
        if (game->board[x+2][y-2] == RED) {
            game->black_pieces--;
        } else {
            game->red_pieces--;
        }
    } else if ((x-2) >= 0 && (y+2) < BOARD_SIZE && game->board[x-1][y+1]*direction < 0 && game->board[x-2][y+2] == EMPTY) {
        game->board[x-1][y+1] = EMPTY;
        game->board[x-2][y+2] = game->board[x][y];
        game->board[x][y] = EMPTY;
        if (game->board[x-2][y+2] == RED) {
            game->black_pieces--;
        } else {
            game->red_pieces--;
        }
    } else if ((x-2) >= 0 && (y-2) >= 0 && game->board[x-1][y-1]*direction < 0 && game->board[x-2][y-2] == EMPTY) {
        game->board[x-1][y-1] = EMPTY;
        game->board[x-2][y-2] = game->board[x][y];
        game->board[x][y] = EMPTY;
        if (game->board[x-2][y-2] == RED) {
            game->black_pieces--;
        } else {
            game->red_pieces--;
        }
    } else {
        // If no capture is possible, move to empty space
        game->board[x][y] = EMPTY;
        if ((x+direction) == 0 || (x+direction) == BOARD_SIZE) {
            // Turn into king if at other end of board
            game->board[x+direction][y] = game->board[x][y] + 2;
        } else {
            game->board[x+direction][y] = game->board[x][y];
        }
    }
}

// Function to check if a piece can capture
int can_capture(game_t *game, int x, int y) {
    int direction = game->board[x][y] == RED ? -1 : 1;

    if ((x+2) < BOARD_SIZE && (y+2) < BOARD_SIZE && game->board[x+1][y+1]*direction < 0 && game->board[x+2][y+2] == EMPTY) {
        return 1;
    } else if ((x+2) < BOARD_SIZE && (y-2) >= 0 && game->board[x+1][y-1]*direction < 0 && game->board[x+2][y-2] == EMPTY) {
        return 1;
    } else if ((x-2) >= 0 && (y+2) < BOARD_SIZE && game->board[x-1][y+1]*direction < 0 && game->board[x-2][y+2] == EMPTY) {
        return 1;
    } else if ((x-2) >= 0 && (y-2) >= 0 && game->board[x-1][y-1]*direction < 0 && game->board[x-2][y-2] == EMPTY) {
        return 1;
    }
    return 0;
}

// Function to check if the game is over
int game_over(game_t *game) {
    if (game->red_pieces == 0 || game->black_pieces == 0) {
        return 1;
    } else {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (game->board[i][j] != EMPTY && can_capture(game, i, j)) {
                    return 0;
                }
            }
        }
        return 1;
    }
}

// Function to get a valid move from the user
move_t get_move() {
	move_t move;
	printf("Enter x-coordinate of piece to move: ");
	scanf("%d", &move.x);
	printf("Enter y-coordinate of piece to move: ");
	scanf("%d", &move.y);
	return move;
}

// Main function
int main() {
	game_t game = {
        .board = create_board(),
        .turn = RED,
        .red_pieces = 0,
        .black_pieces = 0
    };

    initialize_board(&game);

    while (!game_over(&game)) {
        printf("\n");
        print_board(&game);
        printf("\n");
        move_t move = get_move();

        if (game.board[move.x][move.y] == game.turn) {
            make_move(&game, move);
            if (game.turn == RED) {
                game.turn = BLACK;
            } else {
                game.turn = RED;
            }
        } else {
            printf("Invalid move!\n");
        }
    }

    printf("\n");
    print_board(&game);

    if (game.red_pieces == 0) {
        printf("Black wins!");
    } else if (game.black_pieces == 0) {
        printf("Red wins!");
    } else {
        printf("Tie game!");
    }

    return 0;
}