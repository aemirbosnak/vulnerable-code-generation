//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

// Dark and stormy incantation to create an ethereal checkers board.
void create_board(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Odd rows are filled with nothingness (0) or dream weavers (X).
            if ((i + j) % 2 == 0) {
                board[i][j] = ' ';
            } else {
                board[i][j] = (i < 3) ? 'X' : (i > 4) ? 'O' : ' ';
            }
        }
    }
}

// The board, a tapestry of fate, is revealed to the players.
void print_board(char board[SIZE][SIZE]) {
    printf("  a b c d e f g h\n");
    printf(" +-----------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d|", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n +-----------------\n");
    }
}

// A whimsical leap across the void, transforming coordinates to their companions.
int move_piece(char board[SIZE][SIZE], int x1, int y1, int x2, int y2, char player) {
    if (board[x1][y1] == player && board[x2][y2] == ' ' &&
        ((x2 == x1 + 1 && (y2 == y1 + 1 || y2 == y1 - 1)) || (x2 == x1 - 1 && (y2 == y1 + 1 || y2 == y1 - 1)))) {
        board[x2][y2] = player;
        board[x1][y1] = ' ';
        return 1; // The leap is successful!
    }
    return 0; // The leap is thwarted!
}

// A curious check for daring players, who walks the line of capturing fate.
int can_capture(char board[SIZE][SIZE], int x, int y, char player) {
    int direction[] = {-1, 1};
    for (int i = 0; i < 2; i++) {
        for (int j = -1; j <= 1; j += 2) {
            if (x + direction[i] >= 0 && x + direction[i] < SIZE && 
                y + j >= 0 && y + j < SIZE && 
                board[x + direction[i]][y + j] != player && 
                board[x + direction[i]][y + j] != ' ' &&
                x + 2 * direction[i] >= 0 && x + 2 * direction[i] < SIZE && 
                y + 2 * j >= 0 && y + 2 * j < SIZE && 
                board[x + 2 * direction[i]][y + 2 * j] == ' ') {
                return 1; // The dance of capturing is underway!
            }
        }
    }
    return 0; // The capture vanishes into the ether!
}

// The ancient oracle that asks the players for their next move.
void player_turn(char board[SIZE][SIZE], char player) {
    char column;
    int row;
    printf("Player %c, cast your move: ", player);
    scanf(" %c%d", &column, &row);
    int x1 = row - 1;
    int y1 = column - 'a';
    
    printf("Now, where shall your stars collide? ");
    scanf(" %c%d", &column, &row);
    int x2 = row - 1;
    int y2 = column - 'a';

    if (!move_piece(board, x1, y1, x2, y2, player)) {
        printf("The move is lost in the void!\n");
    } else {
        printf("The stars align...\n");
    }
}

int main() {
    char board[SIZE][SIZE];
    create_board(board);
    char player = 'X';

    while (1) {
        print_board(board);
        player_turn(board, player);
        
        // Surreal twist of fate: toggle players, as asleep as dreams.
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0; // The curtain falls!
}