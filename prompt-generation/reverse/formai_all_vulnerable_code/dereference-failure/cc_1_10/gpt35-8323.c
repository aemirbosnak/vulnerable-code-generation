//FormAI DATASET v1.0 Category: Chess AI ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Constants
#define BOARD_SIZE 8
#define MAX_NAME_LENGTH 20
#define MAX_MOVE_LENGTH 6

// Structs
typedef struct {
    int row;
    int col;
} Coordinate;

typedef struct {
    Coordinate position;
    char name[MAX_NAME_LENGTH];
    char color;
} Piece;

// Function declarations
void print_board(Piece board[][BOARD_SIZE]);
void initialize_board(Piece board[][BOARD_SIZE]);
void print_piece(Piece piece);
void move_piece(Piece board[][BOARD_SIZE], Coordinate start, Coordinate end);
void get_user_input(Coordinate *start, Coordinate *end);

int main() {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    print_board(board);

    Coordinate start, end;
    get_user_input(&start, &end);
    move_piece(board, start, end);
    print_board(board);

    return 0;
}

void print_board(Piece board[][BOARD_SIZE]) {
    printf("     A    B    C    D    E    F    G    H\n");
    printf("   +----+----+----+----+----+----+----+----+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d |", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].name[0] == '\0') {
                printf("    |");
            } else {
                print_piece(board[i][j]);
            }
        }
        printf(" %d\n   +----+----+----+----+----+----+----+----+\n", i + 1);
    }
    printf("     A    B    C    D    E    F    G    H\n");
}

void initialize_board(Piece board[][BOARD_SIZE]) {
    // Initialize pawns
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i].position.row = 1;
        board[1][i].position.col = i;
        board[1][i].name[0] = 'P';
        board[1][i].name[1] = '\0';
        board[1][i].color = 'B';

        board[6][i].position.row = 6;
        board[6][i].position.col = i;
        board[6][i].name[0] = 'P';
        board[6][i].name[1] = '\0';
        board[6][i].color = 'W';
    }

    // Initialize major pieces
    board[0][0].position.row = 0;
    board[0][0].position.col = 0;
    board[0][0].name[0] = 'R';
    board[0][0].name[1] = '\0';
    board[0][0].color = 'B';

    board[0][7].position.row = 0;
    board[0][7].position.col = 7;
    board[0][7].name[0] = 'R';
    board[0][7].name[1] = '\0';
    board[0][7].color = 'B';

    board[7][0].position.row = 7;
    board[7][0].position.col = 0;
    board[7][0].name[0] = 'R';
    board[7][0].name[1] = '\0';
    board[7][0].color = 'W';

    board[7][7].position.row = 7;
    board[7][7].position.col = 7;
    board[7][7].name[0] = 'R';
    board[7][7].name[1] = '\0';
    board[7][7].color = 'W';
}

void print_piece(Piece piece) {
    printf(" %c%c |", piece.name[0], piece.color);
}

void move_piece(Piece board[][BOARD_SIZE], Coordinate start, Coordinate end) {
    Piece temp = board[start.row][start.col];
    board[start.row][start.col].name[0] = '\0';
    board[end.row][end.col] = temp;
}

void get_user_input(Coordinate *start, Coordinate *end) {
    char move[MAX_MOVE_LENGTH];
    printf("Enter move (ex: a2 a4): ");
    fgets(move, MAX_MOVE_LENGTH, stdin);

    start->col = move[0] - 'a';
    start->row = atoi(&move[1]) - 1;
    end->col = move[3] - 'a';
    end->row = atoi(&move[4]) - 1;
}