//FormAI DATASET v1.0 Category: Memory Game ; Style: Ada Lovelace
/*
* C Memory Game implemented in the Ada Lovelace style
* By [Your Name Here]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4 // Size of the memory game board
#define MAX_ATTEMPTS 10 // Max number of attempts to match cards

void createBoard(int **board);
void shuffleBoard(int **board);
void printBoard(int **board, int hide);
int isValidInput(int row, int col);
int isMatch(int **board, int row1, int col1, int row2, int col2);
void revealCards(int **board, int row1, int col1, int row2, int col2);
void hideCards(int **board, int row1, int col1, int row2, int col2);

int main()
{
    srand(time(NULL)); // Initialize random number generator

    int **board; // 2D array representing the memory game board
    board = (int **)malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board[i] = (int *)malloc(BOARD_SIZE * sizeof(int));
    }

    createBoard(board); // Create the board with number pairs
    shuffleBoard(board); // Shuffle the order of the cards

    int attempts = 0;
    int row1, col1, row2, col2;
    int matchesFound = 0;

    printf("Welcome to C Memory Game\n");
    printf("You have %d attempts to match all the cards on the board\n", MAX_ATTEMPTS);
    printf("\n----------------------------------------------------\n");

    while (attempts < MAX_ATTEMPTS && matchesFound < (BOARD_SIZE * BOARD_SIZE) / 2)
    {
        printBoard(board, 1); // Print the board with cards hidden

        printf("\nPlease enter the coordinates of two cards to reveal (ex: 1 2): ");
        scanf("%d %d %d %d", &row1, &col1, &row2, &col2);

        if (!isValidInput(row1, col1) || !isValidInput(row2, col2))
        {
            printf("Invalid input\n");
            continue;
        }

        if (row1 == row2 && col1 == col2)
        {
            printf("Cards must be different\n");
            continue;
        }

        if (isMatch(board, row1, col1, row2, col2))
        {
            revealCards(board, row1, col1, row2, col2);
            matchesFound++;
            printf("Match found!\n");
        }
        else
        {
            hideCards(board, row1, col1, row2, col2);
            printf("No match found\n");
        }

        attempts++;
        printf("\n----------------------------------------------------\n");
    }

    if (matchesFound == (BOARD_SIZE * BOARD_SIZE) / 2)
    {
        printf("Congratulations, you have matched all the cards!");
    }
    else
    {
        printf("Sorry, you have run out of attempts. Please try again.");
    }

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}

// Create the board with number pairs
void createBoard(int **board)
{
    int count = 1;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = count / 2;
            count++;
        }
    }
}

// Shuffle the order of the cards
void shuffleBoard(int **board)
{
    int temp, row1, col1, row2, col2;
    for (int i = 0; i < 100; i++)
    {
        row1 = rand() % BOARD_SIZE;
        col1 = rand() % BOARD_SIZE;
        row2 = rand() % BOARD_SIZE;
        col2 = rand() % BOARD_SIZE;

        temp = board[row1][col1];
        board[row1][col1] = board[row2][col2];
        board[row2][col2] = temp;
    }
}

// Print the board with cards hidden or revealed based on hide parameter
void printBoard(int **board, int hide)
{
    printf("\n   ");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d |", i);
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (hide && board[i][j] >= 0)
            {
                printf("* ");
            }
            else
            {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

// Check if input coordinates are valid
int isValidInput(int row, int col)
{
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
    {
        return 0;
    }
    return 1;
}

// Check if two selected cards match
int isMatch(int **board, int row1, int col1, int row2, int col2)
{
    if (board[row1][col1] == board[row2][col2])
    {
        return 1;
    }
    return 0;
}

// Reveal two selected cards
void revealCards(int **board, int row1, int col1, int row2, int col2)
{
    board[row1][col1] = -1;
    board[row2][col2] = -1;
}

// Hide two selected cards
void hideCards(int **board, int row1, int col1, int row2, int col2)
{
    board[row1][col1] = board[row1][col1] >= 0 ? board[row1][col1] : -2;
    board[row2][col2] = board[row2][col2] >= 0 ? board[row2][col2] : -2;
}