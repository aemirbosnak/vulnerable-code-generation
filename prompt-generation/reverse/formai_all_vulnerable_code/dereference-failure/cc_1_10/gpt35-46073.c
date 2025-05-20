//FormAI DATASET v1.0 Category: Memory Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void printBoard(int** board, int rows, int cols);
void shuffle(int* arr, int size);

int main() {
    int row, col;
    int* nums;
    int** board;

    // Allocate memory for the board
    board = (int**) malloc(ROWS * sizeof(int*));
    for (row = 0; row < ROWS; row++) {
        board[row] = (int*) malloc(COLS * sizeof(int));
    }

    // Allocate memory for the nums array
    nums = (int*) malloc((ROWS*COLS/2) * sizeof(int));
    for (int i = 0; i < ROWS*COLS/2; i++) {
        nums[i] = i+1;
    }

    // Shuffle the nums array
    srand(time(NULL));
    shuffle(nums, ROWS*COLS/2);

    // Place the numbers onto the board
    int index = 0;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            board[row][col] = nums[index];
            index++;
        }
    }

    // Print the initial board
    printBoard(board, ROWS, COLS);

    // Game loop
    int firstRow, firstCol, secondRow, secondCol;
    int isFirst = 1;
    int count = 0;
    int found[ROWS*COLS/2] = {0};
    while (count < ROWS*COLS/2) {
        printf("Enter a row and column to reveal a number: ");
        scanf("%d %d", &row, &col);
        if (row < 1 || row > ROWS || col < 1 || col > COLS) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        if (found[board[row-1][col-1]-1]) {
            printf("That number has already been matched. Try again.\n");
            continue;
        }
        if (isFirst) {
            firstRow = row-1;
            firstCol = col-1;
            printf("Enter a row and column to reveal another number: ");
            scanf("%d %d", &row, &col);
            if (row < 1 || row > ROWS || col < 1 || col > COLS) {
                printf("Invalid input. Try again.\n");
                continue;
            }
            if (found[board[row-1][col-1]-1]) {
                printf("That number has already been matched. Try again.\n");
                continue;
            }
            secondRow = row-1;
            secondCol = col-1;
            isFirst = 0;
        } else {
            if (board[row-1][col-1] == board[firstRow][firstCol]) {
                found[board[firstRow][firstCol]-1] = 1;
                printf("You found a match!\n");
                count++;
            } else if (board[row-1][col-1] == board[secondRow][secondCol]) {
                found[board[secondRow][secondCol]-1] = 1;
                printf("You found a match!\n");
                count++;
            } else {
                printf("Sorry, no match.\n");
            }
            isFirst = 1;
        }
        board[firstRow][firstCol] = 0;
        board[secondRow][secondCol] = 0;
        printBoard(board, ROWS, COLS);
    }

    printf("Congratulations, you won!\n");

    // Free the memory
    free(nums);
    for (row = 0; row < ROWS; row++) {
        free(board[row]);
    }
    free(board);

    return 0;
}

void printBoard(int** board, int rows, int cols) {
    printf("+");
    for (int col = 0; col < cols; col++) {
        printf("---+");
    }
    printf("\n");
    for (int row = 0; row < rows; row++) {
        printf("|");
        for (int col = 0; col < cols; col++) {
            if (board[row][col] == 0) {
                printf("   |");
            } else {
                printf(" %d |", board[row][col]);
            }
        }
        printf("\n");
        printf("+");
        for (int col = 0; col < cols; col++) {
            printf("---+");
        }
        printf("\n");
    }
}

void shuffle(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}