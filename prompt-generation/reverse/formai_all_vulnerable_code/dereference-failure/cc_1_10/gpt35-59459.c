//FormAI DATASET v1.0 Category: Memory Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_ATTEMPTS 5

void displayBoard(int board[ROWS][COLS])
{
    printf("\n-------------\n");
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLS; j++) {
            printf(" %d |", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

void initializeBoard(int board[ROWS][COLS])
{
    int nums[ROWS*COLS/2];
    for (int i = 0; i < ROWS*COLS/2; i++) {
        nums[i] = i + 1;
    }
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int idx = rand() % (ROWS*COLS/2);
            board[i][j] = nums[idx];
            nums[idx] = nums[ROWS*COLS/2-1-idx];
            nums[ROWS*COLS/2-1-idx] = board[i][j];
        }
    }
}

void startGame(int board[ROWS][COLS])
{
    initializeBoard(board);
    int attempts = 0;
    int first_row, first_col, second_row, second_col;
    while (1) {
        displayBoard(board);
        printf("\nAttempt %d/%d\n", attempts+1, MAX_ATTEMPTS);
        printf("\nEnter the row and column of the first card: ");
        scanf("%d %d", &first_row, &first_col);
        printf("Enter the row and column of the second card: ");
        scanf("%d %d", &second_row, &second_col);
        attempts++;
        if (board[first_row][first_col] == board[second_row][second_col]) {
            printf("\nYou found a match!\n");
            board[first_row][first_col] = 0;
            board[second_row][second_col] = 0;
        } else {
            printf("\nSorry, the cards don't match.\n");
        }
        if (attempts == MAX_ATTEMPTS) {
            printf("\nGame over! You ran out of attempts.\n");
            displayBoard(board);
            break;
        }
        int found_all = 1;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] != 0) {
                    found_all = 0;
                    break;
                }
            }
            if (!found_all) {
                break;
            }
        }
        if (found_all) {
            printf("\nCongratulations, you found all matches in %d attempts!\n", attempts);
            displayBoard(board);
            break;
        }
    }
}

int main()
{
    int board[ROWS][COLS];
    printf("Welcome to the Memory Game!\n");
    printf("Find all the matching pairs in %d attempts.\n", MAX_ATTEMPTS);
    printf("The board has %d rows and %d columns.\n", ROWS, COLS);
    printf("\nInstructions:\n");
    printf("Enter the row and column of the first card and press enter.\n");
    printf("Enter the row and column of the second card and press enter.\n");
    printf("If the cards match, they will be removed from the board.\n");
    printf("If the cards don't match, you will lose an attempt.\n");
    printf("Good luck!\n\n");
    startGame(board);
    return 0;
}