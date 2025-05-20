//FormAI DATASET v1.0 Category: Memory Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_MOVES 20

void print_board(int board[ROWS][COLS], int hidden[ROWS][COLS], int moves);
void get_move(int board[ROWS][COLS], int hidden[ROWS][COLS], int moves);
void reveal_tiles(int board[ROWS][COLS], int hidden[ROWS][COLS], int row, int col);
int check_win(int hidden[ROWS][COLS]);

int main()
{
    // initialize the game board
    int board[ROWS][COLS] = {
        {1, 1, 2, 2},
        {3, 3, 4, 4},
        {5, 5, 6, 6},
        {7, 7, 8, 8}
    };
    
    // initialize the hidden board
    int hidden[ROWS][COLS] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    
    // seed the random number generator
    srand(time(NULL));
    
    // shuffle the board randomly
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int r = rand() % ROWS;
            int c = rand() % COLS;
            int temp = board[i][j];
            board[i][j] = board[r][c];
            board[r][c] = temp;
        }
    }
    
    // play the game
    int moves = 0;
    while (moves < MAX_MOVES && !check_win(hidden)) {
        print_board(board, hidden, moves);
        get_move(board, hidden, moves);
        moves++;
    }
    
    // print win/loss message
    if (check_win(hidden)) {
        printf("Congratulations, you win!\n");
    } else {
        printf("Sorry, you ran out of moves. Better luck next time!\n");
    }
    
    return 0;
}

void print_board(int board[ROWS][COLS], int hidden[ROWS][COLS], int moves)
{
    printf("Moves: %d\n", moves);
    printf("----------------------------\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (hidden[i][j]) {
                printf("| %d ", board[i][j]);
            } else {
                printf("|   ");
            }
        }
        printf("|\n");
        printf("----------------------------\n");
    }
}

void get_move(int board[ROWS][COLS], int hidden[ROWS][COLS], int moves)
{
    int row1;
    int col1;
    int row2;
    int col2;
    
    printf("Enter the row and column of the first tile: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter the row and column of the second tile: ");
    scanf("%d %d", &row2, &col2);
    
    reveal_tiles(board, hidden, row1, col1);
    reveal_tiles(board, hidden, row2, col2);
}

void reveal_tiles(int board[ROWS][COLS], int hidden[ROWS][COLS], int row, int col)
{
    hidden[row][col] = 1;
    
    if (hidden[row][col] && hidden[row][col] && board[row][col] == board[row][col]) {
        hidden[row][col] = 0;
        hidden[row][col] = 0;
    }
}

int check_win(int hidden[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (!hidden[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}