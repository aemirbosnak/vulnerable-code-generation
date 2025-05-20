//FormAI DATASET v1.0 Category: Memory Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_ATTEMPTS 8

void initializeBoard(int board[ROWS][COLS]);
void printBoard(int board[ROWS][COLS], int attempts);
void checkMatch(int board[ROWS][COLS], int input1Row, int input1Col, int input2Row, int input2Col, int matched[ROWS][COLS], int *attemptsPtr);
int isGameOver(int matched[ROWS][COLS]);

int main()
{
    int board[ROWS][COLS], matched[ROWS][COLS] = {{0}};
    int input1Row, input1Col, input2Row, input2Col, attempts = 0;

    srand(time(NULL)); 
    initializeBoard(board);

    while (!isGameOver(matched))
    {
        printBoard(board, attempts);

        printf("Enter the first card row and column numbers: ");
        scanf("%d %d", &input1Row, &input1Col);

        printf("Enter the second card row and column numbers: ");
        scanf("%d %d", &input2Row, &input2Col);

        checkMatch(board, input1Row, input1Col, input2Row, input2Col, matched, &attempts);

        if (attempts >= MAX_ATTEMPTS) 
        {
            printf("\n*** You have reached the max attempts! Game Over! ***\n");
            break;
        }
    }
    return 0;
}

void initializeBoard(int board[ROWS][COLS])
{
    int i, j, num;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            num = rand() % 8 + 1;
            board[i][j] = num;
        }
    }
}

void printBoard(int board[ROWS][COLS], int attempts)
{
    int i, j;

    printf("\n--- MEMORY GAME ---\n");
    printf("Attempts: %d/%d\n", attempts, MAX_ATTEMPTS);

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] == 0)
            {
                printf("  ");
            }
            else if (board[i][j] < 10)
            {
                printf("%d ", board[i][j]);
            }
            else
            {
                printf("%d", board[i][j]);
            }
        }
        printf("\n");
    }
}

void checkMatch(int board[ROWS][COLS], int input1Row, int input1Col, int input2Row, int input2Col, int matched[ROWS][COLS], int *attemptsPtr)
{
    if (input1Row == input2Row && input1Col == input2Col) 
    {
        printf("\n*** Invalid input. Cards should not be the same! ***\n");
    }
    else if (board[input1Row][input1Col] == board[input2Row][input2Col])
    {
        printf("\n*** MATCH FOUND! ***\n\n");
        matched[input1Row][input1Col] = 1;
        matched[input2Row][input2Col] = 1;
    }
    else 
    {
        printf("\n*** No match. Please try again! ***\n\n");
        (*attemptsPtr)++;
    }
}

int isGameOver(int matched[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (matched[i][j] == 0)
            {
                return 0;
            }
        }
    }
    printf("\n*** Congratulations! You have completed the game! ***\n");
    return 1;
}