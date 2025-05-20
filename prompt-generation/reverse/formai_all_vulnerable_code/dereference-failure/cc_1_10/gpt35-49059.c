//FormAI DATASET v1.0 Category: Memory Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4 // Change this to increase or decrease board size
#define MAX_MOVES BOARD_SIZE * BOARD_SIZE * 2 // Maximum number of moves that can be made

void shuffle(int *arr, int size);
void populate_board(int **board, int *nums);
void print_board(int **board);
int get_num();
void swap(int *a, int *b);
int make_move(int **board, int *nums, int moves[]);
int check_win(int **board, int *nums);

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Dynamically allocate memory for the board
    int **board = (int **)malloc(sizeof(int *) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board[i] = (int *)malloc(sizeof(int) * BOARD_SIZE);
    }

    // Dynamically allocate memory for the number array
    int *nums = (int *)malloc(sizeof(int) * BOARD_SIZE * BOARD_SIZE);

    // Populate the number array with unique integers
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
    {
        nums[i] = i + 1;
    }

    // Shuffle the number array
    shuffle(nums, BOARD_SIZE * BOARD_SIZE);

    // Populate the board with the shuffled numbers
    populate_board(board, nums);

    // Print the initial board
    printf("Memory Game! You have %d moves to match all the numbers.\n\n", MAX_MOVES);
    print_board(board);

    // Start the game loop
    int moves[MAX_MOVES] = {0};
    int num_moves = 0;
    while (num_moves < MAX_MOVES && !check_win(board, nums))
    {
        // Get the user's move
        int move = make_move(board, nums, moves);
        if (move != -1)
        {
            moves[num_moves] = move;
            num_moves++;

            // Print the board after the move
            printf("\n");
            print_board(board);
        }
        else
        {
            printf("Invalid move, try again.\n\n");
        }
    }

    // Check if the player won or lost
    if (num_moves == MAX_MOVES)
    {
        printf("Sorry, you ran out of moves!\n");
    }
    else
    {
        printf("Congratulations, you won in %d moves!\n", num_moves);
    }

    // Free the allocated memory
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);
    free(nums);

    return 0;
}

// Shuffles the given array using the Fisher-Yates shuffle algorithm
void shuffle(int *arr, int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

// Populates the board with the given numbers
void populate_board(int **board, int *nums)
{
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = nums[index];
            index++;
        }
    }
}

// Prints the current board state
void print_board(int **board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%3d", board[i][j]);
        }
        printf("\n");
    }
}

// Gets the user's move and returns the index of the selected number or -1 if the move is invalid
int make_move(int **board, int *nums, int moves[])
{
    int row1, col1, row2, col2;

    printf("Enter the row and column of the first number: ");
    scanf("%d %d", &row1, &col1);

    // Check if the selected cell is already matched or out of bounds
    int index1 = (row1 - 1) * BOARD_SIZE + (col1 - 1);
    if (moves[index1] || row1 < 1 || row1 > BOARD_SIZE || col1 < 1 || col1 > BOARD_SIZE)
    {
        return -1;
    }

    printf("Enter the row and column of the second number: ");
    scanf("%d %d", &row2, &col2);

    // Check if the second selected cell is already matched or out of bounds
    int index2 = (row2 - 1) * BOARD_SIZE + (col2 - 1);
    if (moves[index2] || row2 < 1 || row2 > BOARD_SIZE || col2 < 1 || col2 > BOARD_SIZE)
    {
        return -1;
    }

    // Check if the two selected cells contain the same number
    if (board[row1 - 1][col1 - 1] != board[row2 - 1][col2 - 1])
    {
        return -1;
    }

    // Mark the two selected cells as matched
    moves[index1] = 1;
    moves[index2] = 1;

    // Return the indices of the selected cells
    return index1;
}

// Checks if the player has won the game
int check_win(int **board, int *nums)
{
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
    {
        if (!board[i / BOARD_SIZE][i % BOARD_SIZE])
        {
            return 0;
        }

        if (board[i / BOARD_SIZE][i % BOARD_SIZE] != nums[i])
        {
            return 0;
        }
    }
    return 1;
}

// Swaps the values of two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}