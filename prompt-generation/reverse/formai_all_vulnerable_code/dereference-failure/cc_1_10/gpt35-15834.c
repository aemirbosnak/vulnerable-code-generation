//FormAI DATASET v1.0 Category: Memory Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void init_board(int board[][BOARD_SIZE]);
void display_board(int board[][BOARD_SIZE], int revealed[][BOARD_SIZE]);
void get_input(int *row1, int *col1, int *row2, int *col2);
void reveal_tile(int row, int col, int board[][BOARD_SIZE], int revealed[][BOARD_SIZE]);
int check_win(int revealed[][BOARD_SIZE]);

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    int revealed[BOARD_SIZE][BOARD_SIZE] = {0};
    int row1, col1, row2, col2, moves = 0;

    init_board(board);

    while (!check_win(revealed))
    {
        printf("Moves: %d\n", moves);
        display_board(board, revealed);
        get_input(&row1, &col1, &row2, &col2);
        reveal_tile(row1, col1, board, revealed);
        reveal_tile(row2, col2, board, revealed);
        if (board[row1][col1] != board[row2][col2])
        {
            printf("Not a match!\n");
            revealed[row1][col1] = 0;
            revealed[row2][col2] = 0;
        }
        moves++;
    }

    display_board(board, revealed);
    printf("Congratulations, you won in %d moves!\n", moves);

    return 0;
}

void init_board(int board[][BOARD_SIZE])
{
    int i, j, count = 0;
    int values[BOARD_SIZE*BOARD_SIZE/2];

    // Set up values for tiles
    for (i = 0; i < BOARD_SIZE*BOARD_SIZE/2; i++)
    {
        values[i] = count;
        count++;
        if (count == 10) // Only use digits 0-9
        {
            count = 0;
        }
    }

    // Shuffle values array
    srand(time(NULL));
    for (i = 0; i < BOARD_SIZE*BOARD_SIZE/2; i++)
    {
        int rand_index = rand() % (BOARD_SIZE*BOARD_SIZE/2);
        int temp = values[i];
        values[i] = values[rand_index];
        values[rand_index] = temp;
    }

    // Populate board array with shuffled values
    count = 0;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = values[count];
            count++;
        }
    }
}

void display_board(int board[][BOARD_SIZE], int revealed[][BOARD_SIZE])
{
    int i, j;

    printf("\n  ");
    for (j = 0; j < BOARD_SIZE; j++)
    {
        printf("| %d ", j);
    }
    printf("|\n");

    for (i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d ", i);
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (revealed[i][j])
            {
                printf("| %d ", board[i][j]);
            }
            else
            {
                printf("|   ");
            }
        }
        printf("|\n");
    }
}

void get_input(int *row1, int *col1, int *row2, int *col2)
{
    printf("Enter first tile row and column: ");
    scanf("%d %d", row1, col1);
    printf("Enter second tile row and column: ");
    scanf("%d %d", row2, col2);
}

void reveal_tile(int row, int col, int board[][BOARD_SIZE], int revealed[][BOARD_SIZE])
{
    revealed[row][col] = 1;
}

int check_win(int revealed[][BOARD_SIZE])
{
    int i, j, count = 0;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (revealed[i][j])
            {
                count++;
            }
        }
    }

    if (count == BOARD_SIZE*BOARD_SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}