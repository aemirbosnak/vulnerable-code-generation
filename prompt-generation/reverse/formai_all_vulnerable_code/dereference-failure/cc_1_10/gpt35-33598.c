//FormAI DATASET v1.0 Category: Game of Life ; Style: paranoid
/* The Game of Life */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ROWS 20
#define COLS 20
#define ALIVE 'O'
#define DEAD '.'

// Function to create a new board
char** create_board()
{
    char** board = (char**)malloc(sizeof(char*) * ROWS);

    int i, j;
    for (i = 0; i < ROWS; i++) {
        board[i] = (char*)malloc(sizeof(char) * COLS);
        for (j = 0; j < COLS; j++) {
            board[i][j] = DEAD;
        }
    }

    return board;
}

// Function to print the board to the terminal
void print_board(char** board)
{
    int i, j;

    system("clear"); // Clear the terminal

    printf("    ");
    for (i = 0; i < COLS; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printf("   ");
    for (i = 0; i < COLS + 1; i++) {
        printf("--");
    }
    printf("\n");

    for (i = 0; i < ROWS; i++) {
        printf("%d | ", i);
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

// Function to count the number of live neighbors around a cell
int count_live_neighbors(char** board, int row, int col)
{
    int i, j;
    int count = 0;

    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (!(i == 0 && j == 0) && row + i >= 0 && row + i < ROWS &&
                col + j >= 0 && col + j < COLS &&
                board[row + i][col + j] == ALIVE) {
                count++;
            }
        }
    }

    return count;
}

// Function to update each cell on the board based on the Game of Life rules
void update_board(char** board)
{
    int i, j;
    char** temp = create_board();

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int live_neighbors = count_live_neighbors(board, i, j);

            if (board[i][j] == ALIVE) {
                if (live_neighbors < 2 || live_neighbors > 3) {
                    temp[i][j] = DEAD;
                } else {
                    temp[i][j] = ALIVE;
                }
            } else {
                if (live_neighbors == 3) {
                    temp[i][j] = ALIVE;
                } else {
                    temp[i][j] = DEAD;
                }
            }
        }
    }

    memcpy(board, temp, ROWS * COLS);
    free(temp);
}

// Function to randomize the board with a given percentage of live cells
void randomize_board(char** board, int percent)
{
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (rand() % 100 < percent) {
                board[i][j] = ALIVE;
            } else {
                board[i][j] = DEAD;
            }
        }
    }
}

int main()
{
    char** board = create_board();

    randomize_board(board, 50);
    print_board(board);

    while (1) {
        update_board(board);
        print_board(board);

        usleep(100000); // Sleep for 100 milliseconds
    }

    return 0;
}