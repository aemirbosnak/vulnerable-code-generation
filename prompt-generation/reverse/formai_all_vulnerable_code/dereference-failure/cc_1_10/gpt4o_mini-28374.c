//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int turn; // 0 for White, 1 for Black
} GameState;

void initialize_board(GameState *game) {
    const char *initial_board[BOARD_SIZE] = {
        "rnbqkbnr",
        "pppppppp",
        "........",
        "........",
        "........",
        "........",
        "PPPPPPPP",
        "RNBQKBNR"
    };
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        strncpy(game->board[i], initial_board[i], BOARD_SIZE);
    }
    game->turn = 0; // White starts
}

void print_board(const GameState *game) {
    printf("\n");
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            printf("%c ", game->board[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

int is_valid_move(char piece, int sr, int sc, int dr, int dc) {
    int d_row = dr - sr;
    int d_col = dc - sc;
    
    // Logic for moving pieces would go here
    // Simplified here for demonstration:
    switch (piece) {
        case 'P':
            return d_row == -1 && d_col == 0; // White pawn move
        case 'p':
            return d_row == 1 && d_col == 0; // Black pawn move
        case 'R':
        case 'r':
            return (d_row == 0 || d_col == 0); // Rook moves
        case 'N':
        case 'n':
            return (abs(d_row) == 2 && abs(d_col) == 1) || (abs(d_row) == 1 && abs(d_col) == 2);
        case 'B':
        case 'b':
            return abs(d_row) == abs(d_col); // Bishop moves
        case 'Q':
        case 'q':
            return (abs(d_row) == abs(d_col)) || (d_row == 0 || d_col == 0); // Queen moves
        case 'K':
        case 'k':
            return (abs(d_row) <= 1 && abs(d_col) <= 1); // King moves
        default:
            return 0; // Invalid piece
    }
}

void move_piece(GameState *game, int sr, int sc, int dr, int dc) {
    char piece = game->board[sr][sc];
    if (is_valid_move(piece, sr, sc, dr, dc)) {
        game->board[dr][dc] = piece;
        game->board[sr][sc] = '.';
        game->turn = !game->turn; // Switch turn
    } else {
        printf("Invalid move!\n");
    }
}

void get_move(GameState *game) {
    char from[3], to[3];
    printf("Player %s, enter your move (e.g., e2 e4): ", game->turn == 0 ? "White" : "Black");
    scanf("%s %s", from, to);
    
    int sr = 8 - (from[1] - '0'); // Convert to array index (0-7)
    int sc = from[0] - 'a';       // Convert to array index (0-7)
    int dr = 8 - (to[1] - '0');   // Convert to array index (0-7)
    int dc = to[0] - 'a';         // Convert to array index (0-7)
    
    move_piece(game, sr, sc, dr, dc);
}

int main() {
    GameState game;
    initialize_board(&game);
    
    while (1) {
        print_board(&game);
        get_move(&game);
    }
    
    return 0;
}